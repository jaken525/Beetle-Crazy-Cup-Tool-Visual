#include "obj2inf.h"

#include "BinaryFileWork.h"

void otoi::obj2inf::Convert()
{
	std::string fileName;
	std::string filePath;

	filePath = Binary::OpenFileName();
	fileName = Binary::GetFilenameFile(filePath);

	if (!fs::exists(*path + "\\Converted"))
		fs::create_directory(*path + "\\Converted");

	if (filePath != "")
	{
		Parser parser;

		parser.ObjParse(filePath, texture, autoTex);

		facesNum = parser.GetFacesNumber();
		verNum = parser.GetVerticiesNumber();
		tverNum = parser.GetTextureVerticiesNumber();
		norNum = parser.GetNormalsNumber();
		*polygons = parser.GetFaces();
		*vertices = parser.GetVerticies();
		*tvertices = parser.GetTextureVerticies();
		*normals = parser.GetNormals();

		tempVertices = vertices[0].data();

		parser.~Parser();

		writeINF(fileName);
		writeVER(fileName);

		writeTRI(texture, fileName);

		if (norNum > 0 && normals != NULL)
			writeNOR(fileName);
	}
}

void otoi::obj2inf::writeINF(std::string name)
{
	std::ofstream infFile(this->path[0] + "\\Converted\\" + name + ".inf", std::ios_base::binary);

	infFile << Binary::WriteLong(tverNum) << Binary::WriteLong(facesNum);
	infFile.close();
}

void otoi::obj2inf::writeVER(std::string name)
{
	std::ofstream file(this->path[0] + "\\Converted\\" + name + ".ver", std::ios_base::binary);

	for (int i = 0; i < tverNum; i++)
		file << Binary::WriteFloat((*vertices)[i * 3])
			 << Binary::WriteFloat((*vertices)[(i * 3) + 1])
			 << Binary::WriteFloat((*vertices)[(i * 3) + 2])
			 << Binary::WriteFloat((*tvertices)[i * 2])
			 << Binary::WriteFloat((*tvertices)[(i * 2) + 1]);
	file.close();
}

void otoi::obj2inf::writeTRI(int tex, std::string name)
{
	// Reading string.
	std::vector<int> verTriangles;
	std::vector<int> norTriangles;
	std::vector<int> texTriangles;

	for (int i = 0; i < facesNum * 4; i++)
	{
		std::string tempFace = "";

		if (GetSymbolsCount('/', (*polygons)[i]) > 0)
			for (int k = 0; k < size((*polygons)[i]); k++)
				if ((*polygons)[i][k] != '/')
					tempFace += (*polygons)[i][k];
				else
				{
					verTriangles.push_back(stoi(tempFace) - 1);

					tempFace = "";
					for (int j = k + 1; j <= size((*polygons)[i]); j++)
						tempFace += (*polygons)[i][j];

					norTriangles.push_back(stoi(tempFace) - 1);
					tempFace = "";

					break;
				}
		else
			texTriangles.push_back(stoi((*polygons)[i]));
	}

	_verTriangles = verTriangles.data();

	// Write.
	std::ofstream file(this->path[0] + "\\Converted\\" + name + ".tri", std::ios_base::binary);

	for (int i = 0; i < facesNum; i++)
	{
		file << Binary::WriteShort(verTriangles[i * 3]) << Binary::WriteShort(norTriangles[i * 3])
			 << Binary::WriteShort(verTriangles[(i * 3) + 2]) << Binary::WriteShort(norTriangles[(i * 3) + 2])
			 << Binary::WriteShort(verTriangles[(i * 3) + 1]) << Binary::WriteShort(norTriangles[(i * 3) + 1]);

		if (autoTex)
			file << Binary::WriteShort(texTriangles[i]) << Binary::WriteShort(65535);
		else
			file << Binary::WriteShort(tex) << Binary::WriteShort(65535);
	}
	file.close();
}

void otoi::obj2inf::writeNOR(std::string name)
{
	std::ofstream file(this->path[0] + "\\Converted\\" + name + ".nor", std::ios_base::binary);

	for (int i = 0; i < norNum; i++)
		file << Binary::WriteFloat((*normals)[i * 3])
			 << Binary::WriteFloat((*normals)[(i * 3) + 1])
			 << Binary::WriteFloat((*normals)[(i * 3) + 2]);
	file.close();
}