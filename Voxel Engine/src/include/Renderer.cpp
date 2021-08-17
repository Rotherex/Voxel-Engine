#include "Renderer.h"

void Renderer::prepare()
{
	glClearColor(0.5f, 0.9f, 0.8f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::render(RawModel model)
{
	EntityRenderer::render(model);
}