#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "furreal_pet.h"
#include "furreal_interact.h"
#include "furreal_display.h"
#include "furreal_save.h"

int main(void){
    int choiceStart;
    int choiceInteract;
    int hasPet=0;

    struct Pet pet;
    initializePet(&pet);

    while(hasPet != 1){
    displayStart();
    scanf("%d", &choiceStart);
    while (getchar() != '\n');

        switch(choiceStart){
            case 1:
            if (loadPet(&pet)) {
                displayPet(pet);
                displayStats(pet);
                hasPet = 1;
            } else {
                printf("\nNo saved pet found! Please start a new pet.\n\n");
            }
            break;

            case 2:
            initializePet(&pet);

            printf("\n\nEnter your new pet's name: ");
            fgets(pet.name, MAX_SIZE, stdin);
            pet.name[strcspn(pet.name, "\n")] = '\0';

            printf("\n");
            displayPet(pet);
            displayStats(pet);
            hasPet = 1;

            break;
            case 3:
                return 1;
            break;
            default: printf("Invalid Input ! \n\n");
            break;
        }
    }

    decreaseStat(&pet);

    while (hasPet == 1&&pet.alive==1){
        displayMenu();
        scanf("%d", &choiceInteract);
        while (getchar() != '\n');
          switch(choiceInteract){
            case 1: eat(&pet);
                    displayPet(pet);
                    displayStats(pet);
                    checkPetStatus(&pet);
                break;
            case 2: sleep(&pet);
                    displayPet(pet);
                    displayStats(pet);
                    checkPetStatus(&pet);
                break;
            case 3: play(&pet);
                    displayPet(pet);
                    displayStats(pet);
                    checkPetStatus(&pet);
                break;
            case 4: bath(&pet);
                    displayPet(pet);
                    displayStats(pet);
                    checkPetStatus(&pet);
                break;
            case 5: poke(&pet);
                    displayPet(pet);
                    displayStats(pet);
                    checkPetStatus(&pet);
                break;// SAVE AND EXITk;
            case 6:
                break;
            default:
                break;
        }
    }

    if (pet.alive==0){
        gameOver(pet);
    }

    return 0;
}
