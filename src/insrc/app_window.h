#pragma once
#include <vector>
#include "../outsrc/GLFW/glfw3.h"

struct ScreenSize{
	int width=0,hight=0;
};

// struct ImVec2
// {
//     float                                   x, y;
//     ImVec2()                                { x = y = 0.0f; }
//     ImVec2(float _x, float _y)              { x = _x; y = _y; }
//     float  operator[] (size_t idx) const    { IM_ASSERT(idx <= 1); return (&x)[idx]; }    // We very rarely use this [] operator, the assert overhead is fine.
//     float& operator[] (size_t idx)          { IM_ASSERT(idx <= 1); return (&x)[idx]; }    // We very rarely use this [] operator, the assert overhead is fine.
// };


class App_Window {
public:
	App_Window(const char* window_name,int width, int height, GLFWwindow* srd_window = NULL);
	virtual ~App_Window();

	static std::vector<App_Window*> wins32;
	virtual void OnWindowAwake();
	virtual void OnUpdate();
	virtual void OnInput();

	// Default raw Quad drawn on the full window
	// set colors of
	void SetBackgroundColor(float red, float green, float blue);
	//set window textuer, id is a gpu uploaded texture id. use LoadImageToGPU(Image im)..
	//void Set_texture_id(Image* im);

	inline int get_width()				  const { return width;}
	inline int get_height()				  const { return height;}
	inline ScreenSize get_screenSize()		  const { return screenSize;}
	inline GLFWwindow* get_window()		  const { return window;}
	inline const char* get_window_name()  const { return windowName;}
	inline bool IsWindowOpen()					{ return !glfwWindowShouldClose(window); }
	inline bool IsWindowVisible()               { int a; glfwGetWindowSize(window,&a,&a); return a;}
private:
	//Image* bg_image;
	float background_col[4];
	int width, height;
	ScreenSize screenSize;
	const char* windowName;
protected:
	GLFWwindow* window = nullptr;
};