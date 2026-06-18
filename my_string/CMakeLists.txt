cmake_minimum_required(VERSION 3.10)
project(MyString CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_string
    src/main.cpp
    src/MyString.cpp
)

target_include_directories(my_string PUBLIC include)