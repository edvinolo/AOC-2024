add_library(lib_05 SHARED day_05.cpp)
target_link_libraries(lib_05 lib_utils)
target_compile_options(lib_05 INTERFACE -O3 -g -Wall)
target_include_directories(lib_05 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})