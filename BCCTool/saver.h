#pragma once
#include "SaveFileSource.h"

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <sstream>
#include <fstream>
#include <Windows.h>

namespace se 
{
	namespace fs = std::filesystem;

	bool isInteger(std::string& s);
	bool isFloat(std::string myString);
	std::string GetMapName(int tag, int number);

	const uint8_t sizeOfPlayerCars = 15;
	const uint8_t sizeOfModes = 5;
	const uint8_t sizeOfModeCars = 8;
	const uint8_t sizeOfBCModes = 7;

	struct Time
	{
		uint8_t minutes;
		uint8_t seconds;
		uint8_t milliseconds;
	};

	struct Level
	{
		Time totalTime[10];
		Time lapTime[10];

		std::string playerName[10];
	};

	struct AllRecordLevels
	{
		Level levels[7];

		std::string saveRecords;
		std::string saveVersion = "";
	};
	
	struct Car
	{
		int id = NULL;
		uint8_t color = NULL;
	};

	struct Map
	{
		uint8_t tag = NULL;
		uint8_t number = NULL;
	};

	struct PlayerCars
	{
		Car yourCars[sizeOfPlayerCars];
		Car quickRaceCars[sizeOfPlayerCars];
		Car marketCars[sizeOfPlayerCars];
		Car bonusCars[sizeOfPlayerCars];
		Car activatedCars[sizeOfPlayerCars];
	};

	struct OpponentCars
	{
		Car carModes[sizeOfModes];
	};

	struct ModeRaceSetting
	{
		uint32_t moneyForLevelPassing[sizeOfModes];
		uint32_t moneyForRecordPassing[sizeOfModes];

		uint8_t levelPassed[sizeOfModes];
		Map maps[sizeOfModes];

		 // BEFORE ALL CAR COLORS
		// AFTER ALL CAR IDS
		OpponentCars opponentCar[sizeOfModeCars];

		uint8_t laps[sizeOfModes];
		uint8_t countOfRacers[sizeOfModes]; // 0 ... 8
	};

	public struct Profile
	{
		std::string profileName = "";

		std::string saveVersion = "";
		std::string saveName = "";
		std::string saveProfileName = "";
		std::string saveDate = "";

		float points = NULL;

		uint8_t passedTrials = NULL;
		uint8_t countOfOpenBonus = NULL; // 0 ... 4
		uint8_t timeAttackSeconds = NULL;
		uint8_t championshipLevels = NULL;

		float jumpDistances[sizeOfBCModes];

		uint32_t countOfSaves = NULL;
		uint32_t openFinalChallenge = NULL; // 0 ... 1
		
		ModeRaceSetting modes[sizeOfBCModes];
		// 0 ... 5 43 bytes NULL
		// 6 23 bytes NULL
		Map lastMap;

		uint8_t countOfCarsYouHaveInModes[sizeOfModes];
		uint8_t countOfCarsYouHaveInQuickRaceMode[sizeOfModes];
		uint8_t countOfCarsYouCanBuy[sizeOfModes];
		uint8_t countOfCarsYouHaveInBonus[sizeOfModes];
		const uint8_t unknown0[sizeOfModes] = { 1, 0, 1, 0, 1 };
		uint8_t currentCarInModes[sizeOfModes];
		uint8_t currentCarInBonus[sizeOfModes];
		uint8_t currentCarInMarket[sizeOfModes];

		PlayerCars cars[sizeOfModes];

		Profile() 
		{

		}

		~Profile()
		{

		}
	};

	public ref class Saver
	{
	public:
		bool loaded;

		std::string* fileName;
		std::string* filePath;

		Profile* localProfile;
		Profile* localChampionshipProfile;
		AllRecordLevels* recordProfile;

		Saver()
		{
			loaded = false;
			localProfile = NULL;
			localChampionshipProfile = NULL;
			recordProfile = NULL;
			fileName = NULL;
			filePath = NULL;
		}

		~Saver()
		{
			loaded = false;
			delete[] localProfile;
			delete[] recordProfile;
			delete[] localChampionshipProfile;
			delete[] fileName;
			delete[] filePath;
		}

		void LoadBCSaveFile(std::string filePath, std::string fileName);
		void LoadBCSaveFile(int saveNumber);
		void LoadChampionshipSaveFile(std::string filePath, std::string fileName);
		void LoadRecordsSaveFile(std::string filePath, std::string fileName);
		bool LoadProfile();
		bool LoadProfile(std::string path);

		void SaveBCSaveFile(int saveNumber);
		void SaveChampionshipSaveFile();
		void SaveRecordsFile();

		void CreateNewProfile(std::string filePath, std::string fileName);
		void ChangeFileName(std::string fileName);

	private:
		std::string OpenFileName();
		bool OpenFile(char*& f, size_t& fsize, std::string filename);
		std::string GetFilenameFile(const std::string str);
		std::string GetFilenamePath(const std::string str);

		std::string ReadStringWithout(char*& f, size_t& pos, int size);
		std::string ReadString(char*& f, size_t& pos, int size);
		unsigned short ReadShort(char*& f, size_t& pos);
		unsigned int ReadShortShort(char*& f, size_t& pos);
		unsigned long ReadLong(char*& f, size_t& pos);
		float ReadFloat(char*& f, size_t& pos);

		std::string WriteShort(int num);
		std::string WriteLong(int num);
		std::string WriteFloatLong(float num);
		std::string WriteString(int size, std::string str);
	};
}