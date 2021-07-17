/***********************
  File Name   :   InputManager.h
  Description :
  Author      :   Ethan WT Griffin
  Mail        :   Ethan.WTGriffin@gmail.com
********************/
#pragma once
#include <GLFW/glfw3.h>
#include <vector>
#include <stdio.h>

#include "Event.h"

class KeyInput
{
public:
	KeyInput() { }
	~KeyInput() { }

	// Functions
	void AddListener(Event* action);
	void RemoveListener(Event* action);
	void Fire(GLFWwindow* _window, int _action);

private:
	// Variables
	typedef std::vector<Event*> ActionsArray;
	ActionsArray actions;
};

class InputManager
{
	//******************Singleton******************
public:
	static InputManager& GetInstance()
	{
		static InputManager instance;
		return instance;
	}
	InputManager(InputManager const&) = delete;
	void operator= (InputManager const&) = delete;

private:
	InputManager() {};
	~InputManager() {};
	//*********************************************

public:
	// Functions
	void Init(GLFWwindow* _window);
	void AddInput(int _key, Event* action);
	void RemoveInput(int _key, Event* action);
	
private:
	// Functions
	static void MouseCallback(GLFWwindow* _window, double _xpos, double _ypos);
	static void ScrollCallback(GLFWwindow* _window, double _xoffset, double _yoffset);
	static void KeyCallback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods);
	
	// Variables
	static std::vector<KeyInput*> m_keyInputs;
};