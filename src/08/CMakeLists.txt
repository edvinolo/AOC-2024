add_library(lib_08 SHARED day_08.cpp)
target_link_libraries(lib_08 lib_utils)
target_compile_options(lib_08 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_08 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})