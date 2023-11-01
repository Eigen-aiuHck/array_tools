#include "array_tools/endian_convertion.hpp"

#include <bit>
#include <cstdint>
#include <exception>
#include <vector>

namespace binary_tools {
namespace conv_endian {
template <>
std::vector<uint8_t> static_conv_endian(std::vector<uint8_t> const &src) {
  return std::vector<uint8_t>(src.rbegin(), src.rend());
}

std::vector<uint8_t> static_conv_endian(std::vector<uint8_t> const &src,
                                        int32_t const place,
                                        int32_t const size) {
  if ((place + size) > src.size()) {
    // error
    throw std::runtime_error("(place + size) size bigger than src.size()!! : "
                             "binaly_tools::conv_endian::static_conv_endian");
    return {};
  }
  return std::vector<uint8_t>((src.rend() - place) - size, src.rend() - place);
}

template <>
std::vector<uint8_t> dynamic_conv_endian(std::endian dst_endian,
                                         std::vector<uint8_t> const &src) {
  return if_ret(std::endian::native != dst_endian, static_conv_endian(src),
                src);
}
std::vector<uint8_t> dynamic_conv_endian(std::endian dst_endian,
                                         std::vector<uint8_t> const &src,
                                         int32_t const place,
                                         int32_t const size) {
  return if_ret(std::endian::native != dst_endian,
                static_conv_endian(src, place, size), src);
}
} // namespace conv_endian
} // namespace binary_tools