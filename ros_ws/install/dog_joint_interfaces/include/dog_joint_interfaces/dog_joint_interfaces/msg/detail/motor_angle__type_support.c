// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "dog_joint_interfaces/msg/detail/motor_angle__rosidl_typesupport_introspection_c.h"
#include "dog_joint_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "dog_joint_interfaces/msg/detail/motor_angle__functions.h"
#include "dog_joint_interfaces/msg/detail/motor_angle__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  dog_joint_interfaces__msg__MotorAngle__init(message_memory);
}

void dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_fini_function(void * message_memory)
{
  dog_joint_interfaces__msg__MotorAngle__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_member_array[2] = {
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dog_joint_interfaces__msg__MotorAngle, motor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_angle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(dog_joint_interfaces__msg__MotorAngle, joint_angle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_members = {
  "dog_joint_interfaces__msg",  // message namespace
  "MotorAngle",  // message name
  2,  // number of fields
  sizeof(dog_joint_interfaces__msg__MotorAngle),
  dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_member_array,  // message members
  dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_init_function,  // function to initialize message memory (memory has to be allocated)
  dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_type_support_handle = {
  0,
  &dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_dog_joint_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, dog_joint_interfaces, msg, MotorAngle)() {
  if (!dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_type_support_handle.typesupport_identifier) {
    dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &dog_joint_interfaces__msg__MotorAngle__rosidl_typesupport_introspection_c__MotorAngle_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
