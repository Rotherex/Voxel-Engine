#pragma once
class RawModel
{
public:
	RawModel(int vaoID, int vertexCount);

	int getVaoID();
	int getVertexCount();
private:
	int vaoID, vertexCount = 0;
};

