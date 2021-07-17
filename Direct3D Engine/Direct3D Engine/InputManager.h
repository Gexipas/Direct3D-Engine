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

	void addListener(Event* action)
	{
		ActionsArray::iterator position = find(actions.begin(), actions.end(), action);

		if (position != actions.end())
		{
			printf_s("Action existed in delegate list.");
			return;
		}

		actions.push_back(action);
	}

	void removeListener(Event* action)
	{
		ActionsArray::iterator position = find(actions.begin(), actions.end(), action);

		if (position == actions.end())
		{
			return;
		}

		actions.erase(position);
	}

	void fire(GLFWwindow* _window, int _action)
	{
		for (Event* action : actions)
		{
			(*action)(_window, _action);
		}
	}

private:
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
	void Init(GLFWwindow* _window)
	{
		glfwSetCursorPosCallback(_window, mouse_callback);
		glfwSetScrollCallback(_window, scroll_callback);
		glfwSetKeyCallback(_window, key_callback);

		m_keyInputs = std::vector<KeyInput*>(349);
	}

	void AddInput(int _key, Event* action)
	{
		if (m_keyInputs[_key] == nullptr)
		{
			m_keyInputs[_key] = new KeyInput();
		}
		m_keyInputs[_key]->addListener(action);
	}

	void RemoveInput(int _key, Event* action)
	{
		if (m_keyInputs[_key] != nullptr)
		{
			m_keyInputs[_key]->removeListener(action);
		}
	}
	
private:
	// Functions
	static void mouse_callback(GLFWwindow* _window, double _xpos, double _ypos)
	{

	}

	static void scroll_callback(GLFWwindow* _window, double _xoffset, double _yoffset)
	{

	}

	static void key_callback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
	{
		if (m_keyInputs[_key] != nullptr)
		{
			m_keyInputs[_key]->fire(_window, _action);
		}
	}

	// Variables
	static std::vector<KeyInput*> m_keyInputs;
};