// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dog_joint_interfaces:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_H_
#define DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetJointPosition in the package dog_joint_interfaces.
typedef struct dog_joint_interfaces__srv__SetJointPosition_Request
{
  rosidl_runtime_c__String joint_name;
  double position;
} dog_joint_interfaces__srv__SetJointPosition_Request;

// Struct for a sequence of dog_joint_interfaces__srv__SetJointPosition_Request.
typedef struct dog_joint_interfaces__srv__SetJointPosition_Request__Sequence
{
  dog_joint_interfaces__srv__SetJointPosition_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_joint_interfaces__srv__SetJointPosition_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/SetJointPosition in the package dog_joint_interfaces.
typedef struct dog_joint_interfaces__srv__SetJointPosition_Response
{
  bool success;
  rosidl_runtime_c__String message;
} dog_joint_interfaces__srv__SetJointPosition_Response;

// Struct for a sequence of dog_joint_interfaces__srv__SetJointPosition_Response.
typedef struct dog_joint_interfaces__srv__SetJointPosition_Response__Sequence
{
  dog_joint_interfaces__srv__SetJointPosition_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_joint_interfaces__srv__SetJointPosition_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_H_
