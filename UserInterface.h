#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "VirtualPet.h"


class UserInterface
{
public:
	bool menuState;
	bool createPet;
	bool PetActive;

	UserInterface();

	void VirtualPetMain(VirtualPet& pet);
		
	int PetCreation(std::string pet1[10], std::string pet2[10], std::string pet3[10], std::string pet4[10], std::string pet5[10]);

	std::string NameCreation();

	bool ConfirmPet(VirtualPet& pet);

	void LoadingScreen(std::string word, int speedMS);

	bool LoadExistingPet(VirtualPet& pet);

	void Initialize();

private:

	void WaitAndRefresh(int waitTimeMS);

	void Print(std::string string);

	void nl();

	void LargeGap();

	void ln();

	void Header();

	void PetSelectionArrows(int selectionValue);

	void MenuScreen();

	void MainMenuSelection();

	bool CheckForExistingFile();

	void CreateNewPet();

	void Description();

	void ExitProgram();



};
#endif /*USERINTERFACE_H*/