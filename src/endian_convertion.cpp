#include "endian_convertion.hpp"

#include <bit>
#include <cstdint>
#include <vector>

namespace binary_tools {
namespace conv_endian {
std::vector<uint8_t> static_conv_endian(std::vector<uint8_t> const &src) {
  return std::vector<uint8_t>(src.rbegin(), src.rend());
}

std::vector<uint8_t> dynamic_conv_endian(std::endian dst_endian,
                                         std::vector<uint8_t> const &src) {
  return if_ret(std::endian::native != dst_endian, static_conv_endian(src),
                src);
}
} // namespace conv_endian
} // namespace binary_tools