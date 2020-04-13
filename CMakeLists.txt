# cmake_minimum_required(VERSION <specify CMake version here>)
project(prog)

set(CMAKE_CXX_STANDARD 17)

add_executable(prog main.cpp autocompleter.cpp user_console.cpp word_storage.cpp)