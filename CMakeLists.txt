cmake_minimum_required(VERSION 4.1)
project(grep_clone)

set(CMAKE_CXX_STANDARD 20)

add_executable(grep_clone src/main.cpp
        src/Grep.cpp
        src/FileReader.cpp
        src/Output.cpp)

target_include_directories(grep_clone PRIVATE include)

set_target_properties(grep_clone PROPERTIES OUTPUT_NAME "cgrep")
