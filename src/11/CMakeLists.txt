add_library(lib_11 SHARED day_11.cpp)
target_link_libraries(lib_11 lib_utils)
target_compile_options(lib_11 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_11 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})