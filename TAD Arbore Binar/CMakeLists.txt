cmake_minimum_required(VERSION 3.28)
project(TAD_Arbore_Binar)

set(CMAKE_CXX_STANDARD 17)

add_executable(TAD_Arbore_Binar main.cpp
        AB.h
        AB.cpp
        IteratorAB.cpp
        IteratorAB.h
        TestExtins.h
        TestScurt.h
        TestScurt.cpp
        TestExtins.cpp)
