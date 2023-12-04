cmake_minimum_required(VERSION 3.26)
project(Day4)

set(CMAKE_CXX_STANDARD 23)

add_executable(Day4 src/main.cpp
        src/util.cpp
        src/util.h)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
