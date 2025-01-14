// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from dog_joint_interfaces:srv/SetJointPosition.idl
// generated code does not contain a copyright notice

#ifndef DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_
#define DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "dog_joint_interfaces/srv/detail/set_joint_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace dog_joint_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetJointPosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: joint_name
  {
    out << "joint_name: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_name, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetJointPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: joint_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "joint_name: ";
    rosidl_generator_traits::value_to_yaml(msg.joint_name, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetJointPosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dog_joint_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dog_joint_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_joint_interfaces::srv::SetJointPosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_joint_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_joint_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dog_joint_interfaces::srv::SetJointPosition_Request & msg)
{
  return dog_joint_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dog_joint_interfaces::srv::SetJointPosition_Request>()
{
  return "dog_joint_interfaces::srv::SetJointPosition_Request";
}

template<>
inline const char * name<dog_joint_interfaces::srv::SetJointPosition_Request>()
{
  return "dog_joint_interfaces/srv/SetJointPosition_Request";
}

template<>
struct has_fixed_size<dog_joint_interfaces::srv::SetJointPosition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dog_joint_interfaces::srv::SetJointPosition_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dog_joint_interfaces::srv::SetJointPosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace dog_joint_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetJointPosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetJointPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetJointPosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace dog_joint_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use dog_joint_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const dog_joint_interfaces::srv::SetJointPosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  dog_joint_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use dog_joint_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const dog_joint_interfaces::srv::SetJointPosition_Response & msg)
{
  return dog_joint_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<dog_joint_interfaces::srv::SetJointPosition_Response>()
{
  return "dog_joint_interfaces::srv::SetJointPosition_Response";
}

template<>
inline const char * name<dog_joint_interfaces::srv::SetJointPosition_Response>()
{
  return "dog_joint_interfaces/srv/SetJointPosition_Response";
}

template<>
struct has_fixed_size<dog_joint_interfaces::srv::SetJointPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<dog_joint_interfaces::srv::SetJointPosition_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<dog_joint_interfaces::srv::SetJointPosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<dog_joint_interfaces::srv::SetJointPosition>()
{
  return "dog_joint_interfaces::srv::SetJointPosition";
}

template<>
inline const char * name<dog_joint_interfaces::srv::SetJointPosition>()
{
  return "dog_joint_interfaces/srv/SetJointPosition";
}

template<>
struct has_fixed_size<dog_joint_interfaces::srv::SetJointPosition>
  : std::integral_constant<
    bool,
    has_fixed_size<dog_joint_interfaces::srv::SetJointPosition_Request>::value &&
    has_fixed_size<dog_joint_interfaces::srv::SetJointPosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<dog_joint_interfaces::srv::SetJointPosition>
  : std::integral_constant<
    bool,
    has_bounded_size<dog_joint_interfaces::srv::SetJointPosition_Request>::value &&
    has_bounded_size<dog_joint_interfaces::srv::SetJointPosition_Response>::value
  >
{
};

template<>
struct is_service<dog_joint_interfaces::srv::SetJointPosition>
  : std::true_type
{
};

template<>
struct is_service_request<dog_joint_interfaces::srv::SetJointPosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<dog_joint_interfaces::srv::SetJointPosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DOG_JOINT_INTERFACES__SRV__DETAIL__SET_JOINT_POSITION__TRAITS_HPP_
