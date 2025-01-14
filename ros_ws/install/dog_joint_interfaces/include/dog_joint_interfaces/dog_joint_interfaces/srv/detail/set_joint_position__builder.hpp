// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from dog_joint_interfaces:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__BUILDER_HPP_
#define DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "dog_joint_interfaces/srv/detail/set_joint_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace dog_joint_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetJointPosition_Request_position
{
public:
  explicit Init_SetJointPosition_Request_position(::dog_joint_interfaces::srv::SetJointPosition_Request & msg)
  : msg_(msg)
  {}
  ::dog_joint_interfaces::srv::SetJointPosition_Request position(::dog_joint_interfaces::srv::SetJointPosition_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetJointPosition_Request msg_;
};

class Init_SetJointPosition_Request_joint_name
{
public:
  Init_SetJointPosition_Request_joint_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointPosition_Request_position joint_name(::dog_joint_interfaces::srv::SetJointPosition_Request::_joint_name_type arg)
  {
    msg_.joint_name = std::move(arg);
    return Init_SetJointPosition_Request_position(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetJointPosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_joint_interfaces::srv::SetJointPosition_Request>()
{
  return dog_joint_interfaces::srv::builder::Init_SetJointPosition_Request_joint_name();
}

}  // namespace dog_joint_interfaces


namespace dog_joint_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetJointPosition_Response_message
{
public:
  explicit Init_SetJointPosition_Response_message(::dog_joint_interfaces::srv::SetJointPosition_Response & msg)
  : msg_(msg)
  {}
  ::dog_joint_interfaces::srv::SetJointPosition_Response message(::dog_joint_interfaces::srv::SetJointPosition_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetJointPosition_Response msg_;
};

class Init_SetJointPosition_Response_success
{
public:
  Init_SetJointPosition_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetJointPosition_Response_message success(::dog_joint_interfaces::srv::SetJointPosition_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetJointPosition_Response_message(msg_);
  }

private:
  ::dog_joint_interfaces::srv::SetJointPosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::dog_joint_interfaces::srv::SetJointPosition_Response>()
{
  return dog_joint_interfaces::srv::builder::Init_SetJointPosition_Response_success();
}

}  // namespace dog_joint_interfaces

#endif  // DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__BUILDER_HPP_
