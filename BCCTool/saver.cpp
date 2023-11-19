#include "saver.h"

bool se::isInteger(std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;
	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

bool se::isFloat(std::string myString)
{
	std::istringstream iss(myString);
	float f;
	iss >> std::noskipws >> f;

	return iss.eof() && !iss.fail();
}

std::string se::GetMapName(int tag, int number)
{
	std::string mapName = "";
	const std::string mapNames[8] = { "U-Rock", "Snake Alley", "Speed Wood", "The Take Off", "The Monster", "Cross n Roll", "Shark Beat", "One vs One" };

	if (tag == 4 && number == 5)
		mapName = mapNames[7];
	else
		mapName = mapNames[tag];

	return mapName;
}

void se::Saver::ChangeFileName(std::string fileName)
{
	delete this->fileName;
	this->fileName = new std::string{ fileName };
}

void se::Saver::CreateNewProfile(std::string filePath, std::string fileName)
{
	std::ofstream profileFile(filePath + fileName + ".usr", std::ios::binary);
	for ( int i = 0; i < std::size(se::profileFileSource); i++)
		profileFile << se::profileFileSource[i];
	profileFile.close();

	for (int i = 1; i <= 12; i++)
	{
		std::string _saveNumber = "";
		if (i > 0 && i < 10)
			_saveNumber = "0" + std::to_string(i);
		else
			_saveNumber = std::to_string(i);

		std::ofstream saveFile(filePath + fileName + "\\SAVE " + _saveNumber + ".rb", std::ios::binary);
		for (int i = 0; i < std::size(se::saveFileSource); i++)
			saveFile << se::saveFileSource[i];
		saveFile.close();
	}

	std::ofstream recordFile(filePath + fileName + "\\records.dat", std::ios::binary);
	for (int i = 0; i < std::size(se::recordsSaveSource); i++)
		recordFile << se::recordsSaveSource[i];
	recordFile.close();

	std::ofstream championshipFile(filePath + fileName + "\\Camp.r-b", std::ios::binary);
	for (int i = 0; i < std::size(se::saveFileSource); i++)
		championshipFile << se::saveFileSource[i];
	championshipFile.close();
}

bool se::Saver::LoadProfile()
{
	loaded = false;

	std::string file = "";
	file = OpenFileName();

	if (file != "")
	{
		delete localProfile;
		delete localChampionshipProfile;
		delete recordProfile;
		delete this->fileName;
		delete this->filePath;

		std::string fileName = GetFilenameFile(file);
		std::string filePath = GetFilenamePath(file);

		this->fileName = new std::string{ fileName };
		this->filePath = new std::string{ filePath };

		LoadBCSaveFile(filePath, fileName);
		LoadChampionshipSaveFile(filePath, fileName);
		LoadRecordsSaveFile(filePath, fileName);

		loaded = true;

		return true;
	}

	return false;
}

bool se::Saver::LoadProfile(std::string path)
{
	loaded = false;

	if (path != "")
	{
		delete localProfile;
		delete localChampionshipProfile;
		delete recordProfile;
		delete this->fileName;
		delete this->filePath;

		std::string fileName = GetFilenameFile(path);
		std::string filePath = GetFilenamePath(path);

		this->fileName = new std::string{ fileName };
		this->filePath = new std::string{ filePath };

		LoadBCSaveFile(filePath, fileName);
		LoadChampionshipSaveFile(filePath, fileName);
		LoadRecordsSaveFile(filePath, fileName);

		loaded = true;

		return true;
	}

	return false;
}

void se::Saver::SaveBCSaveFile(int saveNumber)
{
	std::string _saveNumber = "";
	if (saveNumber > 0 && saveNumber < 10)
		_saveNumber = "0" + std::to_string(saveNumber);
	else
		_saveNumber = std::to_string(saveNumber);

	std::ofstream newSaveFile(*filePath + *fileName + "\\SAVE " + _saveNumber + ".rb", std::ios::binary);

	newSaveFile << WriteString(4, "VT04");
	newSaveFile << WriteString(32, localProfile->saveName);
	newSaveFile << WriteString(32, localProfile->profileName);
	newSaveFile << WriteString(32, localProfile->saveDate);

	newSaveFile << WriteFloatLong(localProfile->points);

	newSaveFile << (char)localProfile->passedTrials;
	newSaveFile << (char)localProfile->countOfOpenBonus;
	newSaveFile << (char)localProfile->timeAttackSeconds;
	newSaveFile << (char)localProfile->championshipLevels;

	for (int i = 0; i < sizeOfBCModes - 1; i++)
		newSaveFile << WriteFloatLong(localProfile->jumpDistances[i]);

	newSaveFile << WriteLong(localProfile->countOfSaves);
	newSaveFile << WriteLong(localProfile->openFinalChallenge);

	newSaveFile << WriteString(128, "");

	for (int i = 0; i < sizeOfBCModes; i++)
	{
		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << WriteLong(localProfile->modes[i].moneyForLevelPassing[j]);

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << WriteLong(localProfile->modes[i].moneyForRecordPassing[j]);

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localProfile->modes[i].levelPassed[j];

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localProfile->modes[i].maps[j].tag;

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localProfile->modes[i].maps[j].number;

		for (int k = 0; k < sizeOfModes; k++)
			for (int j = 0; j < sizeOfModeCars; j++)
				newSaveFile << (char)localProfile->modes[i].opponentCar[k].carModes[j].color;

		for (int k = 0; k < sizeOfModes; k++)
			for (int j = 0; j < sizeOfModeCars; j++)
				newSaveFile << (char)localProfile->modes[i].opponentCar[k].carModes[j].id;

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localProfile->modes[i].laps[j];

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localProfile->modes[i].countOfRacers[j];

		if (i == sizeOfBCModes - 1)
			newSaveFile << WriteString(23, "");
		else
			newSaveFile << WriteString(43, "");
	}

	newSaveFile << (char)localProfile->lastMap.tag;
	newSaveFile << (char)localProfile->lastMap.number;
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->countOfCarsYouHaveInModes[i];

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->countOfCarsYouHaveInQuickRaceMode[i];

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->countOfCarsYouCanBuy[i];
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->countOfCarsYouHaveInBonus[i];

	newSaveFile << (char)1 << (char)0 << (char)1 << (char)0 << (char)1;

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->currentCarInModes[i];
	newSaveFile << WriteString(16, "");
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->currentCarInBonus[i];
	newSaveFile << WriteString(9, "");
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localProfile->currentCarInMarket[i];
	newSaveFile << WriteString(2, "");

	for (int i = 0; i < sizeOfModes; i++)
	{
		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].yourCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].yourCars[j].id;

			newSaveFile << (char)localProfile->cars[i].yourCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].quickRaceCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].quickRaceCars[j].id;

			newSaveFile << (char)localProfile->cars[i].quickRaceCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].marketCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].marketCars[j].id;

			newSaveFile << (char)localProfile->cars[i].marketCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].bonusCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].bonusCars[j].id;

			newSaveFile << (char)localProfile->cars[i].bonusCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			newSaveFile << (char)localProfile->cars[i].activatedCars[j].id;
			newSaveFile << (char)localProfile->cars[i].activatedCars[j].color;
		}
	}

	newSaveFile << 0;
	newSaveFile.close();
}

