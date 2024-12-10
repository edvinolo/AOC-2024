cmake_minimum_required(VERSION 3.30.2)
project(AOC-2024 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(src)

add_executable(AOC-2024 main.cpp src/lib_aoc.hpp)
target_compile_options(AOC-2024 PUBLIC -O3 -g -Wall)
target_link_options(AOC-2024 PUBLIC -O3 -g -Wall -fsanitize=address)
target_link_libraries(AOC-2024 PUBLIC lib_AOC-2024)
