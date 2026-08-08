cmake_minimum_required(VERSION 4.2)
project(RubiksCube)

set(CMAKE_CXX_STANDARD 23)

add_executable(RubiksCube main.cpp
        RubiksCube.h
        RubiksCube3DArray.cpp
        RubiksCube.cpp
        dfsSolver.cpp
        IDDFSsolver.cpp
        bfsSolver.cpp)
