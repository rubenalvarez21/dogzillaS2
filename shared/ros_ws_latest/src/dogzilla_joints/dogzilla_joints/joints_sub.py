import rclpy
from rclpy.node import Node
from dog_joint_interfaces.msg import MotorAngle
import DOGZILLALib as dog

control = dog.DOGZILLA()

class JointState_Sub(Node):
	def __init__(self, name):
		super().__init__(name)
		self.sub = self.create_subscription(MotorAngle, "motor_angle_topic", self.sub_callback, 10)
		self.sub
		self.dogControl = dog.DOGZILLA()

	def sub_callback(self, msg):
		self.get_logger().info(f'Motor: {msg.motor_id}, Angle: {msg.joint_angle}')
		print(self.dogControl.read_motor())

def main():
	rclpy.init()
	joint_sub = JointState_Sub("joint_sub_node")
	rclpy.spin(joint_sub)
	joint_sub.destroy_node()
	rclpy.shutdown()