void se::Saver::SaveChampionshipSaveFile()
{
	std::ofstream newSaveFile(*filePath + *fileName + "\\Camp.r-b", std::ios::binary);

	newSaveFile << WriteString(4, "VT04");
	newSaveFile << WriteString(32, localChampionshipProfile->saveName);
	newSaveFile << WriteString(32, localChampionshipProfile->profileName);
	newSaveFile << WriteString(32, localChampionshipProfile->saveDate);

	newSaveFile << WriteFloatLong(localChampionshipProfile->points);

	newSaveFile << (char)localChampionshipProfile->passedTrials;
	newSaveFile << (char)localChampionshipProfile->countOfOpenBonus;
	newSaveFile << (char)localChampionshipProfile->timeAttackSeconds;
	newSaveFile << (char)localChampionshipProfile->championshipLevels;

	for (int i = 0; i < sizeOfBCModes - 1; i++)
		newSaveFile << WriteFloatLong(localChampionshipProfile->jumpDistances[i]);

	newSaveFile << WriteLong(localChampionshipProfile->countOfSaves);
	newSaveFile << WriteLong(localChampionshipProfile->openFinalChallenge);

	newSaveFile << WriteString(128, "");

	for (int i = 0; i < sizeOfBCModes; i++)
	{
		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << WriteLong(localChampionshipProfile->modes[i].moneyForLevelPassing[j]);

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << WriteLong(localChampionshipProfile->modes[i].moneyForRecordPassing[j]);

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localChampionshipProfile->modes[i].levelPassed[j];

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localChampionshipProfile->modes[i].maps[j].tag;

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localChampionshipProfile->modes[i].maps[j].number;

		for (int k = 0; k < sizeOfModes; k++)
			for (int j = 0; j < sizeOfModeCars; j++)
				newSaveFile << (char)localChampionshipProfile->modes[i].opponentCar[k].carModes[j].color;

		for (int k = 0; k < sizeOfModes; k++)
			for (int j = 0; j < sizeOfModeCars; j++)
				newSaveFile << (char)localChampionshipProfile->modes[i].opponentCar[k].carModes[j].id;

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localChampionshipProfile->modes[i].laps[j];

		for (int j = 0; j < sizeOfModes; j++)
			newSaveFile << (char)localChampionshipProfile->modes[i].countOfRacers[j];

		if (i == sizeOfBCModes - 1)
			newSaveFile << WriteString(23, "");
		else
			newSaveFile << WriteString(43, "");
	}

	newSaveFile << (char)localChampionshipProfile->lastMap.tag;
	newSaveFile << (char)localChampionshipProfile->lastMap.number;
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->countOfCarsYouHaveInModes[i];

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->countOfCarsYouHaveInQuickRaceMode[i];

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->countOfCarsYouCanBuy[i];
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->countOfCarsYouHaveInBonus[i];

	newSaveFile << (char)1 << (char)0 << (char)1 << (char)0 << (char)1;

	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->currentCarInModes[i];
	newSaveFile << WriteString(16, "");
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->currentCarInBonus[i];
	newSaveFile << WriteString(9, "");
	for (int i = 0; i < sizeOfModes; i++)
		newSaveFile << (char)localChampionshipProfile->currentCarInMarket[i];
	newSaveFile << WriteString(2, "");

	for (int i = 0; i < sizeOfModes; i++)
	{
		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].yourCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].yourCars[j].id;

			newSaveFile << (char)localProfile->cars[i].yourCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].quickRaceCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].quickRaceCars[j].id;

			newSaveFile << (char)localProfile->cars[i].quickRaceCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].marketCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].marketCars[j].id;

			newSaveFile << (char)localProfile->cars[i].marketCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			if (localProfile->cars[i].bonusCars[j].id == 255)
				newSaveFile << 0;
			else
				newSaveFile << (char)localProfile->cars[i].bonusCars[j].id;

			newSaveFile << (char)localProfile->cars[i].bonusCars[j].color;
		}

		for (int j = 0; j < sizeOfPlayerCars; j++)
		{
			newSaveFile << (char)localChampionshipProfile->cars[i].activatedCars[j].id;
			newSaveFile << (char)localChampionshipProfile->cars[i].activatedCars[j].color;
		}
	}

	newSaveFile << 0;
	newSaveFile.close();
}

