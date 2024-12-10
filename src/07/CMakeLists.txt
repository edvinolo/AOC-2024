add_library(lib_07 SHARED day_07.cpp)
target_link_libraries(lib_07 lib_utils)
target_compile_options(lib_07 INTERFACE -O3 -g -Wall -march=native)
target_include_directories(lib_07 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})