cmake_minimum_required(VERSION 3.8)
project(EXAMEN)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        kvdb.c kvh.h getSet.c)

add_executable(EXAMEN ${SOURCE_FILES})