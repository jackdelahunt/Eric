cmake_minimum_required(VERSION 3.20)
project(Eric)

set(CMAKE_CXX_STANDARD 20)

add_executable(Eric
        main.cpp
        vm/op_code.h
        vm/virtual_machine.h vm/virtual_machine.cpp
        vm/debug.h

        generator/generator.h generator/generator.cpp
        generator/instruction.h generator/instruction.cpp
        )
