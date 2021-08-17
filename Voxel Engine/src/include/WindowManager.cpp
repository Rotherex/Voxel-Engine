#include "WindowManager.h"

WindowManager::WindowManager(const char* name, int width, int height)
	{
		m_Width = width;
		m_Height = height;
		m_Name = name;

		if (!init()) {
			glfwTerminate();
		}
	}

	bool WindowManager::closed()
	{
		return glfwWindowShouldClose(m_Window);
	}

	bool WindowManager::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to initialise GLFW!" << std::endl;
			return false;
		}
		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to initialise GLFW window!" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return -1;
		}

		glViewport(0, 0, m_Width, m_Height);

		return true;
	}

	void WindowManager::update()
	{
		glfwPollEvents();
		glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}