// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__FUNCTIONS_H_
#define DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dog_joint_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "dog_joint_interfaces/msg/detail/motor_angle__struct.h"

/// Initialize msg/MotorAngle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dog_joint_interfaces__msg__MotorAngle
 * )) before or use
 * dog_joint_interfaces__msg__MotorAngle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__init(dog_joint_interfaces__msg__MotorAngle * msg);

/// Finalize msg/MotorAngle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
void
dog_joint_interfaces__msg__MotorAngle__fini(dog_joint_interfaces__msg__MotorAngle * msg);

/// Create msg/MotorAngle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dog_joint_interfaces__msg__MotorAngle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
dog_joint_interfaces__msg__MotorAngle *
dog_joint_interfaces__msg__MotorAngle__create();

/// Destroy msg/MotorAngle message.
/**
 * It calls
 * dog_joint_interfaces__msg__MotorAngle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
void
dog_joint_interfaces__msg__MotorAngle__destroy(dog_joint_interfaces__msg__MotorAngle * msg);

/// Check for msg/MotorAngle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__are_equal(const dog_joint_interfaces__msg__MotorAngle * lhs, const dog_joint_interfaces__msg__MotorAngle * rhs);

/// Copy a msg/MotorAngle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__copy(
  const dog_joint_interfaces__msg__MotorAngle * input,
  dog_joint_interfaces__msg__MotorAngle * output);

/// Initialize array of msg/MotorAngle messages.
/**
 * It allocates the memory for the number of elements and calls
 * dog_joint_interfaces__msg__MotorAngle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__Sequence__init(dog_joint_interfaces__msg__MotorAngle__Sequence * array, size_t size);

/// Finalize array of msg/MotorAngle messages.
/**
 * It calls
 * dog_joint_interfaces__msg__MotorAngle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
void
dog_joint_interfaces__msg__MotorAngle__Sequence__fini(dog_joint_interfaces__msg__MotorAngle__Sequence * array);

/// Create array of msg/MotorAngle messages.
/**
 * It allocates the memory for the array and calls
 * dog_joint_interfaces__msg__MotorAngle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
dog_joint_interfaces__msg__MotorAngle__Sequence *
dog_joint_interfaces__msg__MotorAngle__Sequence__create(size_t size);

/// Destroy array of msg/MotorAngle messages.
/**
 * It calls
 * dog_joint_interfaces__msg__MotorAngle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
void
dog_joint_interfaces__msg__MotorAngle__Sequence__destroy(dog_joint_interfaces__msg__MotorAngle__Sequence * array);

/// Check for msg/MotorAngle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__Sequence__are_equal(const dog_joint_interfaces__msg__MotorAngle__Sequence * lhs, const dog_joint_interfaces__msg__MotorAngle__Sequence * rhs);

/// Copy an array of msg/MotorAngle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_dog_joint_interfaces
bool
dog_joint_interfaces__msg__MotorAngle__Sequence__copy(
  const dog_joint_interfaces__msg__MotorAngle__Sequence * input,
  dog_joint_interfaces__msg__MotorAngle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__FUNCTIONS_H_
