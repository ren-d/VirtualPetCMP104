#include "VirtualPet.h"
#include "UserInterface.h"
#include "MiscFunctions.h"

void Update(VirtualPet& pet, UserInterface ui);

int main()
{
	VirtualPet pet;
	UserInterface ui;
	do {
		ui.Initialize();
		switch (ui.createPet)
		{
		case true:
			pet.SetType(ui.PetCreation(pet.asciiDog, pet.asciiCat, pet.asciiBird, pet.asciiFrog, pet.asciiFish));
			pet.SetName(ui.NameCreation());
			if (ui.ConfirmPet(pet))
			{
				ui.LoadingScreen("Creating New Pet save file", 500);
				pet.SaveProgress();
				ui.PetActive = true;
				ui.menuState = false;
				std::thread thread(Update, std::ref(pet), ui);
				ui.VirtualPetMain(pet);
				thread.detach();
			}
			ui.LoadingScreen("Saving Progress", 500);
			pet.SaveProgress();
			ui.menuState = true;
			break;
		case false:
			if (ui.LoadExistingPet(pet))
			{
				ui.PetActive = true;
				ui.menuState = false;
				std::thread thread(Update, std::ref(pet), ui);
				ui.VirtualPetMain(pet);
				ui.LoadingScreen("Saving Progress", 500);
				pet.SaveProgress();
				thread.detach();
				ui.menuState = true;
			}
			else 
			{
				ui.menuState = true;
			}
			
			
			break;
		}
	} while (ui.menuState == true);
	
	
	
	return 1;
}

void Update(VirtualPet& pet, UserInterface ui)
{
	while (ui.PetActive)
	{
		pet.ReduceStatus(0.2 * 0.15, 0.2 * 0.1, 0.2 * 0.1);
		pet.UpdateHapiness();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

