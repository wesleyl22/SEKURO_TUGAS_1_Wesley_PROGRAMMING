cmake_minimum_required(VERSION 3.10)
project(robot)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(include)

add_executable(robot_app 
    src/main.cpp 
    src/robot.cpp 
    src/robotair.cpp
)