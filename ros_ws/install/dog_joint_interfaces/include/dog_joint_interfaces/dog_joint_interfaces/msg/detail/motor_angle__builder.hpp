// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_
#define DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_joint_interfaces/msg/detail/motor_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_joint_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorAngle_joint_angle
{
public:
  explicit Init_MotorAngle_joint_angle(::dog_joint_interfaces::msg::MotorAngle & msg)
  : msg_(msg)
  {}
  ::dog_joint_interfaces::msg::MotorAngle joint_angle(::dog_joint_interfaces::msg::MotorAngle::_joint_angle_type arg)
  {
    msg_.joint_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_joint_interfaces::msg::MotorAngle msg_;
};

class Init_MotorAngle_motor_id
{
public:
  Init_MotorAngle_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorAngle_joint_angle motor_id(::dog_joint_interfaces::msg::MotorAngle::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_MotorAngle_joint_angle(msg_);
  }

private:
  ::dog_joint_interfaces::msg::MotorAngle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_joint_interfaces::msg::MotorAngle>()
{
  return dog_joint_interfaces::msg::builder::Init_MotorAngle_motor_id();
}

}  // namespace dog_joint_interfaces

#endif  // DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__BUILDER_HPP_
