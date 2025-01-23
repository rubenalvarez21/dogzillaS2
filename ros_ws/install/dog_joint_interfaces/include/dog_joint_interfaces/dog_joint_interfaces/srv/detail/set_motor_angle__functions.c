// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dog_joint_interfaces:srv/SetMotorAngle.idl
// generated code does not contain a copyright notice
#include "dog_joint_interfaces/srv/detail/set_motor_angle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
dog_joint_interfaces__srv__SetMotorAngle_Request__init(dog_joint_interfaces__srv__SetMotorAngle_Request * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // joint_angle
  return true;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Request__fini(dog_joint_interfaces__srv__SetMotorAngle_Request * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // joint_angle
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Request__are_equal(const dog_joint_interfaces__srv__SetMotorAngle_Request * lhs, const dog_joint_interfaces__srv__SetMotorAngle_Request * rhs)
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
dog_joint_interfaces__srv__SetMotorAngle_Request__copy(
  const dog_joint_interfaces__srv__SetMotorAngle_Request * input,
  dog_joint_interfaces__srv__SetMotorAngle_Request * output)
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

dog_joint_interfaces__srv__SetMotorAngle_Request *
dog_joint_interfaces__srv__SetMotorAngle_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Request * msg = (dog_joint_interfaces__srv__SetMotorAngle_Request *)allocator.allocate(sizeof(dog_joint_interfaces__srv__SetMotorAngle_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_joint_interfaces__srv__SetMotorAngle_Request));
  bool success = dog_joint_interfaces__srv__SetMotorAngle_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Request__destroy(dog_joint_interfaces__srv__SetMotorAngle_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_joint_interfaces__srv__SetMotorAngle_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__init(dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Request * data = NULL;

  if (size) {
    data = (dog_joint_interfaces__srv__SetMotorAngle_Request *)allocator.zero_allocate(size, sizeof(dog_joint_interfaces__srv__SetMotorAngle_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_joint_interfaces__srv__SetMotorAngle_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_joint_interfaces__srv__SetMotorAngle_Request__fini(&data[i - 1]);
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
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__fini(dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * array)
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
      dog_joint_interfaces__srv__SetMotorAngle_Request__fini(&array->data[i]);
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

dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence *
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * array = (dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence *)allocator.allocate(sizeof(dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__destroy(dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__are_equal(const dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * lhs, const dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_joint_interfaces__srv__SetMotorAngle_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence__copy(
  const dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * input,
  dog_joint_interfaces__srv__SetMotorAngle_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_joint_interfaces__srv__SetMotorAngle_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_joint_interfaces__srv__SetMotorAngle_Request * data =
      (dog_joint_interfaces__srv__SetMotorAngle_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_joint_interfaces__srv__SetMotorAngle_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_joint_interfaces__srv__SetMotorAngle_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_joint_interfaces__srv__SetMotorAngle_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
dog_joint_interfaces__srv__SetMotorAngle_Response__init(dog_joint_interfaces__srv__SetMotorAngle_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    dog_joint_interfaces__srv__SetMotorAngle_Response__fini(msg);
    return false;
  }
  return true;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Response__fini(dog_joint_interfaces__srv__SetMotorAngle_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Response__are_equal(const dog_joint_interfaces__srv__SetMotorAngle_Response * lhs, const dog_joint_interfaces__srv__SetMotorAngle_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Response__copy(
  const dog_joint_interfaces__srv__SetMotorAngle_Response * input,
  dog_joint_interfaces__srv__SetMotorAngle_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

dog_joint_interfaces__srv__SetMotorAngle_Response *
dog_joint_interfaces__srv__SetMotorAngle_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Response * msg = (dog_joint_interfaces__srv__SetMotorAngle_Response *)allocator.allocate(sizeof(dog_joint_interfaces__srv__SetMotorAngle_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dog_joint_interfaces__srv__SetMotorAngle_Response));
  bool success = dog_joint_interfaces__srv__SetMotorAngle_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Response__destroy(dog_joint_interfaces__srv__SetMotorAngle_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dog_joint_interfaces__srv__SetMotorAngle_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__init(dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Response * data = NULL;

  if (size) {
    data = (dog_joint_interfaces__srv__SetMotorAngle_Response *)allocator.zero_allocate(size, sizeof(dog_joint_interfaces__srv__SetMotorAngle_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dog_joint_interfaces__srv__SetMotorAngle_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dog_joint_interfaces__srv__SetMotorAngle_Response__fini(&data[i - 1]);
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
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__fini(dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * array)
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
      dog_joint_interfaces__srv__SetMotorAngle_Response__fini(&array->data[i]);
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

dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence *
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * array = (dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence *)allocator.allocate(sizeof(dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__destroy(dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__are_equal(const dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * lhs, const dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dog_joint_interfaces__srv__SetMotorAngle_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence__copy(
  const dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * input,
  dog_joint_interfaces__srv__SetMotorAngle_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dog_joint_interfaces__srv__SetMotorAngle_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    dog_joint_interfaces__srv__SetMotorAngle_Response * data =
      (dog_joint_interfaces__srv__SetMotorAngle_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dog_joint_interfaces__srv__SetMotorAngle_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          dog_joint_interfaces__srv__SetMotorAngle_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dog_joint_interfaces__srv__SetMotorAngle_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
