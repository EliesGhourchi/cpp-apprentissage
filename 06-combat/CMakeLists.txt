cmake_minimum_required(VERSION 3.20)

project(combat  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(combat main.cpp)

if(MSVC)
    target_compile_options(combat PRIVATE /W4)
else()
    target_compile_options(combat PRIVATE -Wall -Wextra)
endif()
