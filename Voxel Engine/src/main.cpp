#include "include/WindowManager.h"
#include "include/Renderer.h"
#include "include/Loader.h"
#include "include/RawModel.h"

int main()
{
	WindowManager window("Voxel", 1280, 720);

	float vertices[] = {
		-0.5f, 0.5f, 0,
		-0.5f, -0.5f, 0,
		0.5f, -0.5f, 0,
		0.5f, -0.5f, 0,
		0.5f, 0.5f, 0,
		-0.5f, 0.5f, 0,

	};


	RawModel model = Loader::loadToVAO(vertices);

	while (!window.closed())
	{
		Renderer::prepare();

		Renderer::render(model);

		window.update();
	}

	glfwTerminate();

	Loader::cleanUp();

	return 0;
}