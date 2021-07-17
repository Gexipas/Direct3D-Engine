/***********************
  File Name   :   main.cpp
  Description :
  Author      :   Ethan WT Griffin
  Mail        :   Ethan.WTGriffin@gmail.com
********************/
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include "InputManager.h"

int main()
{
	const UINT windowWidth = 1280;
	const UINT windowHeight = 720;

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "D3D12 Project", nullptr, nullptr);

	InputManager::GetInstance().Init(window);

	Event* callback = new EventFunction([](GLFWwindow* _window, int _action) {if (_action == GLFW_PRESS)glfwSetWindowShouldClose(_window, true); });
	InputManager::GetInstance().AddInput(GLFW_KEY_ESCAPE, callback);
	//InputManager::GetInstance().RemoveInput(GLFW_KEY_ESCAPE, callback);

	while (!glfwWindowShouldClose(window))
	{			
		
		glfwPollEvents();
	}

	return 0;
}