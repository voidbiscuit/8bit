cmake_minimum_required(VERSION 3.12)
project(8bit)

set(CMAKE_CXX_STANDARD 14)

add_executable(8bit main.cpp src/machine/IO/output.cpp src/machine/IO/output.h src/machine/RAM/RAM.cpp src/machine/RAM/RAM.h src/machine/machine.cpp src/machine/machine.h src/machine/Processor/CPU.cpp src/machine/Processor/CPU.h src/machine/Processor/instructions/instructions.cpp src/machine/Processor/instructions/instructions.h test.cpp test.h)