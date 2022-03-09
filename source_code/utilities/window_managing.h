#pragma once
#include<cstdio>
#include<iostream>


double window_size_x, window_size_y;

void window_resized(GLFWwindow* window, int width, int height) {
    window_size_x = width;
    window_size_y = height;
}

