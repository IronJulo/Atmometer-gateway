/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: protocol.proto
 */

// This file is generated. Please do not edit!
#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>
#include <Defines.h>
#include <limits>

// Include external proto definitions

namespace com {
namespace epitech {
namespace atmos {
namespace protobuf {

class Header final: public ::EmbeddedProto::MessageInterface
{
  public:
    Header() = default;
    Header(const Header& rhs )
    {
      set_device_id(rhs.get_device_id());
      set_packet_crc(rhs.get_packet_crc());
    }

    Header(const Header&& rhs ) noexcept
    {
      set_device_id(rhs.get_device_id());
      set_packet_crc(rhs.get_packet_crc());
    }

    ~Header() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      DEVICE_ID = 1,
      PACKET_CRC = 2
    };

    Header& operator=(const Header& rhs)
    {
      set_device_id(rhs.get_device_id());
      set_packet_crc(rhs.get_packet_crc());
      return *this;
    }

    Header& operator=(const Header&& rhs) noexcept
    {
      set_device_id(rhs.get_device_id());
      set_packet_crc(rhs.get_packet_crc());
      return *this;
    }

    static constexpr char const* DEVICE_ID_NAME = "device_id";
    inline void clear_device_id() { device_id_.clear(); }
    inline void set_device_id(const uint32_t& value) { device_id_ = value; }
    inline void set_device_id(const uint32_t&& value) { device_id_ = value; }
    inline uint32_t& mutable_device_id() { return device_id_.get(); }
    inline const uint32_t& get_device_id() const { return device_id_.get(); }
    inline uint32_t device_id() const { return device_id_.get(); }

    static constexpr char const* PACKET_CRC_NAME = "packet_crc";
    inline void clear_packet_crc() { packet_crc_.clear(); }
    inline void set_packet_crc(const uint32_t& value) { packet_crc_ = value; }
    inline void set_packet_crc(const uint32_t&& value) { packet_crc_ = value; }
    inline uint32_t& mutable_packet_crc() { return packet_crc_.get(); }
    inline const uint32_t& get_packet_crc() const { return packet_crc_.get(); }
    inline uint32_t packet_crc() const { return packet_crc_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != device_id_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = device_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::DEVICE_ID), buffer, false);
      }

