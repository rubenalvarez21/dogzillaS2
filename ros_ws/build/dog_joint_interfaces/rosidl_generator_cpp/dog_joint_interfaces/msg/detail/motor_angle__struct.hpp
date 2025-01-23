// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dog_joint_interfaces:msg/MotorAngle.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_HPP_
#define DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dog_joint_interfaces__msg__MotorAngle __attribute__((deprecated))
#else
# define DEPRECATED__dog_joint_interfaces__msg__MotorAngle __declspec(deprecated)
#endif

namespace dog_joint_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorAngle_
{
  using Type = MotorAngle_<ContainerAllocator>;

  explicit MotorAngle_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0l;
      this->joint_angle = 0.0;
    }
  }

  explicit MotorAngle_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0l;
      this->joint_angle = 0.0;
    }
  }

  // field types and members
  using _motor_id_type =
    int32_t;
  _motor_id_type motor_id;
  using _joint_angle_type =
    double;
  _joint_angle_type joint_angle;

  // setters for named parameter idiom
  Type & set__motor_id(
    const int32_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__joint_angle(
    const double & _arg)
  {
    this->joint_angle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_joint_interfaces__msg__MotorAngle
    std::shared_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_joint_interfaces__msg__MotorAngle
    std::shared_ptr<dog_joint_interfaces::msg::MotorAngle_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorAngle_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->joint_angle != other.joint_angle) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorAngle_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorAngle_

// alias to use template instance with default allocator
using MotorAngle =
  dog_joint_interfaces::msg::MotorAngle_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace dog_joint_interfaces

#endif  // DOG_JOINT_INTERFACES__MSG__DETAIL__MOTOR_ANGLE__STRUCT_HPP_
