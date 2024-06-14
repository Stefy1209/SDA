cmake_minimum_required(VERSION 3.28)
project(TAD_DO)

set(CMAKE_CXX_STANDARD 17)

add_executable(TAD_DO main.cpp
        DO.cpp
        DO.h
        Iterator.cpp
        Iterator.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
