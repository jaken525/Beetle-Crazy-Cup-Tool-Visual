// 3D model converter from Wavefront OBJ to Beetle Crazy Cup INF, VER, NOR and TRI

#include <vector>
#include <filesystem>

#include "parser.h"

namespace fs = std::filesystem;

namespace otoi
{
	public ref class obj2inf
	{
	public:
		bool autoTex;

		int facesNum = 0;
		int verNum = 0;
		int tverNum = 0;
		int norNum = 0;
		int texture = 0;

		std::vector<float>* vertices;
		std::vector<float>* tvertices;
		std::vector<float>* normals;

		std::vector<std::string>* polygons;

		int* _verTriangles;
		float* tempVertices;

		std::string* path;

		obj2inf() 
		{
			polygons = new std::vector<std::string>;

			vertices = new std::vector<float>;
			tvertices = new std::vector<float>;
			normals = new std::vector<float>;
		}

		~obj2inf() 
		{
			delete vertices;
			delete tvertices;
			delete normals;
			delete polygons;

			delete[] _verTriangles;
			delete[] tempVertices;
		}

		// Resetting all converter settings and data.
		void Reset(bool autoTex, int tex) 
		{
			_verTriangles = NULL;
			tempVertices = NULL;

			delete polygons;
			polygons = new std::vector<std::string>;

			delete vertices;
			delete tvertices;
			delete normals;
			vertices = new std::vector<float>;
			tvertices = new std::vector<float>;
			normals = new std::vector<float>;

			facesNum = 0;
			verNum = 0;
			tverNum = 0;
			norNum = 0;
			texture = tex;

			this->autoTex = autoTex;
		}

		// Start of the conversion process.
		void Convert();

	private:
		int GetSymbolsCount(char sym, std::string str)
		{
			int c = 0;
			for (int i = 0; i < str.length(); i++)
				if (str[i] == sym) c++;

			return c;
		}

		std::string changeSymbol(std::string str, char ch1, char ch2)
		{
			for (int i = 0; i < str.length(); i++)
				if (str[i] == ch1) str[i] = ch2;

			return str;
		}

		   // Writing a INF file.
		  // Structure:
		 // 4 bytes - number of verticies.
		// 4 bytes - number of faces.
		void writeINF(std::string name);

		   // Writing a VER file.
		  // Structure:
		 // 12 bytes float - coordinates of verticies.
		// 8 bytes - coordinates of texture verticies.
		void writeVER(std::string name);

		   // Writing a TRI file.
		  // Structure:
		 // 3 times ( XYZ ) 4 bytes - vertex triangle, 4 bytes - normal triangle.
		// 4 bytes - number of texture for this polygon.
		void writeTRI(int tex, std::string name);

		  // Writing a NOR file.
		 // Structure:
		// 12 bytes float - coordinates of normals.
		void writeNOR(std::string name);
	};
}