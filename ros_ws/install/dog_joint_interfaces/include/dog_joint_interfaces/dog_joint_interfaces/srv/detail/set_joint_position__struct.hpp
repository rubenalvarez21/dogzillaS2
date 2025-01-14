// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from dog_joint_interfaces:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_HPP_
#define DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Request __attribute__((deprecated))
#else
# define DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Request __declspec(deprecated)
#endif

namespace dog_joint_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetJointPosition_Request_
{
  using Type = SetJointPosition_Request_<ContainerAllocator>;

  explicit SetJointPosition_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint_name = "";
      this->position = 0.0;
    }
  }

  explicit SetJointPosition_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint_name = "";
      this->position = 0.0;
    }
  }

  // field types and members
  using _joint_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _joint_name_type joint_name;
  using _position_type =
    double;
  _position_type position;

  // setters for named parameter idiom
  Type & set__joint_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->joint_name = _arg;
    return *this;
  }
  Type & set__position(
    const double & _arg)
  {
    this->position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Request
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Request
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetJointPosition_Request_ & other) const
  {
    if (this->joint_name != other.joint_name) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetJointPosition_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetJointPosition_Request_

// alias to use template instance with default allocator
using SetJointPosition_Request =
  dog_joint_interfaces::srv::SetJointPosition_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dog_joint_interfaces


#ifndef _WIN32
# define DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Response __attribute__((deprecated))
#else
# define DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Response __declspec(deprecated)
#endif

namespace dog_joint_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetJointPosition_Response_
{
  using Type = SetJointPosition_Response_<ContainerAllocator>;

  explicit SetJointPosition_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetJointPosition_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Response
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__dog_joint_interfaces__srv__SetJointPosition_Response
    std::shared_ptr<dog_joint_interfaces::srv::SetJointPosition_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetJointPosition_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetJointPosition_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetJointPosition_Response_

// alias to use template instance with default allocator
using SetJointPosition_Response =
  dog_joint_interfaces::srv::SetJointPosition_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace dog_joint_interfaces

namespace dog_joint_interfaces
{

namespace srv
{

struct SetJointPosition
{
  using Request = dog_joint_interfaces::srv::SetJointPosition_Request;
  using Response = dog_joint_interfaces::srv::SetJointPosition_Response;
};

}  // namespace srv

}  // namespace dog_joint_interfaces

#endif  // DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__STRUCT_HPP_
