#include "app_window.h" 
#include <stdio.h>
#include "../outsrc/imgui/imgui_impl_glfw.h"
#include "../outsrc/imgui/imgui_impl_opengl2.h"
#include "../outsrc/imgui/imgui_internal.h"

//thread_local ImGuiContext* MyImGuiTLS; // thread local context if need. ned to be activated from imconfig.h

void AppAwake(App_Window* window);
void AppStart(App_Window* window);
void AppUpdate(App_Window* window, float deltaTime);
void AppClosed(App_Window* window);

std::vector<App_Window*> App_Window::wins32;

App_Window::App_Window(const char* window_name, int width, int height, GLFWwindow* srd_window):
    windowName(window_name),
	width(width),
	height(height)
{
    AppAwake(this);

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

void App_Window::OnWindowAwake()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL2_Init();
    AppStart(this);
}



void App_Window::OnUpdate()
{
    glfwMakeContextCurrent(window);
    glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    //glfwSetWindowOpacity(window, 0.0f);

    //frame start.
    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();


    AppUpdate(this,ImGui::GetIO().DeltaTime);

    //frame end.
    ImGui::Render();
    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

void App_Window::OnInput()
{

}


App_Window:: ~App_Window() 
{
    glfwDestroyWindow(window);
    AppClosed(this);
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
