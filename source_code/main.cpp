/* <This is the source code to BewareTheDeep a voxel based game inspired by Minecraft, Dwarf Fortress, and the original Legend Of Zelda>
    Copyright (C) <2022>  <Joseph Victor Swedlund>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"utilities/input_handling.h"
#include"utilities/window_managing.h"
#include"libs/glm/glm.hpp"
#include"systems/cube.h"

int main() {
    if(!glfwInit()){
		return -1;
	}
    
    bool fullscreen = false;
    const char* WINDOW_TITLE = "BewareTheDeep";
    
    GLFWwindow* window = glfwCreateWindow(window_size_x, window_size_y, WINDOW_TITLE, glfwGetPrimaryMonitor(), nullptr);
    
    // Checking for fullscreen
    if(!fullscreen) {
         glfwSetWindowMonitor(window, nullptr, 0, 0, window_size_x, window_size_y, 60);
    }

    
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    
    // Activating user input
    glfwSetKeyCallback(window, key_action);
    glfwSetCursorPosCallback(window, cursor_position_changed);
    glfwSetMouseButtonCallback(window, mouse_button_clicked);
    glfwSetWindowSizeCallback(window, window_resized);
    
    // Setting up glViewport
    glViewport(0, 0, window_size_x, window_size_y);


    //Creating Buffers
    uint32_t vao;
    glGenBuffers(1, &vao);
    glBindBuffer(GL_ARRAY_BUFFER, vao);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*9, &rectangle_data[0], GL_DYNAMIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*3, (void*)0);
    glEnableVertexAttribArray(0);


    while(!glfwWindowShouldClose(window)){

        rectangle_data[0] = normalized_mouse_cursor_x;        
        rectangle_data[1] = normalized_mouse_cursor_y;        
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*9, &rectangle_data[0], GL_DYNAMIC_DRAW);
        
        if(key_is_held[GLFW_KEY_W]){
            glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
            if(mouse_button_is_held[GLFW_MOUSE_BUTTON_1]) {
                glClearColor(0.0f, 0.0f, 0.0f, 1.0f);    
            }
        }
        else if(mouse_button_is_held[GLFW_MOUSE_BUTTON_2]) {
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        }
        else {
            glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
        }
        
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}




