#pragma once
#include<cstdio>
#include<iostream>
#include<glad/glad.h>

double window_size_x = 600, window_size_y = 600;

void window_resized(GLFWwindow* window, int width, int height) {
    window_size_x = width;
    window_size_y = height;
    glViewport(0, 0, window_size_x, window_size_y);
}

