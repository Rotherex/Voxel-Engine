#include "Loader.h"

std::vector<GLuint> Loader::vaos;
std::vector<GLuint> Loader::vbos;

RawModel Loader::loadToVAO(float vertices[])
{
	int vaoID = createVAO();
	storeDataInAttributeList(vertices, 0, 3);

	return RawModel(vaoID, sizeof(vertices) / sizeof(vertices[0]));
}

int Loader::createVAO()
{
	GLuint vao_name;

	vaos.push_back(vao_name);	

	glGenVertexArrays(0, &vao_name);
	glBindVertexArray(vao_name);

	return vao_name;
}

void Loader::storeDataInAttributeList(float data[], int attributeNumber, int dimensions)
{
	GLuint vbo_name;

	vbos.push_back(vbo_name);

	glGenBuffers(0, &vbo_name);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_name);
	glBufferData(GL_ARRAY_BUFFER, dimensions, data, GL_STATIC_DRAW);
	glVertexAttribPointer(attributeNumber, dimensions, GL_FLOAT, false, 0, 0);
}

void Loader::cleanUp()
{
	for (GLuint vao : vaos)
	{
		glDeleteVertexArrays(0, &vao);
	};

	for (GLuint vbo : vbos)
	{
		glDeleteBuffers(0, &vbo);
	}
}