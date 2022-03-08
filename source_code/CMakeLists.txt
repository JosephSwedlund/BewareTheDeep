cmake_minimum_required(VERSION 3.18.4)

project(BewareTheDeep_00.0.0.2)

add_executable(${PROJECT_NAME} main.cpp utilities/input_handling.h libs/glad.c)

target_link_libraries(${PROJECT_NAME} GL dl glfw)
