#include "VirtualPet.h"
#include "MiscFunctions.h"

VirtualPet::VirtualPet()
{
	m_Name = "null";
	m_Type = "null";


	m_Hunger = 4.0f;
	m_Energy = 4.0f;
	m_Playfulness = 0.0f;
	m_Happiness = (m_Hunger + m_Energy + m_Playfulness) / 3;
	m_isAlive = true;

	ConvertAsciiFileToArray(asciiDog, "files/ascii/asciiDog.txt");
	ConvertAsciiFileToArray(asciiCat, "files/ascii/asciiCat.txt");
	ConvertAsciiFileToArray(asciiBird, "files/ascii/asciiBird.txt");
	ConvertAsciiFileToArray(asciiFrog, "files/ascii/asciiFrog.txt");
	ConvertAsciiFileToArray(asciiFish, "files/ascii/asciiFish.txt");

}

int VirtualPet::SaveProgress()
{
	std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	//creates save file for the pet
	std::ofstream saveFile;
	saveFile.open("files/save_file.txt");
	saveFile << m_Name << std::endl;
	saveFile << m_Type << std::endl;
	saveFile << m_Hunger << std::endl;
	saveFile << m_Energy << std::endl;
	saveFile << m_Playfulness << std::endl;
	saveFile << m_isAlive << std::endl;
	saveFile << std::ctime(&end_time) << std::endl;
	return 0;

}


void VirtualPet::SetType(int type)
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

void VirtualPet::UpdateHapiness()
{
	m_Happiness = (m_Hunger + m_Energy + m_Playfulness) / 3;
}

void VirtualPet::SetName(std::string name)
{
	m_Name = name;
}

float VirtualPet::GetHunger()
{
	return m_Hunger;
}

float VirtualPet::GetEnergy()
{
	return m_Energy;
}

float VirtualPet::GetPlayfulness()
{
	return m_Playfulness;
}

float VirtualPet::GetHappiness()
{
	return m_Happiness;
}

std::string VirtualPet::GetType()
{
	return m_Type;
}

bool VirtualPet::isAlive()
{
	return m_isAlive;
}
std::string VirtualPet::GetName()
{
	return m_Name;
}


void VirtualPet::SetHunger(float value)
{
	m_Hunger = value;
}

void VirtualPet::SetEnergy(float value)
{
	m_Energy = value;
}

void VirtualPet::SetPlayfulness(float value)
{
	m_Playfulness = value;
}

void VirtualPet::ReduceStatus(float Hunger, float Energy, float Playfulness)
{
	m_Hunger -= Hunger;
	m_Energy -= Energy;
	m_Playfulness -= Playfulness;
}

void VirtualPet::Feed()
{
	if (m_Hunger < 4.0)
	{
		m_Hunger += 0.5f;
		std::cout << m_Name << " ate some yum yums" << std::endl;
	}
	else
	{
		std::cout << m_Name << " is not Hungry right now." << std::endl;
	}
}

void VirtualPet::Play()
{
	if (m_Energy >= 2.0 && m_Playfulness < 3.2)
	{
		m_Energy -= 0.1f;
		m_Playfulness += 0.7f;
		std::cout << m_Name << " did the fun" << std::endl;
	}
	else if (m_Energy < 2.5)
	{
		std::cout << m_Name << " is too Tired to play right now." << std::endl;
	}
	else if (m_Playfulness >= 3.2)
	{
		std::cout << m_Name << " has had enough of your silly games for now." << std::endl;
	}
}

void VirtualPet::Sleep()
{
	if (m_Energy < 2.5)
	{
		m_Energy = 4.0f;
		m_Hunger -= 2.0f;
		m_Playfulness -= 3.0f;
		std::cout << m_Name << " went to the sleep" << std::endl;
	}
	else
	{
		std::cout << m_Name << " is not tired right now.";
	}
}
