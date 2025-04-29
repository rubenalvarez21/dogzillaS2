import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState, Imu
import DOGZILLALib as dog
import gym
from gym import spaces
import numpy as np
import time
import math

control = dog.DOGZILLA()

class env(gym.Env, Node):
	def __init__(self):
		gym.Env.__init__(self)
		Node.__init__(self, 'RL_env')
		self.dogControl = dog.DOGZILLA()

		num_joints = 12
		self.action_space = spaces.Box(low=np.array([np.deg2rad(-73), np.deg2rad(-66), np.deg2rad(-31)] * 4), high=np.array([np.deg2rad(57), np.deg2rad(93), np.deg2rad(31)] * 4), shape=(num_joints,), dtype=np.float64)

		num_states = 37
		self.observation_space = spaces.Box(low=-np.inf, high=np.inf, shape=(37,), dtype=np.float64)

		self.sub1 = self.create_subscription(JointState, "/joint_states", self.sub_callback1, 10)
		self.sub2 = self.create_subscription(Imu, "/imu/data_raw_self", self.sub_callback2, 10)
		self.sub1
		self.sub2

		self.prev_time = None
		self.curr_time = time.time()
		self.prev_accel = [0.0, 0.0, 0.0]
		self.velocity = [0.0, 0.0, 0.0]

		self.orientations = np.zeros(4, dtype=float)
		self.roll_threshold = 0.785
		self.pitch_threshold = 0.785
		self.roll = 0.0
		self.pitch = 0.0
		self.yaw = 0.0

		self.fallen = 0
		self.ang_velocities = np.zeros(3, dtype=float)
		self.lin_accelerations = np.zeros(3, dtype=float)
		self.body_accelerations = np.zeros(3, dtype=float)
		self.filtered_accelerations = np.zeros(3, dtype=float)
		self.accel_threshold = 0.05

		self.positions = np.zeros(12, dtype=float)
		self.velocities = np.zeros(12, dtype=float)
		self.max_steps = 300
		self.current_step = 0

		self.home = [0.19408061, 0.76,  0.01902409,  0.19408061, 0.76, 0.01902409, 0.1584759, 0.9265953, 0.01902409, 0.17627825, 0.90495322, 0.01064651]

	def sub_callback1(self, msg):
		self.velocities = np.array(msg.velocity)
		self.positions = np.array(msg.position)

	def sub_callback2(self, msg):

		self.curr_time = time.time()
		
		self.orientations = np.array([msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w])
		self.ang_velocities = np.array([msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z])
		self.body_accelerations = np.array([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z])

		t0 = 2.0*(self.orientations[3]*self.orientations[0] + self.orientations[1]*self.orientations[2])
		t1 = 1.0 - 2.0*(self.orientations[0]*self.orientations[0] + self.orientations[1]*self.orientations[1])
		self.roll = math.atan2(t0, t1)

		t2 = 2.0*(self.orientations[3]*self.orientations[1] - self.orientations[2]*self.orientations[0])
		t2 = max(min(t2, 1.0), -1.0)
		self.pitch = math.asin(t2)

		t3 = 2.0*(self.orientations[3]*self.orientations[2] + self.orientations[0]*self.orientations[1])
		t4 = 1.0 - 2.0*(self.orientations[1]*self.orientations[1] + self.orientations[2]*self.orientations[2])
		self.yaw = math.atan2(t3, t4)

		t = 2.0*np.cross(self.orientations[:3], self.body_accelerations)
		self.lin_accelerations = self.body_accelerations + self.orientations[3]*t + np.cross(self.orientations[:3], t)

		self.lin_accelerations -= [0, 0, -9.7]
		alpha = 0.15
		self.filtered_accelerations = alpha*self.lin_accelerations + (1 - alpha)*self.filtered_accelerations

		decay = .875

		if self.prev_time is not None:

			dt = self.curr_time - self.prev_time

			self.velocity = np.array(self.velocity)*.95 + 0.5*(self.filtered_accelerations + self.prev_accel)*dt

			self.prev_accel = self.filtered_accelerations

		self.prev_time = self.curr_time

		#if self.velocity[0] < -0.01:
			#self.velocity[0] = 0.0
		
		if np.allclose(self.velocities, 0.0, atol=1e-3):
			self.velocity = [0.0, 0.0, 0.0]

		check = abs(self.roll) > self.roll_threshold or abs(self.pitch) > self.pitch_threshold
		self.fallen = int(check)

	def get_state(self):

		roll = [self.roll]
		pitch = [self.pitch]
		yaw = [self.yaw]
		fallen = [self.fallen]
		self.positions[1] = -self.positions[1]
		self.positions[4] = -self.positions[4]
		self.positions[6] = -self.positions[6]
		self.positions[9] = -self.positions[9]
		self.velocities[1] = -self.velocities[1]
		self.velocities[4] = -self.velocities[4]
		self.velocities[6] = -self.velocities[6]
		self.velocities[9] = -self.velocities[9]
		
		state = np.concatenate((self.velocity, self.positions, self.velocities, roll, pitch, yaw, self.ang_velocities, self.lin_accelerations, fallen))
		return state

	def reset(self):

		self.move_robot(self.home)
		time.sleep(5)

		rclpy.spin_once(self, timeout_sec=0.05)

		#get initial state
		self.prev_time = None
		self.curr_time = time.time()
		self.prev_accel = [0.0, 0.0, 0.0]
		self.velocity = [0.0, 0.0, 0.0]
		self.orientations = np.zeros(4, dtype=float)
		self.roll = 0.0
		self.pitch = 0.0
		self.yaw = 0.0
		self.fallen = 0
		self.ang_velocities = np.zeros(3, dtype=float)
		self.lin_acclerations = np.zeros(3, dtype=float)
		self.body_accelerations = np.zeros(3, dtype=float)
		self.filtered_accelerations = np.zeros(3, dtype=float)
		self.velocities = np.zeros(12, dtype=float)

		self.current_step = 0

		return self.get_state()

	def step(self, action):
	
		self.current_step += 1
		
		start = time.time()	
			
		#send angles to robot
		clipped = np.clip(action, -1.0, 1.0)
		scaled_action = self.scale_action(clipped)
		self.move_robot(scaled_action)
		time.sleep(0.1)

		rclpy.spin_once(self, timeout_sec=0.05)
		observation = self.get_state()

		reward = self.compute_reward(observation, action)

		done = self.check_termination(observation)
		
		print(f"Velocity: {observation[0]}")
		print(f"Accelerations: {observation[33:36]}")

		return observation, reward, done, {}

	def compute_reward(self, observation, action):

		#reward forward velocity and penalize too much roll or pitch
		forward_vel = observation[0]
		tilt = abs(observation[27])+abs(observation[28])
		episode_length_bonus = .08

		leg_ang = 0
		if self.positions[1]<-0.7 or self.positions[4]<-0.7 or self.positions[7]<-0.7 or self.positions[10]<-0.7:
			leg_ang = -10

		#first reward try
		reward = forward_vel - tilt + episode_length_bonus + leg_ang

		return reward

	def scale_action(self, action):
	
		# Joint limits in radians
		joint_limits = [
		[np.deg2rad(-73), np.deg2rad(57)],
		[np.deg2rad(-66), np.deg2rad(93)],
		[np.deg2rad(-31), np.deg2rad(31)],
		] * 4

		scaled = []
		for i in range(len(action)):
			low, high = joint_limits[i]
			scaled_val = 0.5 * (action[i] + 1) * (high - low) + low
			scaled.append(scaled_val)

		return np.array(scaled, dtype=np.float32)

	def move_robot(self, joint_angles):

		#Dogzilla specific functions
		motor_ids = [11,12,13,21,22,23,31,32,33,41,42,43]
		for i in range(len(joint_angles)):
			self.dogControl.motor(motor_ids[i], np.rad2deg(joint_angles[i]))

	def check_termination(self, observation):
	
		roll = observation[27]
		pitch = observation[28]
		done = abs(roll) > self.roll_threshold or abs(pitch) > self.pitch_threshold or self.current_step >= self.max_steps
		
		return done

	def close(self):
		print('Shutting down environement')
		self.node.destroy_node()
		rclpy.shutdown()

