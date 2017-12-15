cmake_minimum_required(VERSION 3.8)
project(annuaire)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c linkedList.h linkedList.c utilities.h utilities.c)
add_executable(annuaire ${SOURCE_FILES} linkedList.h)