cmake_minimum_required(VERSION 3.0)

project(aoc2021)

set(CMAKE_CXX_FLAGS "-std=c++11  -Wall -Werror -g")

add_executable(day2 day2.cpp)
add_test(day2 day2)