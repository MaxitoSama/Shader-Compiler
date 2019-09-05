#include <stdio.h>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl2.h"

#include "..\\App.h"

using namespace std;

enum Engine_State {
	Init,
	PreUpdate,
	Update,
	PostUpdate,
	CleanUp
};

App* Engine = new App();

int main(void)
{
	Engine_State EngineState = Init;
	
	/* Loop until the user closes the window */
	while (EngineState!=CleanUp)
	{
		switch (EngineState)
		{
		case Init:
			if (Engine->Init())
			{
				EngineState = Update;
			}
			break;

		case Update:
			if (!Engine->Update())
			{
				Engine->CleanUp();
				EngineState = CleanUp;
			}
			break;
		}
	}
	return 0;
}

