#pragma once
#include <cstdint>
#include <iterator>
#include <stdexcept>
#include <vector>

namespace binary_tools {
namespace conv_typename {
template <typename T> std::vector<uint8_t> to_vector_u8(T const src) {
  uint8_t const(&buffer)[sizeof(T)] =
      *reinterpret_cast<uint8_t const(*)[sizeof(T)]>(&src);
  return std::vector<uint8_t>(std::begin(buffer), std::end(buffer));
}

template <typename T> T from_vector_u8(std::vector<uint8_t> const &src) {
  if (src.size() != sizeof(T)) {
    std::runtime_error(
        "ERR: array size does not match size that you ordered typename!!");
    return T{};
  }
  T const *buffer = reinterpret_cast<T const *>(src.data());
  return *buffer;
}

template <typename T>
T from_vector_u8(std::vector<uint8_t> const &src, int32_t const place) {
  if ((src.size() - place) < sizeof(T)) {
    std::runtime_error(
        "ERR: array size does not match size that you ordered typename!!");
    return T{};
  }
  T const *buffer = reinterpret_cast<T const *>(src.data() + place);
  return *buffer;
}
} // namespace conv_typename
} // namespace binary_tools