cmake_minimum_required(VERSION 3.15)
project(NetTracker VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC ntcore)
target_include_directories(main PRIVATE core)
