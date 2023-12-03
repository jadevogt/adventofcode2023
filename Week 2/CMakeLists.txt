cmake_minimum_required(VERSION 3.13)  # CMake version check
project(daytwo)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 20)            # Enable c++20 standard

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)


# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES src/daytwo.cpp src/game.cpp)


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(daytwo ${SOURCE_FILES})
