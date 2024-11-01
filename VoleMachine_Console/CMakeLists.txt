cmake_minimum_required(VERSION 3.26)
project(VoleMachine)

set(CMAKE_CXX_STANDARD 17)

add_executable(VoleMachine 
	main.cpp
        Machine.cpp
        Registers.cpp
        ALU.cpp
        CPU.cpp
        Memory.cpp
        Converters.cpp
        ProgramCounter.cpp
        CU.cpp)
