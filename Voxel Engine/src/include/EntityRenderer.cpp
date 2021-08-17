#include "EntityRenderer.h"

void EntityRenderer::render(RawModel model)
{
	glBindVertexArray(model.getVaoID());
	glEnableVertexAttribArray(0);

	glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());

	glDisableVertexAttribArray(0);

	glBindVertexArray(0);
}