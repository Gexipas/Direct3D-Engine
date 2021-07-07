/***********************
  File Name   :   main.cpp
  Description :
  Author      :   Ethan WT Griffin
  Mail        :   Ethan.WTGriffin@gmail.com
********************/
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>


int main()
{
	const UINT windowWidth = 1280;
	const UINT windowHeight = 720;

	glfwInit();

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "D3D12 Project", nullptr, nullptr);


	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);
		
		glfwPollEvents();
	}

	return 0;
}