void se::Saver::SaveRecordsFile()
{
	std::ofstream newSaveFile(*filePath + *fileName + "\\records.dat", std::ios::binary);

	newSaveFile << WriteString(4, "VT04");
	newSaveFile << WriteString(590, "");

	for (int i = 0; i < sizeOfBCModes; i++)
		for (int j = 0; j < 10; j++)
		{
			newSaveFile << (char)recordProfile->levels[i].totalTime[j].minutes;
			newSaveFile << (char)recordProfile->levels[i].totalTime[j].seconds;
			newSaveFile << (char)recordProfile->levels[i].totalTime[j].milliseconds;
		}

	newSaveFile << WriteString(87, "");

	for (int i = 0; i < sizeOfBCModes; i++)
		for (int j = 0; j < 10; j++)
		{
			newSaveFile << (char)recordProfile->levels[i].lapTime[j].minutes;
			newSaveFile << (char)recordProfile->levels[i].lapTime[j].seconds;
			newSaveFile << (char)recordProfile->levels[i].lapTime[j].milliseconds;
		}

	newSaveFile << WriteString(257, "");

	for (int i = 0; i < sizeOfBCModes; i++)
		for (int j = 0; j < 10; j++)
			newSaveFile << WriteString(20, recordProfile->levels[i].playerName[j]);

/*	newSaveFile << WriteString(580, "");

	for (int i = 0; i < sizeOfBCModes; i++)
		for (int j = 0; j < 10; j++)
			newSaveFile << WriteString(20, recordProfile->levels[i].playerName[j]);*/

	newSaveFile << WriteString(2360, "");

	newSaveFile << WriteString(4366, recordProfile->saveRecords);

	newSaveFile.close();
}

