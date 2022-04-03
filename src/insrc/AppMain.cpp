#include "../outsrc/imgui/imgui.h"
#include "../outsrc/GLFW/glfw3.h"
#include "app_window.h"
#include <iostream>

// Runs once before the creation of the window
void AppAwake(App_Window* window){

}



void AppStart(App_Window* window){
    //glfwSetMouseButtonCallback(window->get_window(),[](GLFWwindow*,int a,int b,int c){});
    //glfwSetCursorPosCallback (window->get_window(),[](GLFWwindow*w,double,double){ });

}

// Runs everyfram
void AppUpdate(App_Window* window, float deltaTime){
    ImGui::ShowDemoWindow();

}


// Runs once when app is closed
void AppClosed(App_Window* window){

}