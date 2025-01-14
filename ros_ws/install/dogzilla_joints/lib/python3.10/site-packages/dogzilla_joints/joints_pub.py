import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from dog_joint_interfaces.srv import SetJointPosition

class JointPositionController(Node):
	def __init__(self, name):
		super().__init__(name)

		self.pub = self.create_publisher(JointState, "/joint_states", 1)

		self.joint_names = ["lf_upper_leg_joint", "lf_lower_leg_link", "lf_hip_joint", "lh_upper_leg_joint", "lh_lower_leg_joint", "lh_hip_joint", "rf_upper_leg_joint", "rf_lower_leg_joint", "rf_hip_joint", "rh_upper_leg_joint", "rh_lower_leg_joint", "rh_hip_joint"] 
		self.joint_positions = [0.212, -0.774, 0.011, 0.203, -0.774, 0.002, -0.176, 0.916, 0.015, -0.185, 0.905, 0.006]

		self.joint_srv = self.create_service(SetJointPosition, "set_joint_position", self.set_joint_position_callback)

		self.timer = self.create_timer(.1, self.publish_joint_states)

	def set_joint_position_callback(self, request, response):
		try:
			if request.joint_name in self.joint_names:
				index = self.joint_names.index(request.joint_name)
				self.joint_positions[index] = request.position
				self.get_logger().info(f"Updated {request.joint_name} to position {request.position:.5f}")
				response.success = True
				response.message = f"Joint {request.joint_name} updated successfully"

			else:
				response.success = False
				response.message = f"Joint {request.joint_name} not found"

		except Exception as e:
			response.success = False
			response.message = f"Failed to update joint: {str(e)}"

		return response

	def publish_joint_states(self):
		msg = JointState()
		msg.header.stamp = self.get_clock().now().to_msg()
		msg.name = self.joint_names
		msg.position = self.joint_positions
		self.pub.publish(msg)

def main():
	rclpy.init()
	joint_pub = JointPositionController("joints_publisher_node")
	rclpy.spin(joint_pub)
	joint_pub.destroy_node()
	rclpy.shutdown()
