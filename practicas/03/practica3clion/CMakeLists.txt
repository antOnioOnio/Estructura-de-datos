cmake_minimum_required(VERSION 3.6)
project(practica3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES pila_max.h cola.h main.cpp)
add_executable(practica3 ${SOURCE_FILES})