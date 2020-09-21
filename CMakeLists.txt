
cmake_minimum_required(VERSION 2.8)

project(pi)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-std=c++11)
endif()

add_executable(pi main.cpp)

install(TARGETS pi RUNTIME DESTINATION bin)
