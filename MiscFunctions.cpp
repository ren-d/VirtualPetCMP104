#include "VirtualPet.h"
#include "MiscFunctions.h"
void ConvertAsciiFileToArray(std::string petArray[], std::string filename)
{
	std::string line;
	std::ifstream myFile;
	myFile.open(filename);
	for (int i = 0; i < 10; i++)
	{
		std::getline(myFile, line);
		petArray[i] = line;
	}

}

//prints the ascii art for the pet
void PrintPet(std::string pet[10], bool removeName)
{
	if (removeName)  //removes 'cat/dog/bird...' from the .txt file
	{
		for (int i = 1; i < 10; i++)
		{
			std::cout << pet[i] << std::endl;
		}
	}
	else   //default print
	{
		for (int i = 0; i < 10; i++)
		{
			std::cout << pet[i] << std::endl;
		}
	}

}