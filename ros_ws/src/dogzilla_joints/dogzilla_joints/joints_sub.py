import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState

class JointState_Sub(Node):
	def __init__(self, name):
		super().__init__(name)

		self.sub = self.create_subscription(JointState, "/joint_states", self.sub_callback, 1)

	def sub_callback(self, msg):
		for position in msg.position:
			self.get_logger().info(f'{position:.5f}')

def main():
	rclpy.init()
	joint_sub = JointState_Sub("joint_sub_node")
	rclpy.spin(joint_sub)
	joint_sub.destroy_node()
	rclpy.shutdown()
