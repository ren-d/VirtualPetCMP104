#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void ConvertAsciiFileToArray(std::string Array[], std::string filename);

class VirtualPet
{

private:
	std::string
		m_Name,
		m_Type,
		m_asciiDog[10],
		m_asciiCat[10],
		m_asciiBird[10],
		m_asciiFrog[10],
		m_asciiFish[10];
	int
		m_Hunger,
		m_Energy,
		m_Playfulness;
	float
		m_Age;
	bool
		m_isAlive;


public:

	VirtualPet()
	{
		m_Name = "null";
		m_Type = "null";

		m_Age = 0.0;

		m_Hunger = 4;
		m_Energy = 4;
		m_Playfulness = 4;

		m_isAlive = true;

		ConvertAsciiFileToArray(m_asciiDog, "files/ascii/asciiDog.txt");
		ConvertAsciiFileToArray(m_asciiCat, "files/ascii/asciiCat.txt");
		ConvertAsciiFileToArray(m_asciiBird, "files/ascii/asciiBird.txt");
		ConvertAsciiFileToArray(m_asciiFrog, "files/ascii/asciiFrog.txt");
		ConvertAsciiFileToArray(m_asciiFish, "files/ascii/asciiFish.txt");

	}

	void SetType(int type)
	{

		switch (type)
		{
		case 0:
			m_Type = "Dog";
			break;
		case 1:
			m_Type = "Cat";
			break;
		case 2:
			m_Type = "Bird";
			break;
		case 3:
			m_Type = "Frog";
			break;
		case 4:
			m_Type = "Fish";
			break;
		}
	}

	void SetName(char* name)
	{
		m_Name = name;
	}

	int GetHunger()
	{
		return m_Hunger;
	}

	int GetEnergy()
	{
		return m_Energy;
	}

	int GetPlayfulness()
	{
		return m_Playfulness;
	}

	std::string GetType()
	{
		return m_Type;
	}

	bool isAlive()
	{
		return m_isAlive;
	}


};

//All user Interface code
class UserInterface
{
public:
	bool menuState = true;  //When program is in the menu state all code paths will return to the menu once it is at a dead end.
	bool createPet = true;
	UserInterface() //when the user interface object is initialized it will run this function
	{
		Initialize();
	}

	void PetCreation()
	{
		WaitAndRefresh(0);
		nl();
		nl();
		ln();
		Print("                                         Select a Pet Type");
		nl();
		nl();
		ln();

	}

private:
	void Initialize()
	{
		LoadingScreen("Loading", 500);
		MenuScreen();


	}

	//waits for a specified amount of time then clears the console screen.
	void WaitAndRefresh(int waitTimeMS)
	{
		Sleep(waitTimeMS);
		system("CLS");
	}


	//makes writing std::cout statements quicker and easier to write
	void Print(std::string string)
	{
		std::cout << string << std::endl;
	}

	void nl()
	{
		Print("");
	}

	//creates a large gap (makes formatting UI easier)
	void LargeGap()
	{
		nl();
		nl();
		nl();
		nl();
		nl();
		nl();
		nl();
		nl();
		nl();
	}

	void ln()
	{
		Print("    ______________________________________________________________________________________________________________    ");
	}


	//Fake Loading screen
	void LoadingScreen(std::string word, int speedMS)
	{
		for (int i = 0; i < 2; i++)
		{
			LargeGap();
			std::cout << "                                                    " << word << "                                                        " << std::endl;
			LargeGap();
			WaitAndRefresh(speedMS);
			LargeGap();
			std::cout << "                                                    " << word << ".                                                       " << std::endl;
			LargeGap();
			WaitAndRefresh(speedMS);
			LargeGap();
			std::cout << "                                                    " << word << ". .                                                     " << std::endl;
			LargeGap();
			WaitAndRefresh(speedMS);
			LargeGap();
			std::cout << "                                                    " << word << ". . .                                                   " << std::endl;
			LargeGap();
			WaitAndRefresh(speedMS);
		}

	}

	//Shows the main menu screen.
	void MenuScreen()
	{
		while (menuState)
		{
			nl();
			nl();
			SetConsoleTextAttribute(hConsole, 10);
			Print("                         __      __  _          _                     _   _____           _   ");
			Print("                         \\ \\    / / (_)        | |                   | | |  __ \\         | |  ");
			Print("                          \\ \\  / /   _   _ __  | |_   _   _    __ _  | | | |__) |   ___  | |_ ");
			Print("                           \\ \\/ /   | | | '__| | __| | | | |  / _` | | | |  ___/   / _ \\ | __|");
			Print("                            \\  /    | | | |    | |_  | |_| | | (_| | | | | |      |  __/ | |_ ");
			Print("                             \\/     |_| |_|     \\__|  \\__,_|  \\__,_| |_| |_|       \\___|  \\__|");
			SetConsoleTextAttribute(hConsole, 14);
			ln();
			nl();
			SetConsoleTextAttribute(hConsole, 15);
			Print("                           # 0 # Create New Pet                      # 1 # Load Existing Pet");
			nl();
			Print("                           # 2 # Description                         # 3 # Exit Program");
			SetConsoleTextAttribute(hConsole, 14);
			nl();
			ln();
			nl();
			nl();
			MainMenuSelection();
			WaitAndRefresh(1000);
		}


	}

	//The selection for the main menu.
	void MainMenuSelection()
	{
		int menuSelection;
		if (std::cin >> menuSelection)
		{
			switch (menuSelection)
			{
			case 0:
				CreateNewPet();
				createPet = true;
				break;
			case 1:
				LoadExistingPet();
				createPet = false;
				break;
			case 2:
				Description();
				break;
			case 3:
				ExitProgram();
				break;
			default:
				Print("Error input is invalid. Please enter a value from 0-3");
				break;
			}
		}
		else
		{
			Print("Error input is invalid. Please enter a value from 0-3");
		}

	}

	//checks code for an existing file.
	bool CheckForExistingFile()
	{
		std::ifstream ifile;
		ifile.open("files/save_file.txt");
		if (ifile)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//code path for the create a new pet option in the menu
	void CreateNewPet()
	{
		LoadingScreen("Checking for Existing File", 500);
		if (CheckForExistingFile())
		{
			Print("There");
			Print("would you like to overwrite save data?");
			Print("                  y/n");
			std::string userInput;

			do {
				std::cin >> userInput;
				if (userInput == "y")
				{
					std::remove("files/save_file.txt");
					std::ofstream saveFile("files/save_file.txt");
					menuState = false;
					break;
				}
				else if (userInput == "n")
				{
					Print("No");
					break;
				}
				else
				{
					Print("ERROR!!!! Please enter a (lowercase) 'y' or 'n'");
				}
			} while (true);
		}
		else
		{
			Print("GONE GONE");
			std::ofstream saveFile("files/save_file.txt");
			menuState = false;
		}
		Print("test");

	}

	//code path for loading an already created pet.
	void LoadExistingPet()
	{
		if (CheckForExistingFile())
		{
			LoadingScreen("Opening save", 500);
		}
		else
		{
			Print("There is no existing Pet");
		}
	}

	//shows the description of the program.
	void Description()
	{

	}


	//Exits the Program
	void ExitProgram()
	{
		exit(0);
	}




};

int main()
{
	VirtualPet pet;
	UserInterface ui;
	switch (ui.createPet)
	{
	case true:
		break;
	case false:
		break;
	}
	
	
	return 1;
}

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