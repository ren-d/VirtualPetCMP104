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

			// code path for when the user creates a new pet


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

			//code path for when the user loads an existing pet.

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

//uses threading to update in the pet values in the background
void Update(VirtualPet& pet, UserInterface ui)
{
	while (ui.PetActive && pet.isAlive() == true)
	{
		pet.ReduceStatus(0.2 * 0.15, 0.2 * 0.1, 0.2 * 0.1);
		pet.UpdateHapiness();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		if (pet.GetHappiness() <= 0)
		{
			ui.LoadingScreen("Pet has died...", 500);
			std::cout << "your pet: " << pet.GetName() << " has died... Take care of your pet better next time" << std::endl;
			pet.Die();
			std::cin.get();
			exit(1);
		}
	}
}

