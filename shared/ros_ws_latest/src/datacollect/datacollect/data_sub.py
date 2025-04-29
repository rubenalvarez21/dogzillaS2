import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from sensor_msgs.msg import JointState, Imu
import DOGZILLALib as dog
import numpy as np
import time
import math
import random
from scipy.spatial.transform import Rotation as R

control = dog.DOGZILLA()

class MultiSub(Node):
	def __init__(self, name):
		super().__init__(name)
		self.sub1 = self.create_subscription(Twist, "/cmd_vel", self.sub_callback1, 10)
		self.sub2 = self.create_subscription(JointState, "/joint_states", self.sub_callback2, 10)
		self.sub3 = self.create_subscription(Imu, "/imu/data_raw_self", self.sub_callback3, 10)
		self.sub1
		self.sub2
		self.sub3
		self.dogControl = dog.DOGZILLA()

		self.prev_time = None
		self.curr_time = time.time()
		self.prev_accel = [0.0, 0.0, 0.0]
		self.linear_cmd_vel = [0.0, 0.0, 0.0]
		self.velocity = [0.0, 0.0, 0.0]

		self.orientations = np.zeros(4, dtype=float)
		self.roll_threshold = 0.785
		self.roll = 0.0
		self.pitch = 0.0
		self.yaw = 0.0
		self.pitch_threshold = 0.785
		self.fallen = 0
		self.ang_velocities = np.zeros(3, dtype=float)
		
		self.lin_accelerations = np.zeros(3, dtype=float)
		self.accel_threshold = 0.05
		self.filtered_accelerations = np.zeros(3, dtype=float)
		self.body_accelerations = np.zeros(3, dtype=float)

		self.positions = np.zeros(12, dtype=float)
		self.velocities = np.zeros(12, dtype=float)
		
		self.home = [0.19408061, 0.76340701, 0.01902409, 0.19408061, 0.76340701, 0.01902409, 0.1584759, 0.9265953, 0.01902409, 0.17627825, 0.90495322, 0.01064651]

		self.joint_limits = [(-50, 40), (-50, 70), (-20, 20)]

		self.timer = self.create_timer(2, self.print_data)
		self.timer

	def sub_callback1(self, msg):
		self.linear_cmd_vel = [msg.linear.x, msg.linear.y, msg.linear.z]

	def sub_callback2(self, msg):
		self.velocities = np.array(msg.velocity)
		self.positions = np.array(msg.position)

	def sub_callback3(self, msg):
		self.curr_time = time.time()
		self.orientations = np.array([msg.orientation.x, msg.orientation.y, msg.orientation.z, msg.orientation.w])
		self.ang_velocities = np.array([msg.angular_velocity.x, msg.angular_velocity.y, msg.angular_velocity.z])
		self.body_accelerations = np.array([msg.linear_acceleration.x, msg.linear_acceleration.y, msg.linear_acceleration.z])

		t0 = 2.0*(self.orientations[3]*self.orientations[0] + self.orientations[1]*self.orientations[2])
		t1 = 1.0 - 2.0*(self.orientations[0]*self.orientations[0] + self.orientations[1]*self.orientations[1])
		self.roll = math.atan2(t0,t1)

		t2 = 2.0*(self.orientations[3]*self.orientations[1] - self.orientations[2]*self.orientations[0])
		t2 = max(min(t2,1.0),-1.0)
		self.pitch = math.asin(t2)

		t3 = 2.0*(self.orientations[3]*self.orientations[2] + self.orientations[0]*self.orientations[1])
		t4 = 1.0 - 2.0*(self.orientations[1]*self.orientations[1] + self.orientations[2]*self.orientations[2])
		self.yaw = math.atan2(t3,t4)
		
		#self.accel_offset = [-0.25, -0.04, -9.7]
		#self.lin_accelerations -= self.accel_offset

		#self.lin_accelerations = [0.0 if abs(accel) < self.accel_threshold else accel for accel in self.lin_accelerations]

		t = 2.0*np.cross(self.orientations[:3], self.body_accelerations)
		self.lin_accelerations = self.body_accelerations + self.orientations[3]*t + np.cross(self.orientations[:3], t)

		self.lin_accelerations -= [0, 0, -9.7]
		alpha = 0.15
		self.filtered_accelerations = alpha*self.lin_accelerations + (1 - alpha)*self.filtered_accelerations
		
		decay = .92

		if self.prev_time is not None:

			dt = self.curr_time - self.prev_time

			self.velocity = np.array(self.velocity)*decay + 0.5*(self.filtered_accelerations + self.prev_accel)*dt

			self.prev_accel = self.filtered_accelerations

		self.prev_time = self.curr_time

		if self.velocity[0] < -0.1:
			self.velocity[0] = 0.0
		
		if np.allclose(self.velocities, 0.0, atol=1e-3):
			self.velocity = [0.0, 0.0, 0.0]

		check = abs(self.roll) > self.roll_threshold or abs(self.pitch) > self.pitch_threshold
		self.fallen = int(check)

	def random_joints(self):

		motor_ids = [11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43]

		for i in range(4):
			for j in range(3):
				joint = random.uniform(self.joint_limits[j][0], self.joint_limits[j][1])

				motor_index = i*3 + j

				self.dogControl.motor(motor_ids[motor_index], joint)

	def move_robot(self, joint_angles):

                #Dogzilla specific functions
                motor_ids = [11,12,13,21,22,23,31,32,33,41,42,43]
                for i in range(len(joint_angles)):
                        self.dogControl.motor(motor_ids[i], np.rad2deg(joint_angles[i]))

	def print_data(self):
		#print(f"velocity: {self.velocity}")
		#self.move_robot(self.home)
		#print(f"At: {self.positions}")
		#print(f"Commanding: {self.home}")
		#print(self.velocities)
		#print([self.roll, self.pitch, self.yaw])
		#print(self.ang_velocities)
		#print(self.lin_accelerations)
		#print(self.fallen)
		print(f"body: {self.body_accelerations}")
		print(f"world: {self.lin_accelerations}")
		print(f"filtered: {self.filtered_accelerations}")

def main():
	rclpy.init()
	data_sub = MultiSub("data_sub")
	rclpy.spin(data_sub)
	data_sub.destroy_node()
	rclpy.shutdown()
