/***********************
  File Name   :   InputManager.cpp
  Description :
  Author      :   Ethan WT Griffin
  Mail        :   Ethan.WTGriffin@gmail.com
********************/

#include "InputManager.h"

// KeyInput

void KeyInput::AddListener(Event* action)
{
	ActionsArray::iterator position = find(actions.begin(), actions.end(), action);

	if (position != actions.end())
	{
		printf_s("Action existed in delegate list.");
		return;
	}

	actions.push_back(action);
}

void KeyInput::RemoveListener(Event* action)
{
	ActionsArray::iterator position = find(actions.begin(), actions.end(), action);

	if (position == actions.end())
	{
		return;
	}

	actions.erase(position);
}

void KeyInput::Fire(GLFWwindow* _window, int _action)
{
	for (Event* action : actions)
	{
		(*action)(_window, _action);
	}
}

// InputManager

void InputManager::Init(GLFWwindow* _window)
{
	glfwSetCursorPosCallback(_window, MouseCallback);
	glfwSetScrollCallback(_window, ScrollCallback);
	glfwSetKeyCallback(_window, KeyCallback);

	m_keyInputs = std::vector<KeyInput*>(349);
}

void InputManager::AddInput(int _key, Event* action)
{
	if (m_keyInputs[_key] == nullptr)
	{
		m_keyInputs[_key] = new KeyInput();
	}
	m_keyInputs[_key]->AddListener(action);
}

void InputManager::RemoveInput(int _key, Event* action)
{
	if (m_keyInputs[_key] != nullptr)
	{
		m_keyInputs[_key]->RemoveListener(action);
	}
}


void InputManager::MouseCallback(GLFWwindow* _window, double _xpos, double _ypos)
{

}

void InputManager::ScrollCallback(GLFWwindow* _window, double _xoffset, double _yoffset)
{

}

void InputManager::KeyCallback(GLFWwindow* _window, int _key, int _scancode, int _action, int _mods)
{
	if (m_keyInputs[_key] != nullptr)
	{
		m_keyInputs[_key]->Fire(_window, _action);
	}
}

std::vector<KeyInput*> InputManager::m_keyInputs;