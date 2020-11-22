#include <iostream>
#include <fstream>
#include "windows.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

class VirtualPet
{

private:

	std::string
		m_Name,
		m_Type;
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

class UserInterface
{
public:
	bool menuState = true;
	UserInterface()
	{
		Initialize();
	}
private:
	void Initialize()
	{
		LoadingScreen("Loading", 500);
		MenuScreen();


	}

	void WaitAndRefresh(int waitTimeMS)
	{
		Sleep(waitTimeMS);
		system("CLS");
	}

	void Print(std::string string)
	{
		std::cout << string << std::endl;
	}

	void nl()
	{
		Print("");
	}

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
			Selection();
			WaitAndRefresh(1000);
		}
		

	}

	void Selection()
	{
		int menuSelection;
		if (std::cin >> menuSelection)
		{
			switch (menuSelection)
			{
			case 0:
				CreateNewPet();
				break;
			case 1:
				LoadExistingPet();
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
		}

	}

	
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

	void Description()
	{

	}

	void ExitProgram()
	{
		exit(0);
	}

	
	

};

int main()
{
	VirtualPet pet;
	UserInterface ui;
	int userInput;
	std::cin >> userInput;
	pet.SetType(userInput);

	
	
	return 1;
}