cmake_minimum_required(VERSION 2.6)
project(cube)

find_package(OpenGL REQUIRED)

add_executable(cube src/main.c)
