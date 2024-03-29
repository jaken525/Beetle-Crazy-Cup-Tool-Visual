ref struct Model
{
	static int verticesCount;
	static int facesCount;

	static float* vertices;
	static int* faces;

	static void Reset();
	static void SetVertices(float* vertices);
	static void SetTriangles(int* faces);
	static void SetCounts(int verticesCount, int facesCount);
};