void se::Saver::LoadChampionshipSaveFile(std::string filePath, std::string fileName)
{
	Profile profile;
	char* f = NULL;
	size_t fsize = 0;

	if (OpenFile(f, fsize, filePath + fileName + "\\Camp.r-b"))
	{
		size_t ptr = 0;

		profile.saveVersion = ReadStringWithout(f, ptr, 4);

		profile.profileName = fileName;

		profile.saveName = ReadStringWithout(f, ptr, 32);
		profile.saveProfileName = ReadStringWithout(f, ptr, 32);
		profile.saveDate = ReadStringWithout(f, ptr, 32);

		profile.points = ReadFloat(f, ptr);

		profile.passedTrials = ReadShortShort(f, ptr);
		profile.countOfOpenBonus = ReadShortShort(f, ptr);
		profile.timeAttackSeconds = ReadShortShort(f, ptr);
		profile.championshipLevels = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfBCModes - 1; i++)
			profile.jumpDistances[i] = ReadFloat(f, ptr);

		profile.countOfSaves = ReadLong(f, ptr);
		profile.openFinalChallenge = ReadLong(f, ptr);

		ptr += 128;

		for (int i = 0; i < sizeOfBCModes; i++)
		{
			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForLevelPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForRecordPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].levelPassed[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].tag = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].number = ReadShortShort(f, ptr);

			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].color = ReadShortShort(f, ptr);

			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].id = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].laps[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].countOfRacers[j] = ReadShortShort(f, ptr);

			if (i == sizeOfBCModes - 1)
				ptr += 23;
			else
				ptr += 43;
		}

		profile.lastMap.tag = ReadShortShort(f, ptr);
		profile.lastMap.number = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInModes[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInQuickRaceMode[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouCanBuy[i] = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInBonus[i] = ReadShortShort(f, ptr);

		ptr += 5;

		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInModes[i] = ReadShortShort(f, ptr);
		ptr += 16;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInBonus[i] = ReadShortShort(f, ptr);
		ptr += 9;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInMarket[i] = ReadShortShort(f, ptr);
		ptr += 2;

		for (int i = 0; i < sizeOfModes; i++)
		{
			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].yourCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].yourCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].quickRaceCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].quickRaceCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].marketCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].marketCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].bonusCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].bonusCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].activatedCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].activatedCars[j].color = ReadShortShort(f, ptr);
			}
		}
	}

	if (f != NULL)
		delete[] f;

	localChampionshipProfile = new Profile{ profile };
}

