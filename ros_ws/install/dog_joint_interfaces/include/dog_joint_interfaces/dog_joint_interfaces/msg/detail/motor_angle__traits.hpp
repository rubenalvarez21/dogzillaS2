// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__TRAITS_HPP_
#define DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dog_joint_interfaces/msg/detail/motor_angle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dog_joint_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MotorAngle & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id
  {
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << ", ";
  }

  // member: joint_angle
  {
    out << "joint_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_angle, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MotorAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << "\n";
  }

  // member: joint_angle
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_angle: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_angle, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MotorAngle & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace dog_joint_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dog_joint_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_joint_interfaces::msg::MotorAngle & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_joint_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_joint_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const dog_joint_interfaces::msg::MotorAngle & msg)
{
  return dog_joint_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<dog_joint_interfaces::msg::MotorAngle>()
{
  return "dog_joint_interfaces::msg::MotorAngle";
}

template<>
inline const char * name<dog_joint_interfaces::msg::MotorAngle>()
{
  return "dog_joint_interfaces/msg/MotorAngle";
}

template<>
struct has_fixed_size<dog_joint_interfaces::msg::MotorAngle>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<dog_joint_interfaces::msg::MotorAngle>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<dog_joint_interfaces::msg::MotorAngle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__TRAITS_HPP_
