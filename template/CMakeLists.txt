cmake_minimum_required(VERSION 3.26)
project(template)

set(CMAKE_CXX_STANDARD 23)

add_executable(template src/main.cpp
        src/util.cpp
        src/util.h)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
