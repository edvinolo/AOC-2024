add_library(lib_utils SHARED aoc_utils.cpp)
target_compile_options(lib_utils INTERFACE -O3 -g -Wall)
target_include_directories(lib_utils INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})