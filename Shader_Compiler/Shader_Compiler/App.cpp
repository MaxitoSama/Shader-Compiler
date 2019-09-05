#include "App.h"


bool App::Init()
{
	/* Initialize the library */
	if (!glfwInit())
		return false;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1000, 1000, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/*Seting the pointer of the static callback funtion In this case The Engine*/
	glfwSetWindowUserPointer(window, (void*)this);
	
	/*Seting the callback funtion for the inputs*/
	glfwSetKeyCallback(window,key_callback);

	/* We can init glew here because the contest is already created*/
	if (glewInit() != GLEW_OK)
	{
		cout << "Problem: glewInit failed, something is seriously wrong." << endl;
	}
	else
	{
		cout << glGetString(GL_VERSION) << endl;
	}

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	////ImGui::StyleColorsClassic();

	// Setup Platform/Renderer bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL2_Init();

	return true;
}

bool App::PreUpdate()
{
	return true;
}

bool App::Update()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
	glVertex2d(-0.5f, -0.5f);
	glVertex2d(0.5f, -0.5f);
	glVertex2d(0.5f, 0.5f);
	
	glVertex2d(-0.5f, -0.5f);
	glVertex2d(0.5f, 0.5f);
	glVertex2d(-0.5f, 0.5f);
	glEnd();

	Draw_UI();

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	/*Key Events*/

	return !close_engine;
}

bool App::PostUpdate()
{
	return true;
}

bool App::CleanUp()
{
	glfwSetWindowShouldClose(window, GLFW_TRUE);
	glfwTerminate();
	return true;
}

void App::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	App* datas;
	datas = (App*)glfwGetWindowUserPointer(window);

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		datas->close_engine = true;
	}
}

void App::Draw_UI()
{
	bool show_demo_window = true;

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow(&show_demo_window);

	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}
