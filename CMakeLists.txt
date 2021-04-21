cmake_minimum_required(VERSION 3.19)
project(rubiks_project C)

set(CMAKE_C_STANDARD 11)

include_directories(headers)
include_directories(src)

add_executable(rubiks_project
        headers/rubiks.h
        src/main.c
        src/rubiks.c)
