
// 3D model converter from Wavefront OBJ to Beetle Crazy Cup INF, VER, NOR and TRI

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include <shlwapi.h>
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
		}

		// Resetting all converter settings and data.
		void Reset(bool autoTex, int tex) 
		{
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
		void Convert()
		{
			std::string fileName;
			std::string filePath;

			filePath = OpenFileName();
			fileName = GetFilenameFile(filePath);

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

				parser.~Parser();

				writeINF(fileName);
				writeVER(fileName);

				writeTRI(texture, fileName);

				if (norNum > 0)
					writeNOR(fileName);
			}
		}

	private:
		 // Open the file selection window.
		// Getting a path by user selection.
		std::string OpenFileName()
		{
			std::string filename(MAX_PATH, '\0');
			OPENFILENAME ofn = { };

			ofn.lStructSize = sizeof(ofn);
			ofn.hwndOwner = NULL;
			ofn.lpstrFilter = "Wavefront Files (*.obj)\0*.obj\0All Files (*.*)\0*.*\0";
			ofn.lpstrFile = &filename[0];
			ofn.nMaxFile = MAX_PATH;
			ofn.lpstrTitle = "Select a File";
			ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;

			if (!GetOpenFileName(&ofn))
				return "";
			return filename;
		}

		std::string GetFilenameFile(const std::string str)
		{
			size_t found;
			std::string strt;
			found = str.find_last_of("/\\");

			if (found < str.size())
			{
				strt = str.substr(found + 1, -1);
				found = strt.find(".");
				if (found < strt.size())
					strt = strt.substr(0, found);
			}
			else strt = str;

			size_t lastdot = strt.find_last_of(".");

			if (lastdot == std::string::npos)
				return strt;
			return strt.substr(0, lastdot);
		}

		int GetSymbolsCount(char sym, std::string str)
		{
			int c = 0;

			for (int i = 0; i < str.length(); i++)
				if (str[i] == sym)
					c++;

			return c;
		}

		// Writing a 2-byte number.
		std::string writeShort(int num)
		{
			int arr[] = { 0, 0 };
			while (num >= 256)
			{
				arr[1] += 1;
				num -= 256;
			}
			arr[0] = num;

			std::string hex;
			for (int i = 0; i < 2; i++)
				hex += char(arr[i]);

			return hex;
		}

		   // Writing a 4-byte number.
		  // A number is taken and converted to HEX with the addition of zeros in front.
		 // Then the resulting value is flipped one byte at a time(2 characters each).
		// At the end, we translate everything into a string and the already received string is written to a file.
		std::string WriteLong(int num)
		{
			std::string Hex = "";
			std::stringstream s;
			s << std::hex << num;

			int zeroes = 8 - size(s.str());
			for (int i = 0; i < zeroes; i++)
				Hex += "0";
			Hex += s.str();

			int arr[] = { 0, 0, 0, 0 };
			int c = 3;
			for (int i = 0; i < Hex.length() - 1; i += 2)
			{
				std::stringstream h;
				h << Hex[i] << Hex[i + 1];
				h >> std::hex >> arr[c];
				c--;
			}

			Hex = "";
			for (int i = 0; i < 4; i++)
				Hex += char(uint8_t(arr[i]));

			return Hex;
		}

		std::string writeFloatLong(float num)
		{
			std::string strHEX = "";
			unsigned long a = 0;
			unsigned long a24 = 0;
			float n = num;

			memcpy(&a, &n, 4);
			strHEX += char(uint8_t(a));
			strHEX += char((uint16_t(a) - uint8_t(a)) / 0x00000100);

			memcpy(&a24, &n, 3);
			strHEX += char((a24 - int(uint16_t(a))) / 0x00010000);
			strHEX += char((a - a24) / 0x01000000);

			return strHEX;
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
		void writeINF(std::string name)
		{
			std::ofstream infFile(this->path[0] + "\\Converted\\" + name + ".inf", std::ios_base::binary);

			infFile << WriteLong(tverNum) << WriteLong(facesNum);
			infFile.close();
		}

		   // Writing a VER file.
		  // Structure:
		 // 12 bytes float - coordinates of verticies.
		// 8 bytes - coordinates of texture verticies.
		void writeVER(std::string name)
		{
			std::ofstream file(this->path[0] + "\\Converted\\" + name + ".ver", std::ios_base::binary);

			for (int i = 0; i < tverNum; i++)
				file << writeFloatLong((*vertices)[i * 3])
					 << writeFloatLong((*vertices)[(i * 3) + 1])
					 << writeFloatLong((*vertices)[(i * 3) + 2])
					 << writeFloatLong((*tvertices)[i * 2])
					 << writeFloatLong((*tvertices)[(i * 2) + 1]);
			file.close();
		}

		   // Writing a TRI file.
		  // Structure:
		 // 3 times ( XYZ ) 4 bytes - vertex triangle, 4 bytes - normal triangle.
		// 4 bytes - number of texture for this polygon.
		void writeTRI(int tex, std::string name)
		{
			// Reading string.
			std::vector<int> verTriangles;
			std::vector<int> norTriangles;
			std::vector<int> texTriangles;

			for (int i = 0; i < facesNum * 4; i++)
			{
				std::string tempFace = "";

				if (GetSymbolsCount('/', (*polygons)[i]) > 0)
				{
					for (int k = 0; k < size((*polygons)[i]); k++)
					{
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
					}
				}
				else
					texTriangles.push_back(stoi((*polygons)[i]));
			}

			// Write.
			std::ofstream file(this->path[0] + "\\Converted\\" + name + ".tri", std::ios_base::binary);

			for (int i = 0; i < facesNum; i++)
			{
				file << writeShort(verTriangles[i * 3]) << writeShort(norTriangles[i * 3])
				   	 << writeShort(verTriangles[(i * 3) + 2]) << writeShort(norTriangles[(i * 3) + 2])
					 << writeShort(verTriangles[(i * 3) + 1]) << writeShort(norTriangles[(i * 3) + 1]);

				if (autoTex)
					file << writeShort(texTriangles[i]) << writeShort(65535);
				else
					file << writeShort(tex) << writeShort(65535);
			}
			file.close();
		}

		  // Writing a NOR file.
		 // Structure:
		// 12 bytes float - coordinates of normals.
		void writeNOR(std::string name)
		{
			std::ofstream file(this->path[0] + "\\Converted\\" + name + ".nor", std::ios_base::binary);

			for (int i = 0; i < norNum; i++)
				file << writeFloatLong((*normals)[i * 3])
					 << writeFloatLong((*normals)[(i * 3) + 1])
					 << writeFloatLong((*normals)[(i * 3) + 2]);
			file.close();
		}
	};
}