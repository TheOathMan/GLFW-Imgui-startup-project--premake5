#include "app_window.h"
#include <assert.h>


std::vector<App_Window*> App_Window::wins32;

App_Window::App_Window(const char* window_name, int width, int height, GLFWwindow* srd_window):
    windowName(window_name),
	width(width),
	height(height)
{
   // glfwSetErrorCallback(glfw_error_callback);
    window = glfwCreateWindow(width, height, windowName, NULL, srd_window);

    if (window == NULL)
        assert("There is no window or your GPU isn't working properly", true);

    glfwMakeContextCurrent(window);
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    screenSize.width = mode->width, screenSize.hight = mode->height;
}

App_Window:: ~App_Window() 
{
    glfwDestroyWindow(window);
}

void App_Window::OnWindowAwake()
{
    // Window Icon
    //Image GetIcon((pixel_uc*)_icon_data,icon_size,4);
    //GetIcon.overrideColors(COLOR_WHITE,COLOR_RED);
    //GLFWimage icons[1];
    //icons[0].pixels = GetIcon.Get_Data();
    //icons[0].width  = GetIcon.Get_Width();
    //icons[0].height = GetIcon.Get_Height();
    //glfwSetWindowIcon(window, 1, icons);
}


void App_Window::OnUpdate()
{
    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(background_col[0],background_col[1],background_col[2], 1.0f);
    //RawQuadTexture();
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
