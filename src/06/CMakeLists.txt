add_library(lib_06 SHARED day_06.cpp)
target_link_libraries(lib_06 lib_utils)
target_compile_options(lib_06 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_06 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})