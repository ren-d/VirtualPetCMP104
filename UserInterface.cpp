#include "VirtualPet.h"
#include "UserInterface.h"
#include "MiscFunctions.h"
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//All user Interface code

UserInterface::UserInterface() //when the user interface object is initialized it will run this function
{
	menuState = true;
}

void UserInterface::VirtualPetMain(VirtualPet& pet)
{
	bool exit = false;
	do {
		Header();
		ln();
		nl();
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "                   Current Mood: ";
		if (pet.GetHappiness() > 3.5)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Very Happy";
		}
		else if (pet.GetHappiness() <= 0)
		{
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "DEAD";
		}
		else if (pet.GetHappiness() > 2.7)
		{
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Happy";
		}
		else if (pet.GetHappiness() > 2.5)
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "Fine";
		}
		else if (pet.GetHappiness() > 2.0)
		{
			SetConsoleTextAttribute(hConsole, 13);
			std::cout << "Unhappy";
		}
		else if (pet.GetHappiness() > 1.5)
		{
			SetConsoleTextAttribute(hConsole, 9);
			std::cout << "Sad";
		}
		else if (pet.GetHappiness() > 1.0)
		{
			SetConsoleTextAttribute(hConsole, 3);
			std::cout << "Very Sad";
		}
		else if (pet.GetHappiness() < 1.0)
		{
			SetConsoleTextAttribute(hConsole, 4);
			std::cout << "Distraught";
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "                                       Hunger: ";
		if (pet.GetHunger() >= 4.0)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Well Fed" << std::endl;
		}
		else if (pet.GetHunger() >= 3.0)
		{
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Slightly Peckish" << std::endl;
		}
		else if (pet.GetHunger() >= 2.0)
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "Rather Hungry" << std::endl;
		}
		else if (pet.GetHunger() < 2.0)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Starving" << std::endl;
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "                   Energy: ";
		if (pet.GetEnergy() >= 4.0)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Wide Awake";
		}
		else if (pet.GetEnergy() <= 0)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Collapsed";
		}
		else if (pet.GetEnergy() >= 3.0)
		{
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Awake";
		}
		else if (pet.GetEnergy() >= 2.0)
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "Tired";
		}
		else if (pet.GetEnergy() < 2.0)
		{
			SetConsoleTextAttribute(hConsole, 6);
			std::cout << "Falling Asleep";
		}
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "                                       Playfulness: ";
		if (pet.GetPlayfulness() == 0)
		{
			SetConsoleTextAttribute(hConsole, 12);
			std::cout << "Bored" << std::endl;
		}
		else if (pet.GetPlayfulness() <= 1)
		{
			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "PlayFul" << std::endl;
		}
		else if (pet.GetPlayfulness() <= 2)
		{
			SetConsoleTextAttribute(hConsole, 11);
			std::cout << "Very Playful" << std::endl;
		}
		else if (pet.GetPlayfulness() <= 3)
		{
			SetConsoleTextAttribute(hConsole, 10);
			std::cout << "Satisfied" << std::endl;
		}
		else if (pet.GetPlayfulness() <= 5)
		{
			SetConsoleTextAttribute(hConsole, 2);
			std::cout << "Fed up" << std::endl;
		}
		SetConsoleTextAttribute(hConsole, 14);
		nl();
		ln();
		nl();
		std::cout << "          Press ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "'f'";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << " to feed pet                                                      Press ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "'p'";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << " to play with pet" << std::endl;
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "                                                       " << pet.GetName() << std::endl;
		SetConsoleTextAttribute(hConsole, 15);
		if (pet.GetType() == "Dog")
		{
			PrintPet(pet.asciiDog, true);
		}
		else if (pet.GetType() == "Cat")
		{
			PrintPet(pet.asciiCat, true);
		}
		else if (pet.GetType() == "Bird")
		{
			PrintPet(pet.asciiBird, true);
		}
		else if (pet.GetType() == "Frog")
		{
			PrintPet(pet.asciiFrog, true);
		}
		else if (pet.GetType() == "Fish")
		{
			PrintPet(pet.asciiFish, true);
		}
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << "          Press ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "'s'";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << " to sleep                                                      Press ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << "'e'";
		SetConsoleTextAttribute(hConsole, 14);
		std::cout << " to exit " << std::endl;
		nl();
		ln();
		char test;
		SetConsoleTextAttribute(hConsole, 15);
		std::cin >> test;
		switch (test)
		{
		case 'f':
			pet.Feed();
			break;
		case 'p':
			pet.Play();
			break;
		case 's':
			pet.Sleep();
			break;
		case 'e':
			exit = true;
			PetActive = false;
			break;
		default:
			break;
		}
		SetConsoleTextAttribute(hConsole, 14);
		WaitAndRefresh(800);
	} while (exit == false);

}


