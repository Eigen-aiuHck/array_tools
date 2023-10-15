#pragma once
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <optional>
#include <vector>

namespace binary_tools {
template <typename T>
bool ifstream_vector(std::filesystem::path const &path, std::vector<T> &dst) {
  std::ifstream file(path, std::ios_base::binary | std::ios::ate);
  if (!file.is_open()) {
    std::cout << "Can not open file!!\nFile name: "
              << path.generic_string<char>() << std::endl;
    dst = {};
    return false;
  }

  size_t const fileSize =
      (static_cast<size_t>(file.tellg()) + sizeof(T) - 1) / sizeof(T);
  dst.resize(fileSize);

  file.seekg(0);
  file.read(reinterpret_cast<char *>(dst.data()), fileSize);

  file.close();
  return true;
}

template <typename T>
bool ofstream_vector(std::filesystem::path const &path,
                     std::vector<T> const &src) {
  std::ofstream file(path, std::ios_base::binary);
  if (!file.is_open()) {
    std::cout << "Can not open file!!\nFile name: "
              << path.generic_string<char>() << std::endl;
    return false;
  }
  size_t src_size_byte = sizeof(T) * src.size();

  file.clear();
  file.write(reinterpret_cast<char const *>(src.data()), src_size_byte);

  file.close();
  return true;
}
} // namespace binary_tools