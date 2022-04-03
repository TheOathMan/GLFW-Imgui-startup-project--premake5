#include "../outsrc/imgui/imgui.h"
#include "../outsrc/GLFW/glfw3.h"
#include "app_window.h"

// Runs once before the creation of the window
void AppAwake(App_Window* window)
{

}


// Runs at the start of the app
void AppStart(App_Window* window)
{

}

// Runs everyfram
void AppUpdate(App_Window* window, float deltaTime)
{
    ImGui::ShowDemoWindow();
}


// Runs once when app is closed
void AppClosed(App_Window* window)
{

}
