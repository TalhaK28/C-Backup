cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp Scheduler.cpp Scheduler.h Server.cpp Server.h Sensor.cpp Sensor.h ISensor.h)
