#include <iostream>
#include <fstream>
#include "windows.h"
#include <string>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void ConvertAsciiFileToArray(std::string Array[], std::string filename);
void PrintPet(std::string pet[]);

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
	std::string
		asciiDog[10],
		asciiCat[10],
		asciiBird[10],
		asciiFrog[10],
		asciiFish[10];

	VirtualPet()
	{
		m_Name = "null";
		m_Type = "null";

		m_Age = 0.0;

		m_Hunger = 4;
		m_Energy = 4;
		m_Playfulness = 4;

		m_isAlive = true;

		ConvertAsciiFileToArray(asciiDog, "files/ascii/asciiDog.txt");
		ConvertAsciiFileToArray(asciiCat, "files/ascii/asciiCat.txt");
		ConvertAsciiFileToArray(asciiBird, "files/ascii/asciiBird.txt");
		ConvertAsciiFileToArray(asciiFrog, "files/ascii/asciiFrog.txt");
		ConvertAsciiFileToArray(asciiFish, "files/ascii/asciiFish.txt");

	}

	void CreateSaveFile()
	{
		//creates save file for the pet
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
		std::cout << m_Type << std::endl;
	}

	void SetName(std::string name)
	{
		m_Name = name;
		std::cout << name << std::endl;
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
	std::string GetName()
	{
		return m_Name;
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

	int PetCreation(std::string pet1[10], std::string pet2[10], std::string pet3[10], std::string pet4[10], std::string pet5[10])
	{
		int currentSelection = 0;
		int userInput = 0;
		WaitAndRefresh(0);
		
		
		do {
			Header();
			ln();
			Print("                                                 Select a Pet Type");
			nl();
			nl();
			SetConsoleTextAttribute(hConsole, 15);
			switch (currentSelection)
			{
			case 0:
				PrintPet(pet1);

				break;
			case 1:
				PrintPet(pet2);
				break;
			case 2:
				PrintPet(pet3);
				break;
			case 3:
				PrintPet(pet4);
				break;
			case 4:
				PrintPet(pet5);
				break;
			}
			PetSelectionArrows(currentSelection);
			nl();
			nl();
			SetConsoleTextAttribute(hConsole, 14);
			Print("                                           Type '-1' to confirm selection.");
			
			ln();
			
			
			if (std::cin >> userInput)
			{
				switch (userInput)
				{
				case 1:
					if (currentSelection != 0)
					{
						currentSelection--;
					}

					break;
				case 2:
					if (currentSelection != 4)
					{
						currentSelection++;
					}
					break;
				case -1:
					userInput = -1;
					break;
				}
			}
			else
			{
				Print("Please Enter either '1' or '2'");
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			
			WaitAndRefresh(500);
		} while (userInput != -1);
		return currentSelection;

	}

	std::string NameCreation()
	{
		char name[9] = { '_','_','_','_','_', '_', '_', '_' }; 
		std::string userInput;
		char happy = 0;
		do {
			Header();
			ln();
			Print("                                              Create a name for your Virtual Pet");
			nl();
			nl();
			nl();
			nl();
			std::cout << "                                                       " << name[0] << "  " << name[1] << "  " << name[2] << "  " << name[3] << "  " << name[4] << "  " << name[5] << "  " << name[6] << "  " << name[7] << " " << name[8] << std::endl;
			nl();
			nl();
			nl();
			Print("                                                        Enter your new friend's name!");
			Print("          Or enter '0' to use the default name");
			ln();
			SetConsoleTextAttribute(hConsole, 15);
			std::getline(std::cin >> std::ws, userInput);
			if (userInput == "0")
			{
				userInput = "your pet";
			}
			if (userInput.length() > 8)
			{
				Print("Name is too Long, please enter a name with at most, '8 characters'");
			}
			else
			{
				
				strcpy_s(name, userInput.c_str());
				do
				{
					WaitAndRefresh(400);
					Header();
					ln();
					Print("                                              Create a name for your Virtual Pet");
					nl();
					nl();
					nl();
					nl();
					std::cout << "                                                       " << name[0] << "  " << name[1] << "  " << name[2] << "  " << name[3] << "  " << name[4] << "  " << name[5] << "  " << name[6] << "  " << name[7] << std::endl;
					nl();
					nl();
					nl();
					Print("                                             Are you happy with your pet's name? y/n");
					ln();
					if (std::cin >> happy)
					{
						switch (happy)
						{
						case 'n':
							std::fill_n(name, 9, '_');
							break;
						case 'y':
							Print("Hell yeah");
							WaitAndRefresh(400);
							break;
						default:
							break;
						}
					}
					else
					{
						Print("Please enter either 'y' or 'n'");
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
				} while (happy != 'y' && happy != 'n');
			}
			WaitAndRefresh(500);
		} while (happy != 'y');
		
		return userInput;
	}

	void ConfirmPet(VirtualPet pet)
	{
		LoadingScreen("Loading Your VirtualPet", 500);
		Header();
		ln();
		nl();
		nl();
		Print("                                          Are you happy with your Virtual Pet?");
		nl();
		SetConsoleTextAttribute(hConsole, 15);
		if (pet.GetType() == "Dog")
		{
			PrintPet(pet.asciiDog);
		}
		else if (pet.GetType() == "Cat")
		{
			PrintPet(pet.asciiCat);
		}
		else if (pet.GetType() == "Bird")
		{
			PrintPet(pet.asciiBird);
		}
		else if (pet.GetType() == "Frog")
		{
			PrintPet(pet.asciiDog);
		}
		else if (pet.GetType() == "Fish")
		{
			PrintPet(pet.asciiFish);
		}
		nl();
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "                                    Name: ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << pet.GetName() << std::endl;
		SetConsoleTextAttribute(hConsole, 14);
		nl();
		ln();
		int cool;
		std::cin >> cool;

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
	void Header()
	{
		SetConsoleTextAttribute(hConsole, 12);
		Print("VirtualPet.cpp  v1.0                                                                                     Duncan Rendall");
		nl();
		SetConsoleTextAttribute(hConsole, 14);

	}
	void PetSelectionArrows(int selectionValue)
	{
		SetConsoleTextAttribute(hConsole, 12);
		switch (selectionValue)
		{
		case 0:
			std::cout << "                                                              " << " ------> 2" << std::endl;
			break;
		case 4:
			std::cout << "                                          1 <------           " << std::endl;
			break;
		default:
			std::cout << "                                          1 <------           " << " ------> 2" << std::endl;
			break;
		}
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
			Header();
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
		pet.SetType(ui.PetCreation(pet.asciiDog, pet.asciiCat, pet.asciiBird, pet.asciiFrog, pet.asciiFish));
		pet.SetName(ui.NameCreation());
		ui.ConfirmPet(pet);
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


void PrintPet(std::string pet[10])
{

	for (int i = 0; i < 10; i++)
	{
		std::cout << pet[i] << std::endl;
	}
}