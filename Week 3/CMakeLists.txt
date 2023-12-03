cmake_minimum_required(VERSION 3.26)
project(Week_3)

set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Week_3 src/main.cpp
        src/util.cpp
        src/util.h)
