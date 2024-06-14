cmake_minimum_required(VERSION 3.27)
project(TAD_Multime)

set(CMAKE_CXX_STANDARD 23)

add_executable(TAD_Multime main.cpp
        Multime.cpp
        Multime.h
        IteratorMultime.cpp
        IteratorMultime.h
        TestScurt.cpp
        TestScurt.h
        TestExtins.cpp
        TestExtins.h)
