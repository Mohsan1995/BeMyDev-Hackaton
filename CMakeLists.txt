cmake_minimum_required(VERSION 3.6)
project(BeMyDev)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Step.cpp header/Step.h src/Team.cpp header/Team.h src/Hackaton.cpp header/Hackaton.h)
add_executable(BeMyDev ${SOURCE_FILES})