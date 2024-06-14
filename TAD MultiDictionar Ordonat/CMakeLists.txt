cmake_minimum_required(VERSION 3.28)
project(TAD_MultiDictionar_Ordonat)

set(CMAKE_CXX_STANDARD 26)

add_executable(TAD_MultiDictionar_Ordonat main.cpp
                MDO.cpp
                MDO.h
                IteratorMDO.cpp
                IteratorMDO.h
                TestScurt.cpp
                TestScurt.h
                TestExtins.cpp
                TestExtins.h)
