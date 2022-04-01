#include "app_window.h"
#include <stdio.h>

std::vector<App_Window*> App_Window::wins32;

App_Window::App_Window(const char* window_name, int width, int height, GLFWwindow* srd_window):
    windowName(window_name),
	width(width),
	height(height)
{
   // glfwSetErrorCallback(glfw_error_callback);
    window = glfwCreateWindow(width, height, windowName, NULL, srd_window);

    if (!window) {
		glfwTerminate();
        perror ("Window failed at initialization");
		exit(EXIT_FAILURE);
	}

    glfwMakeContextCurrent(window);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    screenSize.width = mode->width, screenSize.hight = mode->height;
    SetBackgroundColor(0.7f,0.7f,0.7f);
}

App_Window:: ~App_Window() 
{
    glfwDestroyWindow(window);
}

void App_Window::OnWindowAwake()
{

}


void App_Window::OnUpdate()
{
    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(background_col[0],background_col[1],background_col[2], 1.0f);
}

void App_Window::OnInput()
{

}

void App_Window::SetBackgroundColor(float red, float green, float blue)
{
    background_col[0] = red;
    background_col[1] = green;
    background_col[2] = blue;

}

// draw textured quad opengl
void RawQuadTexture(int id)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, id);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-1.0f, 1.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glEnd();

}
