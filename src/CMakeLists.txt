add_library(
  binary_tools STATIC
  endian_convertion.cpp
  ${PROJECT_SOURCE_DIR}/include/endian_convertion.hpp
  fstream_vector.cpp
  ${PROJECT_SOURCE_DIR}/include/fstream_vector.hpp
  thread_manager.cpp
  ${PROJECT_SOURCE_DIR}/include/thread_manager.hpp
  vector_u8_reinterpret_cast.cpp
  ${PROJECT_SOURCE_DIR}/include/vector_u8_reinterpret_cast.hpp)

target_include_directories(binary_tools PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_definitions(binary_tools PUBLIC binary_tools_PUBLIC)
target_compile_definitions(binary_tools PRIVATE binary_tools_PRIVATE)

target_compile_features(binary_tools PRIVATE cxx_std_20)
target_compile_features(binary_tools PUBLIC cxx_std_17)
target_compile_options(binary_tools PRIVATE -lc++fs)
