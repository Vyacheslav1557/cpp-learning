cmake_minimum_required(VERSION 3.26)
project(untitled2)

set(CMAKE_CXX_STANDARD 23)

add_executable(untitled2 main.cpp
        src/dynamic-array/DynamicArray.cpp
        src/dynamic-array/DynamicArray.h
        src/secure-dynamic-array/SecureDynamicArray.cpp
        src/secure-dynamic-array/SecureDynamicArray.h)
