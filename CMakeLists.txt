cmake_minimum_required(VERSION 3.17)
project(jumblesolver)

set(CMAKE_CXX_STANDARD 17)
SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread")

add_definitions(-lcurses)

add_executable(jumblesolver main.cpp words.cpp words.h format.cpp format.h)