#include <iostream>

#include "Model.h"

void Model::Reset()
{
	Model::verticesCount = 0;
	Model::facesCount = 0;

	Model::vertices = NULL;
	Model::faces = NULL;
}

void Model::SetCounts(int verticesCount, int facesCount)
{
	Model::verticesCount = verticesCount;
	Model::facesCount = facesCount;
}

void Model::SetVertices(float* vertices)
{
	Model::vertices = vertices;
}

void Model::SetTriangles(int* faces)
{
	Model::faces = faces;
}