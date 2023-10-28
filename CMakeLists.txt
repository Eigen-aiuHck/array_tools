cmake_minimum_required(VERSION 3.15...3.26)

project(
  Array_Tools
  VERSION 1.0
  DESCRIPTION "binary data utilitys for C++."
  LANGUAGES CXX)

add_subdirectory(src)

set(ARRAY_TOOLS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
