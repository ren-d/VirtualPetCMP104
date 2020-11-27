#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <thread>
#include <sstream>

class VirtualPet
{

private:
	std::string
		m_Name,
		m_Type;


	float
		m_Hunger,
		m_Energy,
		m_Playfulness,
		m_Happiness;
	bool
		m_isAlive;


public:
	std::string
		asciiDog[10],
		asciiCat[10],
		asciiBird[10],
		asciiFrog[10],
		asciiFish[10];

	VirtualPet();

	int SaveProgress();


	void SetType(int type);

	void UpdateHapiness();

	void SetName(std::string name);

	float GetHunger();

	float GetEnergy();

	float GetPlayfulness();

	float GetHappiness();

	std::string GetType();

	bool isAlive();

	std::string GetName();


	void SetHunger(float value);

	void SetEnergy(float value);

	void SetPlayfulness(float value);

	void ReduceStatus(float Hunger, float Energy, float Playfulness);

	void Feed();

	void Die();

	void Play();

	void Sleep();

};
#endif /*VIRTUALPET_H*/