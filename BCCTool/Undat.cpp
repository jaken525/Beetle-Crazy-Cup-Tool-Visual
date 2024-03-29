#include "Screen.h"
#include "Undat.h"
#include "BinaryFileWork.h"

namespace fs = std::filesystem;

int _progress = 0;
int endPoint = 0;

std::string status = "";

bool IsProcessRunning(const TCHAR* const executableName)
{
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	const auto snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (!Process32First(snapshot, &entry))
	{
		CloseHandle(snapshot);
		return false;
	}

	do
	{
		if (!_tcsicmp(entry.szExeFile, executableName))
		{
			CloseHandle(snapshot);
			return true;
		}
	} while (Process32Next(snapshot, &entry));

	CloseHandle(snapshot);
	return false;
}

bool DAT::ReadAndWriteFolders(char*& f, size_t& pos, size_t& fsize, std::string& n)
{
	if (!fs::exists((*currentPath) + "\\data\\" + n))
		fs::create_directory((*currentPath) + "\\data\\" + n);

	bool sucess = false;

	num_folders = Binary::ReadLong(f, pos);
	num_files = Binary::ReadLong(f, pos);
	_progress = 0;
	endPoint = num_files + num_folders;

	folderID = new uint32_t[num_folders];
	folderName = new std::string[num_folders];

	fileName = new std::string[num_files];
	fileOffset = new size_t[num_files];
	fileSize = new uint32_t[num_files];
	fileTSTAMPfst = new uint32_t[num_files];
	fileTSTAMPsnd = new uint32_t[num_files];
	fileFolderID = new uint32_t[num_files];
	fileFolderIDTemp = new uint32_t[num_files];

	// folders
	for (int i = 0; i < num_folders; i++)
	{
		_progress += 1;

		folderID[i] = Binary::ReadLong(f, pos);
		folderName[i] = Binary::ReadStringWithout(f, pos, 128);
	}

	// files
	for (int i = 0; i < num_files; i++)
	{
		_progress += 1;

		fileFolderID[i] = Binary::ReadLong(f, pos);
		fileFolderIDTemp[i] = fileFolderID[i];
		fileName[i] = Binary::ReadStringWithout(f, pos, 128);
		fileOffset[i] = Binary::ReadLong(f, pos);
		fileSize[i] = Binary::ReadLong(f, pos);

		pos += 4; // skip zeroes

		fileTSTAMPfst[i] = Binary::ReadLong(f, pos);
		fileTSTAMPsnd[i] = Binary::ReadLong(f, pos);

		status = "Reading " + fileName[i];

		std::vector<std::string> folders;
		while (fileFolderID[i] != 0)
		{
			fileFolderID[i] -= 1;

			folders.push_back(folderName[fileFolderID[i]]);
			fileFolderID[i] = folderID[fileFolderID[i]];
		}

		std::string path = (*currentPath) + "\\data\\" + n + "\\";
		for (int j = folders.size() - 1; j >= 0; j--)
		{
			path += folders[j] + "\\";

			if (!fs::exists(path))
				fs::create_directory(path);
		}

		filesPath.push_back(path);
	}

	return sucess;
}

void DAT::WriteFiles(char*& f, size_t& pos, size_t& fsize)
{
	_progress = 0;
	endPoint = num_files;

	for (int i = 0; i < num_files; i++)
	{
		_progress += 1;
		status = "Writing " + fileName[i];
		std::string filepath = filesPath[i] + fileName[i];

		std::ofstream file(filepath, std::ios_base::binary);
		file << Binary::ReadString(f, fileOffset[i], fileSize[i]);
		file.close();
	}
}