int UserInterface::PetCreation(std::string pet1[10], std::string pet2[10], std::string pet3[10], std::string pet4[10], std::string pet5[10])
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
			PrintPet(pet1, false);

			break;
		case 1:
			PrintPet(pet2, false);
			break;
		case 2:
			PrintPet(pet3, false);
			break;
		case 3:
			PrintPet(pet4, false);
			break;
		case 4:
			PrintPet(pet5, false);
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

std::string UserInterface::NameCreation()
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

bool UserInterface::ConfirmPet(VirtualPet& pet)
{

	char userInput;
	do {
		Header();
		ln();
		nl();
		nl();
		Print("                                          Are you happy with your Virtual Pet?   y/n");
		nl();
		SetConsoleTextAttribute(hConsole, 15);
		if (pet.GetType() == "Dog")
		{
			PrintPet(pet.asciiDog, true);
		}
		else if (pet.GetType() == "Cat")
		{
			PrintPet(pet.asciiCat, true);
		}
		else if (pet.GetType() == "Bird")
		{
			PrintPet(pet.asciiBird, true);
		}
		else if (pet.GetType() == "Frog")
		{
			PrintPet(pet.asciiFrog, true);
		}
		else if (pet.GetType() == "Fish")
		{
			PrintPet(pet.asciiFish, true);
		}
		nl();
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "                                    Name: ";
		SetConsoleTextAttribute(hConsole, 15);
		std::cout << pet.GetName() << std::endl;
		SetConsoleTextAttribute(hConsole, 14);
		nl();
		ln();
		if (std::cin >> userInput)
		{
			switch (userInput)
			{
			case 'y':
				return true;
				break;
			case 'n':
				return false;
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
		WaitAndRefresh(500);
	} while (userInput != 'y' && userInput != 'n');


}

//Fake Loading screen
void UserInterface::LoadingScreen(std::string word, int speedMS)
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
//code path for loading an already created pet.
bool UserInterface::LoadExistingPet(VirtualPet& pet)
{
	if (CheckForExistingFile())
	{
		LoadingScreen("Opening save", 500);
		int i = 0;
		std::ifstream savefile("files/save_file.txt");
		std::string line;
		while (std::getline(savefile, line))
		{
			if (i == 0)
			{
				pet.SetName(line);
			}
			else if (i == 1)
			{
				if (line == "Dog")
				{
					pet.SetType(0);
				}
				if (line == "Cat")
				{
					pet.SetType(1);
				}
				if (line == "Bird")
				{
					pet.SetType(2);
				}
				if (line == "Frog")
				{
					pet.SetType(3);
				}
				if (line == "Fish")
				{
					pet.SetType(4);
				}

			}
			else if (i == 2)
			{
				pet.SetHunger(std::stof(line));
			}
			else if (i == 3)
			{
				pet.SetEnergy(std::stof(line));
			}
			else if (i == 4)
			{
				pet.SetPlayfulness(std::stof(line));
			}
			i++;
		}
		return true;

	}
	else
	{
		Print("There is no existing Pet");
		return false;
	}
}

void UserInterface::Initialize()
{
	LoadingScreen("Loading", 500);
	MenuScreen();
}

//waits for a specified amount of time then clears the console screen.
void UserInterface::WaitAndRefresh(int waitTimeMS)
{
	Sleep(waitTimeMS);
	system("CLS");
}


//makes writing std::cout statements quicker and easier to write
void UserInterface::Print(std::string string)
{
	std::cout << string << std::endl;
}

void UserInterface::nl()
{
	Print("");
}

//creates a large gap (makes formatting UI easier)
void UserInterface::LargeGap()
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

void UserInterface::ln()
{
	Print("    ______________________________________________________________________________________________________________    ");
}
void UserInterface::Header()
{
	SetConsoleTextAttribute(hConsole, 12);
	Print("VirtualPet.cpp  v1.0                                                                                     Duncan Rendall");
	nl();
	SetConsoleTextAttribute(hConsole, 14);

}
void UserInterface::PetSelectionArrows(int selectionValue)
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



//Shows the main menu screen.
void UserInterface::MenuScreen()
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
void UserInterface::MainMenuSelection()
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
			createPet = false;
			menuState = false;
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
bool UserInterface::CheckForExistingFile()
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
void UserInterface::CreateNewPet()
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


//shows the description of the program.
void UserInterface::Description()
{

}


//Exits the Program
void UserInterface::ExitProgram()
{
	exit(0);
}







