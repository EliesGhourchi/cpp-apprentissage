cmake_minimum_required(VERSION 3.20)

project(characters  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(characters main.cpp)

if(MSVC)
    target_compile_options(characters PRIVATE /W4)
else()
    target_compile_options(characters PRIVATE -Wall -Wextra)
endif()
