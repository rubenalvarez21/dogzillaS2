import rclpy
from rclpy.node import Node
from dog_joint_interfaces.msg import MotorAngle
from dog_joint_interfaces.srv import SetMotorAngle

class JointPositionController(Node):
	def __init__(self, name):
		super().__init__(name)
		self.pub = self.create_publisher(MotorAngle, "motor_angle_topic", 10)
		self.motor_id = 11
		self.joint_angle = 45.0
		self.valid_motor_ids = [11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43]
		self.angle_srv = self.create_service(SetMotorAngle, "set_motor_angle", self.handle_set_motor_angle)

		self.timer = self.create_timer(1.0, self.publish_motor_angle)

	def handle_set_motor_angle(self, request, response):

		if request.motor_id in self.valid_motor_ids:
			self.motor_id = request.motor_id
			self.joint_angle = request.joint_angle
			response.success = True
			response.message = f"Motor {request.motor_id} set to {request.joint_angle} degrees."
			self.get_logger().info(response.message)
		else:
			response.success = False
			response.message = f"Motor {request.motor_id} is invalid."
			self.get_logger().warn(response.message)

		return response

	def publish_motor_angle(self):
		msg = MotorAngle()
		msg.motor_id = self.motor_id
		msg.joint_angle = self.joint_angle
		self.pub.publish(msg)

def main():
	rclpy.init()
	joint_pub = JointPositionController("joints_publisher_node")
	rclpy.spin(joint_pub)
	joint_pub.destroy_node()
	rclpy.shutdown()
