cmake_minimum_required(VERSION 3.6)
project(BeMyDev)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Step.cpp Step.h Team.cpp Team.h Hackaton.cpp Hackaton.h)
add_executable(BeMyDev ${SOURCE_FILES})