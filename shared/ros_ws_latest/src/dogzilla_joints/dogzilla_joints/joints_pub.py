import rclpy
from rclpy.node import Node
from dog_joint_interfaces.msg import MotorAngle
from dog_joint_interfaces.srv import SetMotorAngle
import DOGZILLALib as dog
import time

control = dog.DOGZILLA()

class JointPositionController(Node):
	def __init__(self, name):
		super().__init__(name)
		self.dogControl = dog.DOGZILLA()
		self.pub = self.create_publisher(MotorAngle, "motor_angle_topic", 10)
		self.motor_id = 0
		self.joint_angle = 0.0
		self.valid_motor_ids = [11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43]
		self.angle_srv = self.create_service(SetMotorAngle, "set_motor_angle", self.handle_set_motor_angle)
		print("motor speed")
		self.dogControl.motor_speed(255)

		self.timer = self.create_timer(1.0, self.publish_motor_angle)

	def handle_set_motor_angle(self, request, response):

		if request.motor_id in self.valid_motor_ids:

			self.joint_angle = request.joint_angle
			self.motor_id = request.motor_id
			print("move")
			print(time.time())
			self.dogControl.motor(request.motor_id, request.joint_angle)
			response.success = True
			response.message = f"Step {i}: Motor {request.motor_id} set to {request.joint_angle} degrees."
			self.get_logger().info(response.message)

		else:
			response.success = False
			response.message = f"Motor {request.motor_id} is invalid."
			self.get_logger().warn(response.message)

		time.sleep(1)
		self.get_logger().info(f"Final angle for Motor {request.motor_id}: {request.joint_angle}")
		print(f"Actual: {self.dogControl.read_motor()[0]}")

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
