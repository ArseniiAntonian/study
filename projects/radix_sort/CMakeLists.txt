cmake_minimum_required(VERSION 3.26)
project(radix_sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(radix_sort main.cpp
        radix_sort.cpp
        radix_sort.hpp)
