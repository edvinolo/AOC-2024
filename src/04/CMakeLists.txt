add_library(lib_04 SHARED day_04.cpp)
target_link_libraries(lib_04 lib_utils)
target_compile_options(lib_04 INTERFACE -O3 -g -Wall)
target_include_directories(lib_04 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})