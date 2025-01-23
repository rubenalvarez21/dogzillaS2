// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_H_
#define DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MotorAngle in the package dog_joint_interfaces.
typedef struct dog_joint_interfaces__msg__MotorAngle
{
  /// The motor's id number
  int32_t motor_id;
  /// The joint's angle in degrees
  double joint_angle;
} dog_joint_interfaces__msg__MotorAngle;

// Struct for a sequence of dog_joint_interfaces__msg__MotorAngle.
typedef struct dog_joint_interfaces__msg__MotorAngle__Sequence
{
  dog_joint_interfaces__msg__MotorAngle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} dog_joint_interfaces__msg__MotorAngle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_H_
