#pragma once
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#undef  GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <iostream>

class WindowManager
{
public:
	WindowManager(const char* name, int width, int height);
	GLFWwindow* m_Window;

	void update();
	bool closed();

private:
	int m_Width = 1280;
	int m_Height = 720;

	const char* m_Name;

	bool init();
};

