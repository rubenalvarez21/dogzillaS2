// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice
#include "dog_joint_interfaces/msg/detail/motor_angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
dog_joint_interfaces__msg__MotorAngle__init(dog_joint_interfaces__msg__MotorAngle * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // joint_angle
  return true;
}

void
dog_joint_interfaces__msg__MotorAngle__fini(dog_joint_interfaces__msg__MotorAngle * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // joint_angle
}

bool
dog_joint_interfaces__msg__MotorAngle__are_equal(const dog_joint_interfaces__msg__MotorAngle * lhs, const dog_joint_interfaces__msg__MotorAngle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_id
  if (lhs->motor_id != rhs->motor_id) {
    return false;
  }
  // joint_angle
  if (lhs->joint_angle != rhs->joint_angle) {
    return false;
  }
  return true;
}

bool
dog_joint_interfaces__msg__MotorAngle__copy(
  const dog_joint_interfaces__msg__MotorAngle * input,
  dog_joint_interfaces__msg__MotorAngle * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // joint_angle
  output->joint_angle = input->joint_angle;
  return true;
}

dog_joint_interfaces__msg__MotorAngle *
dog_joint_interfaces__msg__MotorAngle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__msg__MotorAngle * msg = (dog_joint_interfaces__msg__MotorAngle *)allocator.allocate(sizeof(dog_joint_interfaces__msg__MotorAngle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_joint_interfaces__msg__MotorAngle));
  bool success = dog_joint_interfaces__msg__MotorAngle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_joint_interfaces__msg__MotorAngle__destroy(dog_joint_interfaces__msg__MotorAngle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_joint_interfaces__msg__MotorAngle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_joint_interfaces__msg__MotorAngle__Sequence__init(dog_joint_interfaces__msg__MotorAngle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__msg__MotorAngle * data = NULL;

  if (size) {
    data = (dog_joint_interfaces__msg__MotorAngle *)allocator.zero_allocate(size, sizeof(dog_joint_interfaces__msg__MotorAngle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_joint_interfaces__msg__MotorAngle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_joint_interfaces__msg__MotorAngle__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
dog_joint_interfaces__msg__MotorAngle__Sequence__fini(dog_joint_interfaces__msg__MotorAngle__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      dog_joint_interfaces__msg__MotorAngle__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

dog_joint_interfaces__msg__MotorAngle__Sequence *
dog_joint_interfaces__msg__MotorAngle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__msg__MotorAngle__Sequence * array = (dog_joint_interfaces__msg__MotorAngle__Sequence *)allocator.allocate(sizeof(dog_joint_interfaces__msg__MotorAngle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_joint_interfaces__msg__MotorAngle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_joint_interfaces__msg__MotorAngle__Sequence__destroy(dog_joint_interfaces__msg__MotorAngle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_joint_interfaces__msg__MotorAngle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_joint_interfaces__msg__MotorAngle__Sequence__are_equal(const dog_joint_interfaces__msg__MotorAngle__Sequence * lhs, const dog_joint_interfaces__msg__MotorAngle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_joint_interfaces__msg__MotorAngle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_joint_interfaces__msg__MotorAngle__Sequence__copy(
  const dog_joint_interfaces__msg__MotorAngle__Sequence * input,
  dog_joint_interfaces__msg__MotorAngle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_joint_interfaces__msg__MotorAngle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_joint_interfaces__msg__MotorAngle * data =
      (dog_joint_interfaces__msg__MotorAngle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_joint_interfaces__msg__MotorAngle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_joint_interfaces__msg__MotorAngle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_joint_interfaces__msg__MotorAngle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
