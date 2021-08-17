#pragma once
#include "RawModel.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#undef  GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <list>
#include <vector>

class Loader
{
public:
	static RawModel loadToVAO(float vertices[]);

	static std::vector<GLuint> vaos;
	static std::vector<GLuint> vbos;

	static void cleanUp();

	static int createVAO();

	static void storeDataInAttributeList(float data[], int attributeNumber, int dimensions);
};

