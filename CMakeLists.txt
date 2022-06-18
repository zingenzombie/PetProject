cmake_minimum_required(VERSION 3.21)
project(PetProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(PetProject main.cpp LinkedList.h Pet.h Pet.cpp)
