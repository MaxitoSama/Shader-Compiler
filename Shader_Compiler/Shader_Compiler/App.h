#ifndef __APP_H__
#define __APP_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl2.h"

using namespace std;

class 	GLFWwindow;


class App
{
public:
	App() {};
	~App() {};

	bool Init();
	bool PreUpdate();
	bool Update();
	bool PostUpdate();
	bool CleanUp();

	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void Draw_UI();

public:

	bool close_engine = false;
	GLFWwindow* window;

};

#endif // !__APP_H__
