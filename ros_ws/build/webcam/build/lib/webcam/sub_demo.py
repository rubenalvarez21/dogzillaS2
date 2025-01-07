import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class Topic_Sub(Node):
	def __init__(self,name):
		super().__init__(name)
		self.sub = self.create_subscription(String,"/topic_demo",self.sub_callback,1)

	def sub_callback(self, msg):
		print(msg.data)

def main():
	rclpy.init()
	sub_demo = Topic_Sub("Subscriber_node")
	rclpy.spin(sub_demo)
	sub_demo.destroy_node()
	rclpy.shutdown()
