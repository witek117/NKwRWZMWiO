cmake_minimum_required(VERSION 3.1)
set(NAME TASK12)
project(${NAME} CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -static")

file(GLOB_RECURSE SOURCES
        "src/*.c"
        "src/*.cpp"
        "inc/*.h"
        "inc/*.hpp"
        )

add_executable(${NAME} ${SOURCES})

target_include_directories(${NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)