      if((0U != packet_crc_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = packet_crc_.serialize_with_id(static_cast<uint32_t>(FieldNumber::PACKET_CRC), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::DEVICE_ID:
            return_value = device_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::PACKET_CRC:
            return_value = packet_crc_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_device_id();
      clear_packet_crc();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::DEVICE_ID:
          name = DEVICE_ID_NAME;
          break;
        case FieldNumber::PACKET_CRC:
          name = PACKET_CRC_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = device_id_.to_string(left_chars, indent_level + 2, DEVICE_ID_NAME, true);
      left_chars = packet_crc_.to_string(left_chars, indent_level + 2, PACKET_CRC_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint32 device_id_ = 0U;
      EmbeddedProto::uint32 packet_crc_ = 0U;

};

class Socket final: public ::EmbeddedProto::MessageInterface
{
  public:
    Socket() = default;
    Socket(const Socket& rhs )
    {
      set_socket_id(rhs.get_socket_id());
      set_sensor_id(rhs.get_sensor_id());
      set_sensor_type(rhs.get_sensor_type());
    }

    Socket(const Socket&& rhs ) noexcept
    {
      set_socket_id(rhs.get_socket_id());
      set_sensor_id(rhs.get_sensor_id());
      set_sensor_type(rhs.get_sensor_type());
    }

    ~Socket() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      SOCKET_ID = 1,
      SENSOR_ID = 2,
      SENSOR_TYPE = 3
    };

    Socket& operator=(const Socket& rhs)
    {
      set_socket_id(rhs.get_socket_id());
      set_sensor_id(rhs.get_sensor_id());
      set_sensor_type(rhs.get_sensor_type());
      return *this;
    }

    Socket& operator=(const Socket&& rhs) noexcept
    {
      set_socket_id(rhs.get_socket_id());
      set_sensor_id(rhs.get_sensor_id());
      set_sensor_type(rhs.get_sensor_type());
      return *this;
    }

    static constexpr char const* SOCKET_ID_NAME = "socket_id";
    inline void clear_socket_id() { socket_id_.clear(); }
    inline void set_socket_id(const uint32_t& value) { socket_id_ = value; }
    inline void set_socket_id(const uint32_t&& value) { socket_id_ = value; }
    inline uint32_t& mutable_socket_id() { return socket_id_.get(); }
    inline const uint32_t& get_socket_id() const { return socket_id_.get(); }
    inline uint32_t socket_id() const { return socket_id_.get(); }

    static constexpr char const* SENSOR_ID_NAME = "sensor_id";
    inline void clear_sensor_id() { sensor_id_.clear(); }
    inline void set_sensor_id(const uint32_t& value) { sensor_id_ = value; }
    inline void set_sensor_id(const uint32_t&& value) { sensor_id_ = value; }
    inline uint32_t& mutable_sensor_id() { return sensor_id_.get(); }
    inline const uint32_t& get_sensor_id() const { return sensor_id_.get(); }
    inline uint32_t sensor_id() const { return sensor_id_.get(); }

    static constexpr char const* SENSOR_TYPE_NAME = "sensor_type";
    inline void clear_sensor_type() { sensor_type_.clear(); }
    inline void set_sensor_type(const uint32_t& value) { sensor_type_ = value; }
    inline void set_sensor_type(const uint32_t&& value) { sensor_type_ = value; }
    inline uint32_t& mutable_sensor_type() { return sensor_type_.get(); }
    inline const uint32_t& get_sensor_type() const { return sensor_type_.get(); }
    inline uint32_t sensor_type() const { return sensor_type_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0U != socket_id_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = socket_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOCKET_ID), buffer, false);
      }

      if((0U != sensor_id_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sensor_id_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSOR_ID), buffer, false);
      }

