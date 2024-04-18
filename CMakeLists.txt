cmake_minimum_required(VERSION 3.20)
project(speller)

find_package(Nuspell)
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} Nuspell::nuspell)