add_library(lib_03 SHARED day_03.cpp)
target_link_libraries(lib_03 lib_utils)
target_compile_options(lib_03 INTERFACE -O3 -g -Wall)
target_include_directories(lib_03 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})