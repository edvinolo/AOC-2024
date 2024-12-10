add_library(lib_01 SHARED day_01.cpp)
target_link_libraries(lib_01 lib_utils)
target_compile_options(lib_01 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_01 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})