// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "dog_joint_interfaces/msg/detail/motor_angle__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace dog_joint_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MotorAngle_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) dog_joint_interfaces::msg::MotorAngle(_init);
}

void MotorAngle_fini_function(void * message_memory)
{
  auto typed_message = static_cast<dog_joint_interfaces::msg::MotorAngle *>(message_memory);
  typed_message->~MotorAngle();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MotorAngle_message_member_array[2] = {
  {
    "motor_id",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dog_joint_interfaces::msg::MotorAngle, motor_id),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_angle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dog_joint_interfaces::msg::MotorAngle, joint_angle),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MotorAngle_message_members = {
  "dog_joint_interfaces::msg",  // message namespace
  "MotorAngle",  // message name
  2,  // number of fields
  sizeof(dog_joint_interfaces::msg::MotorAngle),
  MotorAngle_message_member_array,  // message members
  MotorAngle_init_function,  // function to initialize message memory (memory has to be allocated)
  MotorAngle_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MotorAngle_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MotorAngle_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace dog_joint_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<dog_joint_interfaces::msg::MotorAngle>()
{
  return &::dog_joint_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorAngle_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, dog_joint_interfaces, msg, MotorAngle)() {
  return &::dog_joint_interfaces::msg::rosidl_typesupport_introspection_cpp::MotorAngle_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