void DAT::CreateArchive(std::string& n, bool cBackup, bool cStartScreen)
{
	std::ofstream tempWrite((*currentPath) + "\\data\\" + n + ".temp", std::ios::binary);
	size_t archiveIntro = (num_folders * 4 + num_folders * 128) + (num_files * 16 + num_files * 128 + num_files * 8) + 8;
	size_t temp = 0;

	_progress = 0;
	endPoint = num_files;

	for (int i = 0; i < num_files; i++)
	{
		_progress += 1;

		if (fs::exists(filesPath[i] + fileName[i]))
		{
			char* f = NULL;
			size_t fsize = 0;
			size_t ptr = 0;

			if (Binary::OpenFile(f, fsize, filesPath[i] + fileName[i]))
			{
				fileOffset[i] = archiveIntro + temp;
				status = "Packing " + fileName[i];

				if (fileName[i] == "CARGANDO.BMP" && cStartScreen)
				{
					fileSize[i] = std::size(tex::startScreen);
					temp += std::size(tex::startScreen) + 4;

					for (int j = 0; j < std::size(tex::startScreen); j++)
						tempWrite << char(tex::startScreen[j]);

					tempWrite << Binary::WriteLong(0);
				}
				else
				{
					fileSize[i] = fsize;

					temp += fsize + 4;

					tempWrite << Binary::ReadString(f, ptr, fsize) << Binary::WriteLong(0);
				}
			}

			if (f != NULL)
			{
				delete[] f;
				f = NULL;
			}
		}
		else
		{
			tempWrite.close();
			fs::remove((*currentPath) + "\\data\\" + n + ".temp");

			return;
		}
	}

	tempWrite.close();

	if (cBackup)
		fs::rename((*currentPath) + "\\data\\" + n + ".dat", (*currentPath) + "\\data\\" + n + "old.dat");
	else
		fs::remove((*currentPath) + "\\data\\" + n + ".dat");

	std::ofstream archive((*currentPath) + "\\data\\" + n + ".dat", std::ios::binary);

	archive << Binary::WriteLong(num_folders) << Binary::WriteLong(num_files);
	for (int i = 0; i < num_folders; i++)
		archive << Binary::WriteLong(folderID[i]) << Binary::WriteString(128, folderName[i]);

	for (int i = 0; i < num_files; i++)
		archive << Binary::WriteLong(fileFolderIDTemp[i])
				<< Binary::WriteString(128, fileName[i])
				<< Binary::WriteLong(fileOffset[i])
				<< Binary::WriteLong(fileSize[i])
				<< Binary::WriteLong(0)
				<< Binary::WriteLong(fileTSTAMPfst[i])
				<< Binary::WriteLong(fileTSTAMPsnd[i]);

	if (fs::exists((*currentPath) + "\\data\\" + n + ".temp"))
	{
		char* f = NULL;
		size_t fsize = 0;
		size_t ptr = 0;

		if (Binary::OpenFile(f, fsize, (*currentPath) + "\\data\\" + n + ".temp"))
		{
			std::string strTemp = Binary::ReadString(f, ptr, fsize);
			archive << strTemp;
		}

		if (f != NULL)
		{
			delete[] f;
			f = NULL;
		}
	}
	else
	{
		archive.close();
		return;
	}

	archive.close();
	fs::remove((*currentPath) + "\\data\\" + n + ".temp");
}

void Unpacker::SetPath(std::string path)
{
	_currentPath = new std::string{ path };
}

void Unpacker::Extract(std::string name)
{
	char* f = NULL;
	size_t fsize = 0;

	if (Binary::OpenFile(f, fsize, (*_currentPath) + "\\data\\" + name + ".dat"))
	{
		DAT dat((*_currentPath));
		size_t ptr = 0;

		dat.ReadAndWriteFolders(f, ptr, fsize, name);

		dat.WriteFiles(f, ptr, fsize);
	}

	if (f != NULL)
	{
		delete[] f;
		f = NULL;
	}
}

void Unpacker::PackBack(std::string name)
{
	if (fs::exists((*_currentPath) + "\\data\\" + name))
	{
		char* f = NULL;
		size_t fsize = 0;

		if (Binary::OpenFile(f, fsize, (*_currentPath) + "\\data\\" + name + ".dat"))
		{
			DAT dat((*_currentPath));
			size_t ptr = 0;

			dat.ReadAndWriteFolders(f, ptr, fsize, name);

			dat.CreateArchive(name, createBackup, changeStartScreen);
		}

		if (f != NULL)
		{
			delete[] f;
			f = NULL;
		}
	}
}