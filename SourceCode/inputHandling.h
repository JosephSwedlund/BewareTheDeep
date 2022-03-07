#pragma once
#include<cstdio>
#include<map>
#include<string>
#include<string_view>
#include<iostream>


std::map<int, bool> key_is_pressed {};
std::map<int, bool> key_is_released {};
std::map<int, bool> key_is_held {};

std::map<int, bool> mouse_button_is_pressed {};
std::map<int, bool> mouse_button_is_released {};
std::map<int, bool> mouse_button_is_held {};

double mouse_cursor_x, mouse_cursor_y;

void key_action(GLFWwindow* window, int key, int scancode, int action, int mods) {
    std::cout << "Key "; 
    if(action == GLFW_PRESS) std::cout << "pressed.\n";
    if(action == GLFW_RELEASE) std::cout << "released.\n";
    if(((action == GLFW_PRESS) || (key_is_held[key])) && (action != GLFW_RELEASE)) std::cout << "held.\n";
    key_is_pressed[key] = (action == GLFW_PRESS); 
    key_is_released[key] = (action == GLFW_RELEASE);
    key_is_held[key] = ( ((action == GLFW_PRESS) || (key_is_held[key])) && (action != GLFW_RELEASE));
}

void cursor_position_changed(GLFWwindow* window, double x_position, double y_position) {
    std::cout << "x: " << x_position << "    " << "y: " << y_position << "\n";
    mouse_cursor_x = x_position; 
    mouse_cursor_y = y_position;
}

void mouse_button_clicked(GLFWwindow* window, int button, int action, int mods) {
    std::cout << "Mouse Button "; 
    if(action == GLFW_PRESS) std::cout << "pressed.\n";
    if(action == GLFW_RELEASE) std::cout << "released.\n";
    if(((action == GLFW_PRESS) || (mouse_button_is_held[button])) && (action != GLFW_RELEASE)) std::cout << "held.\n";
    mouse_button_is_pressed[button] = (action == GLFW_PRESS);
    mouse_button_is_released[button] = (action == GLFW_RELEASE);
    mouse_button_is_held[button] = ( ((action == GLFW_PRESS) || (mouse_button_is_held[button])) && (action != GLFW_RELEASE));
}


