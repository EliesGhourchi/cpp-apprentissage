cmake_minimum_required(VERSION 3.20)

project(loading LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(loading main.cpp)

if(MSVC)
    target_compile_options(loading PRIVATE /W4)
else()
    target_compile_options(loading PRIVATE -Wall -Wextra)
endif()

