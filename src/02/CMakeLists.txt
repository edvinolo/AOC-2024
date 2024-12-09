add_library(lib_02 SHARED day_02.cpp)
target_link_libraries(lib_02 lib_utils)
target_compile_options(lib_02 INTERFACE -O3 -g -Wall)
target_include_directories(lib_02 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})