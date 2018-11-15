cmake_minimum_required(VERSION 3.12)
project(BrainFuckVM)

set(CMAKE_CXX_STANDARD 14)

add_executable(bfm main.cpp Data.cpp Data.h Instruction.cpp Instruction.h Program.cpp Program.h BrainFuckVM.cpp BrainFuckVM.h)