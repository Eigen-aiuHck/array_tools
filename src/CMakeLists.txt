add_library(
  Array_Tools STATIC
  array_tools/endian_convertion.cpp
  ${PROJECT_SOURCE_DIR}/include/array_tools/endian_convertion.hpp
  array_tools/fstream_vector.cpp
  ${PROJECT_SOURCE_DIR}/include/array_tools/fstream_vector.hpp
  array_tools/vector_u8_reinterpret_cast.cpp
  ${PROJECT_SOURCE_DIR}/include/array_tools/vector_u8_reinterpret_cast.hpp)

target_include_directories(Array_Tools PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_definitions(Array_Tools PUBLIC Array_Tools_PUBLIC)
target_compile_definitions(Array_Tools PRIVATE Array_Tools_PRIVATE)

target_compile_features(Array_Tools PRIVATE cxx_std_20)
target_compile_features(Array_Tools PUBLIC cxx_std_17)
target_compile_options(Array_Tools PRIVATE -lc++fs)
