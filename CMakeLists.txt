cmake_minimum_required(VERSION 3.10)
project(Renderer VERSION 1.0)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(Renderer main.cpp renderer.cpp)
target_link_libraries(Renderer ${SDL2_LIBRARIES})