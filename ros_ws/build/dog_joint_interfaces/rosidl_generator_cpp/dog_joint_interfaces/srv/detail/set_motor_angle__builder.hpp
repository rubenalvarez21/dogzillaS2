// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_joint_interfaces:srv/SetMotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__SRV__DETAIL__SET_MOTOR_ANGLE__BUILDER_HPP_
#define DOG_JOINT_INTERFACES__SRV__DETAIL__SET_MOTOR_ANGLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_joint_interfaces/srv/detail/set_motor_angle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_joint_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetMotorAngle_Request_joint_angle
{
public:
  explicit Init_SetMotorAngle_Request_joint_angle(::dog_joint_interfaces::srv::SetMotorAngle_Request & msg)
  : msg_(msg)
  {}
  ::dog_joint_interfaces::srv::SetMotorAngle_Request joint_angle(::dog_joint_interfaces::srv::SetMotorAngle_Request::_joint_angle_type arg)
  {
    msg_.joint_angle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetMotorAngle_Request msg_;
};

class Init_SetMotorAngle_Request_motor_id
{
public:
  Init_SetMotorAngle_Request_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotorAngle_Request_joint_angle motor_id(::dog_joint_interfaces::srv::SetMotorAngle_Request::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_SetMotorAngle_Request_joint_angle(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetMotorAngle_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_joint_interfaces::srv::SetMotorAngle_Request>()
{
  return dog_joint_interfaces::srv::builder::Init_SetMotorAngle_Request_motor_id();
}

}  // namespace dog_joint_interfaces


namespace dog_joint_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetMotorAngle_Response_message
{
public:
  explicit Init_SetMotorAngle_Response_message(::dog_joint_interfaces::srv::SetMotorAngle_Response & msg)
  : msg_(msg)
  {}
  ::dog_joint_interfaces::srv::SetMotorAngle_Response message(::dog_joint_interfaces::srv::SetMotorAngle_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetMotorAngle_Response msg_;
};

class Init_SetMotorAngle_Response_success
{
public:
  Init_SetMotorAngle_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetMotorAngle_Response_message success(::dog_joint_interfaces::srv::SetMotorAngle_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetMotorAngle_Response_message(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetMotorAngle_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_joint_interfaces::srv::SetMotorAngle_Response>()
{
  return dog_joint_interfaces::srv::builder::Init_SetMotorAngle_Response_success();
}

}  // namespace dog_joint_interfaces

#endif  // DOG_JOINT_INTERFACES__SRV__DETAIL__SET_MOTOR_ANGLE__BUILDER_HPP_