void se::Saver::LoadBCSaveFile(int saveNumber)
{
	Profile profile;
	char* f = NULL;
	size_t fsize = 0;

	std::string _saveNumber = "";
	if (saveNumber > 0 && saveNumber < 10)
		_saveNumber = "0" + std::to_string(saveNumber);
	else
		_saveNumber = std::to_string(saveNumber);

	if (OpenFile(f, fsize, *filePath + *fileName + "\\SAVE " + _saveNumber + ".rb"))
	{
		size_t ptr = 0;

		profile.saveVersion = ReadStringWithout(f, ptr, 4);

		profile.profileName = *fileName;

		profile.saveName = ReadStringWithout(f, ptr, 32);
		profile.saveProfileName = ReadStringWithout(f, ptr, 32);
		profile.saveDate = ReadStringWithout(f, ptr, 32);

		profile.points = ReadFloat(f, ptr);

		profile.passedTrials = ReadShortShort(f, ptr);
		profile.countOfOpenBonus = ReadShortShort(f, ptr);
		profile.timeAttackSeconds = ReadShortShort(f, ptr);
		profile.championshipLevels = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfBCModes - 1; i++)
			profile.jumpDistances[i] = ReadFloat(f, ptr);

		profile.countOfSaves = ReadLong(f, ptr);
		profile.openFinalChallenge = ReadLong(f, ptr);

		ptr += 128;

		for (int i = 0; i < sizeOfBCModes; i++)
		{
			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForLevelPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForRecordPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].levelPassed[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].tag = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].number = ReadShortShort(f, ptr);

			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].color = ReadShortShort(f, ptr);
					
			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].id = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].laps[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].countOfRacers[j] = ReadShortShort(f, ptr);

			if (i == sizeOfBCModes - 1)
				ptr += 23;
			else
				ptr += 43;
		}

		profile.lastMap.tag = ReadShortShort(f, ptr);
		profile.lastMap.number = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInModes[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInQuickRaceMode[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouCanBuy[i] = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInBonus[i] = ReadShortShort(f, ptr);

		ptr += 5;

		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInModes[i] = ReadShortShort(f, ptr);
		ptr += 16;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInBonus[i] = ReadShortShort(f, ptr);
		ptr += 9;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInMarket[i] = ReadShortShort(f, ptr);
		ptr += 2;

		for (int i = 0; i < sizeOfModes; i++)
		{
			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].yourCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].yourCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].quickRaceCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].quickRaceCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].marketCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].marketCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].bonusCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].bonusCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].activatedCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].activatedCars[j].color = ReadShortShort(f, ptr);
			}
		}
	}

	if (f != NULL)
		delete[] f;

	localProfile = new Profile{ profile };
}

