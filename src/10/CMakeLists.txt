add_library(lib_10 SHARED day_10.cpp)
target_link_libraries(lib_10 lib_utils)
target_compile_options(lib_10 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_10 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})