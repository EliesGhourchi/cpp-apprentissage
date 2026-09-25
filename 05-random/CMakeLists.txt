cmake_minimum_required(VERSION 3.20)

project(random LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(random main.cpp)

if(MSVC)
    target_compile_options(random PRIVATE /W4)
else()
    target_compile_options(random PRIVATE -Wall -Wextra)
endif()