void se::Saver::LoadBCSaveFile(std::string filePath, std::string fileName)
{
	Profile profile;
	char* f = NULL;
	size_t fsize = 0;

	if (OpenFile(f, fsize, filePath + fileName + "\\SAVE 01.rb"))
	{
		size_t ptr = 0;

		profile.saveVersion = ReadStringWithout(f, ptr, 4);

		profile.profileName = fileName;

		profile.saveName = ReadStringWithout(f, ptr, 32);
		profile.saveProfileName = ReadStringWithout(f, ptr, 32);
		profile.saveDate = ReadStringWithout(f, ptr, 32);

		profile.points = ReadFloat(f, ptr);

		profile.passedTrials = ReadShortShort(f, ptr);
		profile.countOfOpenBonus = ReadShortShort(f, ptr);
		profile.timeAttackSeconds = ReadShortShort(f, ptr);
		profile.championshipLevels = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfBCModes - 1; i++)
			profile.jumpDistances[i] = ReadFloat(f, ptr);

		profile.countOfSaves = ReadLong(f, ptr);
		profile.openFinalChallenge = ReadLong(f, ptr);

		ptr += 128;

		for (int i = 0; i < sizeOfBCModes; i++)
		{
			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForLevelPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].moneyForRecordPassing[j] = ReadLong(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].levelPassed[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].tag = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].maps[j].number = ReadShortShort(f, ptr);

			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].color = ReadShortShort(f, ptr);
				
			for (int k = 0; k < sizeOfModes; k++)
				for (int j = 0; j < sizeOfModeCars; j++)
					profile.modes[i].opponentCar[k].carModes[j].id = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].laps[j] = ReadShortShort(f, ptr);

			for (int j = 0; j < sizeOfModes; j++)
				profile.modes[i].countOfRacers[j] = ReadShortShort(f, ptr);

			if (i + 1 == sizeOfBCModes)
				ptr += 23;
			else
				ptr += 43;
		}

		profile.lastMap.tag = ReadShortShort(f, ptr);
		profile.lastMap.number = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInModes[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInQuickRaceMode[i] = ReadShortShort(f, ptr);

		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouCanBuy[i] = ReadShortShort(f, ptr);
		for (int i = 0; i < sizeOfModes; i++)
			profile.countOfCarsYouHaveInBonus[i] = ReadShortShort(f, ptr);

		ptr += 5;

		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInModes[i] = ReadShortShort(f, ptr);
		ptr += 16;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInBonus[i] = ReadShortShort(f, ptr);
		ptr += 9;
		for (int i = 0; i < sizeOfModes; i++)
			profile.currentCarInMarket[i] = ReadShortShort(f, ptr);
		ptr += 2;

		for (int i = 0; i < sizeOfModes; i++)
		{
			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].yourCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].yourCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].quickRaceCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].quickRaceCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].marketCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].marketCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].bonusCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].bonusCars[j].color = ReadShortShort(f, ptr);
			}

			for (int j = 0; j < sizeOfPlayerCars; j++)
			{
				profile.cars[i].activatedCars[j].id = ReadShortShort(f, ptr);
				profile.cars[i].activatedCars[j].color = ReadShortShort(f, ptr);
			}
		}
	}

	if (f != NULL)
		delete[] f;

	localProfile = new Profile{ profile };
}

void se::Saver::LoadRecordsSaveFile(std::string filePath, std::string fileName)
{
	AllRecordLevels records;
	char* f = NULL;
	size_t fsize = 0;

	if (OpenFile(f, fsize, filePath + fileName + "\\records.dat"))
	{
		size_t ptr = 0;

		records.saveVersion = ReadStringWithout(f, ptr, 4);

		ptr += 590;

		for (int i = 0; i < sizeOfBCModes; i++)
			for (int j = 0; j < 10; j++)
			{
				records.levels[i].totalTime[j].minutes = ReadShortShort(f, ptr);
				records.levels[i].totalTime[j].seconds = ReadShortShort(f, ptr);
				records.levels[i].totalTime[j].milliseconds = ReadShortShort(f, ptr);
			}

		ptr += 87;

		for (int i = 0; i < sizeOfBCModes; i++)
			for (int j = 0; j < 10; j++)
			{
				records.levels[i].lapTime[j].minutes = ReadShortShort(f, ptr);
				records.levels[i].lapTime[j].seconds = ReadShortShort(f, ptr);
				records.levels[i].lapTime[j].milliseconds = ReadShortShort(f, ptr);
			}

		ptr += 257;

		for (int i = 0; i < sizeOfBCModes; i++)
			for (int j = 0; j < 10; j++)
				records.levels[i].playerName[j] = ReadStringWithout(f, ptr, 20);

		ptr += 2360;

/*		for (int i = 0; i < sizeOfBCModes; i++)
			for (int j = 0; j < 10; j++)
				records.levels[i].playerName[j] = ReadStringWithout(f, ptr, 20);

		ptr += 380;*/

		records.saveRecords = ReadString(f, ptr, 4366);
	}

	if (f != NULL)
		delete[] f;

	recordProfile = new AllRecordLevels{ records };
}

std::string se::Saver::ReadStringWithout(char*& f, size_t& pos, int size)
{
	std::string result = "";
	bool isWriting = true;

	for (int i = 0; i < size; i++)
	{
		if (f[pos] != 0 && isWriting)
			result += f[pos];
		else
			isWriting = false;
		pos += 1;
	}

	return result;
}