      if((0U != sensor_type_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sensor_type_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSOR_TYPE), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::SOCKET_ID:
            return_value = socket_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSOR_ID:
            return_value = sensor_id_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSOR_TYPE:
            return_value = sensor_type_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_socket_id();
      clear_sensor_id();
      clear_sensor_type();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::SOCKET_ID:
          name = SOCKET_ID_NAME;
          break;
        case FieldNumber::SENSOR_ID:
          name = SENSOR_ID_NAME;
          break;
        case FieldNumber::SENSOR_TYPE:
          name = SENSOR_TYPE_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = socket_id_.to_string(left_chars, indent_level + 2, SOCKET_ID_NAME, true);
      left_chars = sensor_id_.to_string(left_chars, indent_level + 2, SENSOR_ID_NAME, false);
      left_chars = sensor_type_.to_string(left_chars, indent_level + 2, SENSOR_TYPE_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      EmbeddedProto::uint32 socket_id_ = 0U;
      EmbeddedProto::uint32 sensor_id_ = 0U;
      EmbeddedProto::uint32 sensor_type_ = 0U;

};

template<
    uint32_t Data_packet_sensor_data_REP_LENGTH
>
class Data_packet final: public ::EmbeddedProto::MessageInterface
{
  public:
    Data_packet() = default;
    Data_packet(const Data_packet& rhs )
    {
      set_header(rhs.get_header());
      set_sensor_data(rhs.get_sensor_data());
    }

    Data_packet(const Data_packet&& rhs ) noexcept
    {
      set_header(rhs.get_header());
      set_sensor_data(rhs.get_sensor_data());
    }

    ~Data_packet() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      HEADER = 1,
      SENSOR_DATA = 2
    };

    Data_packet& operator=(const Data_packet& rhs)
    {
      set_header(rhs.get_header());
      set_sensor_data(rhs.get_sensor_data());
      return *this;
    }

    Data_packet& operator=(const Data_packet&& rhs) noexcept
    {
      set_header(rhs.get_header());
      set_sensor_data(rhs.get_sensor_data());
      return *this;
    }

    static constexpr char const* HEADER_NAME = "header";
    inline void clear_header() { header_.clear(); }
    inline void set_header(const Header& value) { header_ = value; }
    inline void set_header(const Header&& value) { header_ = value; }
    inline Header& mutable_header() { return header_; }
    inline const Header& get_header() const { return header_; }
    inline const Header& header() const { return header_; }

    static constexpr char const* SENSOR_DATA_NAME = "sensor_data";
    inline const EmbeddedProto::uint32& sensor_data(uint32_t index) const { return sensor_data_[index]; }
    inline void clear_sensor_data() { sensor_data_.clear(); }
    inline void set_sensor_data(uint32_t index, const EmbeddedProto::uint32& value) { sensor_data_.set(index, value); }
    inline void set_sensor_data(uint32_t index, const EmbeddedProto::uint32&& value) { sensor_data_.set(index, value); }
    inline void set_sensor_data(const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Data_packet_sensor_data_REP_LENGTH>& values) { sensor_data_ = values; }
    inline void add_sensor_data(const EmbeddedProto::uint32& value) { sensor_data_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Data_packet_sensor_data_REP_LENGTH>& mutable_sensor_data() { return sensor_data_; }
    inline EmbeddedProto::uint32& mutable_sensor_data(uint32_t index) { return sensor_data_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Data_packet_sensor_data_REP_LENGTH>& get_sensor_data() const { return sensor_data_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Data_packet_sensor_data_REP_LENGTH>& sensor_data() const { return sensor_data_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = header_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HEADER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensor_data_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SENSOR_DATA), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::HEADER:
            return_value = header_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SENSOR_DATA:
            return_value = sensor_data_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_header();
      clear_sensor_data();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::HEADER:
          name = HEADER_NAME;
          break;
        case FieldNumber::SENSOR_DATA:
          name = SENSOR_DATA_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = header_.to_string(left_chars, indent_level + 2, HEADER_NAME, true);
      left_chars = sensor_data_.to_string(left_chars, indent_level + 2, SENSOR_DATA_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      Header header_;
      ::EmbeddedProto::RepeatedFieldFixedSize<EmbeddedProto::uint32, Data_packet_sensor_data_REP_LENGTH> sensor_data_;

};

template<
    uint32_t Socket_layout_packet_socket_data_REP_LENGTH
>
class Socket_layout_packet final: public ::EmbeddedProto::MessageInterface
{
  public:
    Socket_layout_packet() = default;
    Socket_layout_packet(const Socket_layout_packet& rhs )
    {
      set_header(rhs.get_header());
      set_socket_data(rhs.get_socket_data());
    }

    Socket_layout_packet(const Socket_layout_packet&& rhs ) noexcept
    {
      set_header(rhs.get_header());
      set_socket_data(rhs.get_socket_data());
    }

    ~Socket_layout_packet() override = default;

    enum class FieldNumber : uint32_t
    {
      NOT_SET = 0,
      HEADER = 1,
      SOCKET_DATA = 2
    };

    Socket_layout_packet& operator=(const Socket_layout_packet& rhs)
    {
      set_header(rhs.get_header());
      set_socket_data(rhs.get_socket_data());
      return *this;
    }

    Socket_layout_packet& operator=(const Socket_layout_packet&& rhs) noexcept
    {
      set_header(rhs.get_header());
      set_socket_data(rhs.get_socket_data());
      return *this;
    }

    static constexpr char const* HEADER_NAME = "header";
    inline void clear_header() { header_.clear(); }
    inline void set_header(const Header& value) { header_ = value; }
    inline void set_header(const Header&& value) { header_ = value; }
    inline Header& mutable_header() { return header_; }
    inline const Header& get_header() const { return header_; }
    inline const Header& header() const { return header_; }

    static constexpr char const* SOCKET_DATA_NAME = "socket_data";
    inline const Socket& socket_data(uint32_t index) const { return socket_data_[index]; }
    inline void clear_socket_data() { socket_data_.clear(); }
    inline void set_socket_data(uint32_t index, const Socket& value) { socket_data_.set(index, value); }
    inline void set_socket_data(uint32_t index, const Socket&& value) { socket_data_.set(index, value); }
    inline void set_socket_data(const ::EmbeddedProto::RepeatedFieldFixedSize<Socket, Socket_layout_packet_socket_data_REP_LENGTH>& values) { socket_data_ = values; }
    inline void add_socket_data(const Socket& value) { socket_data_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<Socket, Socket_layout_packet_socket_data_REP_LENGTH>& mutable_socket_data() { return socket_data_; }
    inline Socket& mutable_socket_data(uint32_t index) { return socket_data_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Socket, Socket_layout_packet_socket_data_REP_LENGTH>& get_socket_data() const { return socket_data_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<Socket, Socket_layout_packet_socket_data_REP_LENGTH>& socket_data() const { return socket_data_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = header_.serialize_with_id(static_cast<uint32_t>(FieldNumber::HEADER), buffer, false);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = socket_data_.serialize_with_id(static_cast<uint32_t>(FieldNumber::SOCKET_DATA), buffer, false);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      FieldNumber id_tag = FieldNumber::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<FieldNumber>(id_number);
        switch(id_tag)
        {
          case FieldNumber::HEADER:
            return_value = header_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::SOCKET_DATA:
            return_value = socket_data_.deserialize_check_type(buffer, wire_type);
            break;

          case FieldNumber::NOT_SET:
            return_value = ::EmbeddedProto::Error::INVALID_FIELD_ID;
            break;

          default:
            return_value = skip_unknown_field(buffer, wire_type);
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_header();
      clear_socket_data();

    }

    static char const* field_number_to_name(const FieldNumber fieldNumber)
    {
      char const* name = nullptr;
      switch(fieldNumber)
      {
        case FieldNumber::HEADER:
          name = HEADER_NAME;
          break;
        case FieldNumber::SOCKET_DATA:
          name = SOCKET_DATA_NAME;
          break;
        default:
          name = "Invalid FieldNumber";
          break;
      }
      return name;
    }

#ifdef MSG_TO_STRING

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str) const
    {
      return this->to_string(str, 0, nullptr, true);
    }

    ::EmbeddedProto::string_view to_string(::EmbeddedProto::string_view& str, const uint32_t indent_level, char const* name, const bool first_field) const override
    {
      ::EmbeddedProto::string_view left_chars = str;
      int32_t n_chars_used = 0;

      if(!first_field)
      {
        // Add a comma behind the previous field.
        n_chars_used = snprintf(left_chars.data, left_chars.size, ",\n");
        if(0 < n_chars_used)
        {
          // Update the character pointer and characters left in the array.
          left_chars.data += n_chars_used;
          left_chars.size -= n_chars_used;
        }
      }

      if(nullptr != name)
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "\"%s\": {\n", name);
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s\"%s\": {\n", indent_level, " ", name);
        }
      }
      else
      {
        if( 0 == indent_level)
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "{\n");
        }
        else
        {
          n_chars_used = snprintf(left_chars.data, left_chars.size, "%*s{\n", indent_level, " ");
        }
      }
      
      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      left_chars = header_.to_string(left_chars, indent_level + 2, HEADER_NAME, true);
      left_chars = socket_data_.to_string(left_chars, indent_level + 2, SOCKET_DATA_NAME, false);
  
      if( 0 == indent_level) 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n}");
      }
      else 
      {
        n_chars_used = snprintf(left_chars.data, left_chars.size, "\n%*s}", indent_level, " ");
      }

      if(0 < n_chars_used)
      {
        left_chars.data += n_chars_used;
        left_chars.size -= n_chars_used;
      }

      return left_chars;
    }

#endif // End of MSG_TO_STRING

  private:


      Header header_;
      ::EmbeddedProto::RepeatedFieldFixedSize<Socket, Socket_layout_packet_socket_data_REP_LENGTH> socket_data_;

};

} // End of namespace protobuf
} // End of namespace atmos
} // End of namespace epitech
} // End of namespace com
#endif // PROTOCOL_H