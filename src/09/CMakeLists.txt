add_library(lib_09 SHARED day_09.cpp)
target_link_libraries(lib_09 lib_utils)
target_compile_options(lib_09 INTERFACE -O3 -g -Wall)
target_include_directories(lib_09 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})