std::string se::Saver::ReadString(char*& f, size_t& pos, int size)
{
	std::string result = "";

	for (int i = 0; i < size; i++)
	{
		result += f[pos];
		pos += 1;
	}

	return result;
}

std::string se::Saver::OpenFileName()
{
	std::string filename(MAX_PATH, '\0');
	OPENFILENAME ofn = { };
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = "Beetle Crazy Cup User File (*.usr)\0*.usr\0All Files (*.*)\0*.*\0";
	ofn.lpstrFile = &filename[0];
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a File";
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	if (!GetOpenFileName(&ofn))
		return "";
	return filename;
}

unsigned long se::Saver::ReadLong(char*& f, size_t& pos)
{
	unsigned long result = {
		(unsigned int)((uint8_t)f[pos] * 0x00000001) + \
		(unsigned int)((uint8_t)f[pos + 1] * 0x00000100) + \
		(unsigned int)((uint8_t)f[pos + 2] * 0x00010000) + \
		(unsigned int)((uint8_t)f[pos + 3] * 0x01000000)
	};
	pos += 4;
	return result;
}

unsigned short se::Saver::ReadShort(char*& f, size_t& pos)
{
	unsigned short result = {
		(unsigned int)((uint8_t)f[pos] * 0x00000001) + \
		(unsigned int)((uint8_t)f[pos + 1] * 0x00000100)
	};
	pos += 2;
	return result;
}

unsigned int se::Saver::ReadShortShort(char*& f, size_t& pos)
{
	unsigned short result = {
		(unsigned int)((uint8_t)f[pos] * 0x00000001)
	};
	pos += 1;
	return result;
}

float se::Saver::ReadFloat(char*& f, size_t& pos)
{
	float result = 0.0;
	unsigned long b = ReadLong(f, pos);
	memcpy(&result, &b, 4);
	return result;
}

bool se::Saver::OpenFile(char*& f, size_t& fsize, std::string filename)
{
	HANDLE hFile = CreateFile(
		filename.c_str(),		// file to open
		GENERIC_READ,			// open for reading
		FILE_SHARE_READ,		// share for reading
		NULL,					// default security
		OPEN_EXISTING,			// existing file only
		FILE_ATTRIBUTE_NORMAL,	// normal file
		NULL					// no attr. template
	);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << " Failed to Open File\n";
		return false;
	}

	fsize = GetFileSize(hFile, NULL);
	if (fsize == 0)
	{
		std::cout << " Failed to read file. File is Empty?\n";
		return false;
	}

	f = new char[fsize];
	unsigned long dwBytesRead = 0;
	if (ReadFile(hFile, f, fsize, &dwBytesRead, NULL) == FALSE || dwBytesRead != fsize)
	{
		std::cout << " Failed to copy file into memory\n";
		fsize = 0;
		delete[] f;
		f = NULL;
		CloseHandle(hFile);
		return false;
	}

	CloseHandle(hFile);
	return true;
}

std::string se::Saver::GetFilenameFile(const std::string str)
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
	else 
		strt = str;

	size_t lastdot = strt.find_last_of(".");

	if (lastdot == std::string::npos)
		return strt;

	return strt.substr(0, lastdot);
}

std::string se::Saver::GetFilenamePath(const std::string str)
{
	size_t found;
	std::string strt;

	found = str.find_last_of("/\\");
	if (found != std::string::npos)
	{
		strt = str.substr(0, found);
		return (strt + "\\");
	}
	else
		return "";
}

// Writing a 2-byte number.
std::string se::Saver::WriteShort(int num)
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
std::string se::Saver::WriteLong(int num)
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

std::string se::Saver::WriteString(int size, std::string str)
{
	size -= str.length();

	std::string endLine = "";
	endLine += str;

	for (int i = 0; i < size; i++)
		endLine += char(uint8_t(0));

	return endLine;
}

std::string se::Saver::WriteFloatLong(float num)
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
