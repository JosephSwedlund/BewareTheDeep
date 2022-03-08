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

int main() {
    if(!glfwInit()){
		return -1;
	}
    
    bool fullscreen = false;
	const short WINDOW_HEIGHT = 700;
	const short WINDOW_WIDTH = 900;
    const char* WINDOW_TITLE = "BewareTheDeep";
 
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, glfwGetPrimaryMonitor(), nullptr);
    

    if(!fullscreen) {
         glfwSetWindowMonitor(window, nullptr, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 60);
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetKeyCallback(window, key_action);
    glfwSetCursorPosCallback(window, cursor_position_changed);
    glfwSetMouseButtonCallback(window, mouse_button_clicked);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);



while(!glfwWindowShouldClose(window)){
        
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

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}




