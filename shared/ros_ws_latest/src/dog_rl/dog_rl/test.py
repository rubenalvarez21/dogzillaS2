import torch
import torch.nn as nn
import torch.nn.functional as F
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState, Imu
import numpy as np
import DOGZILLALib as dog
import time
import math

control = dog.DOGZILLA()

class Model(nn.Module):
    def __init__(self, inputs=37, h1=120, h2 = 120, h3 = 120, output=12):
        super().__init__()
        self.fc1 = nn.Linear(inputs, h1)
        self.fc2 = nn.Linear(h1, h2)
        self.fc3 = nn.Linear(h2, h3)
        self.out = nn.Linear(h3, output)

    def forward(self, x):
        x = F.relu(self.fc1(x))
        x = F.relu(self.fc2(x))
        x = F.relu(self.fc3(x))
        x = self.out(x)

        return x
        
class TestTrained(Node):
	def __init__(self, name):
		super().__init__(name)

		self.sub1 = self.create_subscription(JointState, "/joint_states", self.sub_callback1, 10)
		self.sub2 = self.create_subscription(Imu, "/imu/data_raw_self", self.sub_callback2, 10)
		self.sub1
		self.sub2
		self.dogControl = dog.DOGZILLA()

		self.prev_time = None
		self.curr_time = time.time()
		self.prev_accel = [0.0, 0.0, 0.0]
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
		self.body_accelerations = np.zeros(3, dtype=float)
		self.filtered_accelerations = np.zeros(3, dtype=float)
		self.accel_threshold = 0.05

		self.positions = np.zeros(12, dtype=float)
		self.velocities = np.zeros(12, dtype=float)

		self.model = Model()
		self.model.load_state_dict(torch.load('/root/initial_policy.pth', weights_only=True))
		self.model.eval()

		self.timer = self.create_timer(1.5, self.move_robot)
		self.timer

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
		self.roll = math.atan2(t0,t1)

		t2 = 2.0*(self.orientations[3]*self.orientations[1] - self.orientations[2]*self.orientations[0])
		t2 = max(min(t2,1.0),-1.0)
		self.pitch = math.asin(t2)

		t3 = 2.0*(self.orientations[3]*self.orientations[2] + self.orientations[0]*self.orientations[1])
		t4 = 1.0 - 2.0*(self.orientations[1]*self.orientations[1] + self.orientations[2]*self.orientations[2])
		self.yaw = math.atan2(t3,t4)

		t = 2.0*np.cross(self.orientations[:3], self.body_accelerations)
		self.lin_accelerations = self.body_accelerations + self.orientations[3]*t + np.cross(self.orientations[:3], t)

		self.lin_accelerations -= [0, 0, -9.8]
		alpha = 0.15
		self.filtered_accelerations = alpha*self.lin_accelerations + (1 - alpha)*self.filtered_accelerations

		if self.prev_time is not None:

			dt = self.curr_time - self.prev_time

			self.velocity += 0.5*(self.filtered_accelerations + self.prev_accel)*dt

			self.prev_accel = self.filtered_accelerations

		self.prev_time = self.curr_time

		if self.velocity[0] < -0.01:
			self.velocity[0] = 0.0
		
		if np.allclose(self.velocities, 0.0, atol=1e-3):
			self.velocity = [0.0, 0.0, 0.0]

		check = abs(self.roll) > self.roll_threshold or abs(self.pitch) > self.pitch_threshold
		self.fallen = int(check)

	def move_robot(self):

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
		inputs = np.concatenate((self.velocity, self.positions, self.velocities, roll, pitch, yaw, self.ang_velocities, self.lin_accelerations, fallen))
		inputs = torch.FloatTensor(inputs)
		
		outputs = self.model(inputs)
		outputs = outputs.tolist()
		
		motor_ids = [11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43]
		
		for i in range(len(motor_ids)):
			print(motor_ids[i])
			print(np.rad2deg(outputs[i]))
		

def main():
	rclpy.init()
	test_trained = TestTrained('test_trained')
	rclpy.spin(test_trained)
	test_trained.destroy_node()
	rclpy.shutdown()
