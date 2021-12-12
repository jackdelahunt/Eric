cmake_minimum_required(VERSION 3.20)
project(Eric)

set(CMAKE_CXX_STANDARD 20)

add_executable(Eric main.cpp op_code.h operations.h operations.cpp c_array.h exception.h virtual_machine.h virtual_machine.cpp )
