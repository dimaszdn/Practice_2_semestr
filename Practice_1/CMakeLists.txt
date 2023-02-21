cmake_minimum_required(VERSION 3.24)
project(Practice_1)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Practice_1 main.cpp inc/Scrambler.h)
