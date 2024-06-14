cmake_minimum_required(VERSION 3.27)
project(TAD_Matrice)

set(CMAKE_CXX_STANDARD 23)

add_executable(TAD_Matrice main.cpp
        Matrice.cpp
        Matrice.h
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)
