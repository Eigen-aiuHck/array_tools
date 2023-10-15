#pragma once
#include "vector_u8_reinterpret_cast.hpp"

#include <cstdint>
#include <endian.h>
#include <iostream>
#include <vector>

#include "extention_defines/ext_if"
namespace binary_tools {
namespace conv_endian {
std::vector<uint8_t> static_conv_endian(std::vector<uint8_t> const &src);
std::vector<uint8_t> dynamic_conv_endian(std::endian dst_endian,
                                         std::vector<uint8_t> const &src);

template <typename T> T static_conv_endian(T src) {
  auto const buf_src = conv_typename::to_vector_u8(src);
  std::vector<uint8_t> buf_dst(buf_src.end(), buf_src.begin());
  return conv_typename::from_vector_u8<T>(buf_dst);
}
template <typename T> T dynamic_conv_endian(std::endian dst_endian, T &src) {
  return if_ret(std::endian::native != dst_endian, static_conv_endian(src),
                src);
}
} // namespace conv_endian
} // namespace binary_tools