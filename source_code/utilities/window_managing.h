#pragma once
#include<cstdio>
#include<iostream>
#include<glad/glad.h>
#include"../config.h"

double window_size_x = 600, window_size_y = 600;
bool fullscreen = false;


GLFWwindow* window_init_and_create(){
    if(!glfwInit()) {
        return nullptr;
    }

    GLFWwindow* window = glfwCreateWindow(window_size_x, window_size_y, CONFIG_GAME_NAME, glfwGetPrimaryMonitor(), nullptr);

    glfwMakeContextCurrent(window);

    return window;
}

void window_update_fullscreen(GLFWwindow* window) {
    std::cout << fullscreen << '\n';
    if(fullscreen) {
        glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, window_size_x, window_size_y, CONFIG_REFRESH_RATE);
        std::cout << "now big\n";
    } 
    else  {
        glfwSetWindowMonitor(window, nullptr, 200, 200, window_size_x, window_size_y, CONFIG_REFRESH_RATE);
        std::cout << "now small\n";
    }
}

void window_resized(GLFWwindow* window, int width, int height) {
    window_size_x = width;
    window_size_y = height;
    glViewport(0, 0, window_size_x, window_size_y);
}


