#pragma once
#include <GLFW/glfw3.h>
#include "RawModel.h"
#include "EntityRenderer.h"

class Renderer
{
public:
	static void prepare();

	static void render(RawModel model);
};

