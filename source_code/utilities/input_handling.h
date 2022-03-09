#pragma once
#include"../config.h"
#include<cstdio>
#include<map>
#include<string>
#include<string_view>
#include<iostream>
#include"window_managing.h"

std::map<int, bool> key_is_pressed {};
std::map<int, bool> key_is_released {};
std::map<int, bool> key_is_held {};

std::map<int, bool> mouse_button_is_pressed {};
std::map<int, bool> mouse_button_is_released {};
std::map<int, bool> mouse_button_is_held {};

double normalized_mouse_cursor_x;
double normalized_mouse_cursor_y;
double mouse_cursor_x, mouse_cursor_y;

void key_action(GLFWwindow* window, int key, int scancode, int action, int mods) {
    
    #if debug_key_pressed
        if(action == GLFW_PRESS) std::cout << key << " pressed.\n";
    #endif
    #if debug_key_released
        if(action == GLFW_RELEASE) std::cout << key << " released.\n";
    #endif
    #if debug_key_held
        if(((action == GLFW_PRESS) || (key_is_held[key])) && (action != GLFW_RELEASE)) std::cout << key << " held.\n";
   #endif

    // Toggle Fullscreen with key 80 (P)
    if(action = GLFW_PRESS && action != GLFW_RELEASE  && key == 80) {
        fullscreen = !fullscreen;
        window_update_fullscreen(window);
    }

    key_is_pressed[key] = (action == GLFW_PRESS); 
    key_is_released[key] = (action == GLFW_RELEASE);
    key_is_held[key] = ( ((action == GLFW_PRESS) || (key_is_held[key])) && (action != GLFW_RELEASE));
}

void cursor_position_changed(GLFWwindow* window, double x_position, double y_position) {

    
    #if debug_mouse_movement
        std::cout << "x: " << x_position << "    " << "y: " << y_position << "\n";
    #endif
    mouse_cursor_x = x_position; 
    mouse_cursor_y = y_position;
    normalized_mouse_cursor_x = ((mouse_cursor_x / window_size_x)-0.5)*2;                
    normalized_mouse_cursor_y = ((-1*mouse_cursor_y / window_size_y)+0.5)*2;                


}

void mouse_button_clicked(GLFWwindow* window, int button, int action, int mods) {
//    std::cout << "Mouse Button "; 
///    if(action == GLFW_PRESS) std::cout << "pressed.\n";
//    if(action == GLFW_RELEASE) std::cout << "released.\n";
//    if(((action == GLFW_PRESS) || (mouse_button_is_held[button])) && (action != GLFW_RELEASE)) std::cout << "held.\n";
    mouse_button_is_pressed[button] = (action == GLFW_PRESS);
    mouse_button_is_released[button] = (action == GLFW_RELEASE);
    mouse_button_is_held[button] = ( ((action == GLFW_PRESS) || (mouse_button_is_held[button])) && (action != GLFW_RELEASE));
}


