cmake_minimum_required(VERSION 3.26)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp
        Array.cpp
        Array.h
        PlainInitArray.cpp
        PlainInitArray.h
        SimpleInitArray.cpp
        SimpleInitArray.h
        FolkloreInitArray.cpp
        FolkloreInitArray.h
        NavarroInitArray.cpp
        NavarroInitArray.h
)
