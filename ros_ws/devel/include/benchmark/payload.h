// Generated by gencpp from file benchmark/payload.msg
// DO NOT EDIT!


#ifndef BENCHMARK_MESSAGE_PAYLOAD_H
#define BENCHMARK_MESSAGE_PAYLOAD_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace benchmark
{
template <class ContainerAllocator>
struct payload_
{
  typedef payload_<ContainerAllocator> Type;

  payload_()
    : header()
    , data()  {
    }
  payload_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> _data_type;
  _data_type data;





  typedef boost::shared_ptr< ::benchmark::payload_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::benchmark::payload_<ContainerAllocator> const> ConstPtr;

}; // struct payload_

typedef ::benchmark::payload_<std::allocator<void> > payload;

typedef boost::shared_ptr< ::benchmark::payload > payloadPtr;
typedef boost::shared_ptr< ::benchmark::payload const> payloadConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::benchmark::payload_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::benchmark::payload_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::benchmark::payload_<ContainerAllocator1> & lhs, const ::benchmark::payload_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::benchmark::payload_<ContainerAllocator1> & lhs, const ::benchmark::payload_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace benchmark

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::benchmark::payload_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::benchmark::payload_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::benchmark::payload_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::benchmark::payload_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::benchmark::payload_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::benchmark::payload_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::benchmark::payload_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8903b686ebe5db3477e83c6d0bb149f8";
  }

  static const char* value(const ::benchmark::payload_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8903b686ebe5db34ULL;
  static const uint64_t static_value2 = 0x77e83c6d0bb149f8ULL;
};

template<class ContainerAllocator>
struct DataType< ::benchmark::payload_<ContainerAllocator> >
{
  static const char* value()
  {
    return "benchmark/payload";
  }

  static const char* value(const ::benchmark::payload_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::benchmark::payload_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"uint8[] data\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::benchmark::payload_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::benchmark::payload_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct payload_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::benchmark::payload_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::benchmark::payload_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // BENCHMARK_MESSAGE_PAYLOAD_H
