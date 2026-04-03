cmake_minimum_required(VERSION 4.1)
project(grep_clone)

set(CMAKE_CXX_STANDARD 20)

add_executable(grep_clone src/main.cpp
        src/Grep.cpp
        src/FileReader.cpp
        include/Grep.h
        include/FileReader.h)

target_include_directories(grep_clone PRIVATE include)
