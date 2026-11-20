#include <stdio.h>
#include "furreal_display.h"

#define DIALOGUE_NEW_GAME 0
#define DIALOGUE_LOAD_GAME 7

void displayStart(void){
    printf("==================================================\n");
    printf("      FUR REAL: Virtual Pet Simulator!\n");
    printf("==================================================\n");
    printf("1. Check on Your Pet!\n");
    printf("2. Adopt New Pet!\n");
    printf("3. Quit Game\n");
    printf("--------------------------------------------------\n");
    printf("Enter selection (1-3): ");
}
void initializePet(struct Pet *pet){
    pet->energy = 100;
    pet->hunger = 100;
    pet->happiness = 100;
    pet->hygiene = 100;
    pet->alive = 1;
}
void displayPet(struct Pet pet){
    if (pet.alive==0) {
        printf("  /\\_/\\  \n");
        printf("  ( x.x ) \n");
        printf("  > ^ <   \n");
        printf("   _   _  \n\n");
        return;
    }

    if (pet.hunger <= 10) {
        printf("  /\\_/\\  \n");
        printf("  ( T.T ) \n");
        printf("  > ~ <   \n");
        printf("   _   _  \n\n");
    }
    else if (pet.hunger <= 50) {
        printf("  /\\_/\\  \n");
        printf("  ( o.o ) \n");
        printf("  > . <   \n");
        printf("   _   _  \n\n");
    }
    else if (pet.energy <= 10) {
        printf("  /\\_/\\  \n");
        printf("  ( -.- ) \n");
        printf("  > z <   \n");
        printf("   _   _  \n\n");
    }
    else if (pet.hygiene <= 10) {
        printf("  /\\_/\\  \n");
        printf("  ( o//o ) \n");
        printf("  > * <   \n");
        printf("   _   _  \n\n");
    }
    else if (pet.happiness <= 10){
        printf("  /\\ _ /\\  \n");
        printf("    \\  /     \n");
        printf(" ( o m o ) \n");
        printf("   > * <   \n");
        printf("   _   _  \n\n");
    }
    else {
        printf("  /\\ _ /\\  \n");
        printf(" ( o v o )\n");
        printf("  <  *  > \n");
        printf("   _   _  \n\n");
    }
}
void displayStats(struct Pet pet){
    printf("--------------------------------------------------\n");
    printf("Name: %s\n", pet.name);
    printf("Hunger:  %d\n", pet.hunger);
    printf("Energy:  %d\n", pet.energy);
    printf("Happiness:  %d\n", pet.happiness);
    printf("Hygiene:  %d\n", pet.hygiene);
    printf("--------------------------------------------------\n");
}
void displayMenu(void){
    printf("--------------------------------------------------\n");
    printf("1. Eat\n");
    printf("2. Sleep\n");
    printf("3. Play \n");
    printf("4. Bath \n");
    printf("5. Poke! \n");
    printf("6. Save and Exit \n");
    printf("--------------------------------------------------\n");
    printf("Enter selection (1-6):\n\n");
}
void gameOver(struct Pet pet){
      printf("\n==================================================\n");
    printf("                  FUR REAL: RIP                   \n");
    printf("==================================================\n");

    if (pet.hunger <= 0) {
        printf("Here lies %s, who died from starvation.\n", pet.name);
    } else if (pet.energy <= 0) {
        printf("Here lies %s, who died from exhaustion.\n", pet.name);
    } else if (pet.hygiene <= 0) {
        printf("Here lies %s, who died from filth.\n", pet.name);
    } else {
        printf("Here lies %s, who died from a broken heart.\n", pet.name);
    }

    printf("\nGAME OVER\n");

    int minutes = (int)pet.age / 60;
    int seconds = (int)pet.age % 60;
    printf("%s survived %d minutes and %d seconds.\n", pet.name, minutes, seconds);
    printf("--------------------------------------------------\n");
}
void displayDialogue(struct Pet pet, int choice){
    if (choice == DIALOGUE_NEW_GAME) {
        printf("\"%s\"\n", "Hello!");
    } else if (choice == DIALOGUE_LOAD_GAME) {
        printf("\"%s\"\n", "Hello again!");
    }
    else if (pet.hunger <= 10) {
        printf("%s: \"meoooww... meoww... eoww...\"\n", pet.name);
    } else if (pet.energy <= 10) {
        printf("%s: \"zzzz...\"\n", pet.name);
    } else if (pet.hygiene <= 10) {
        printf("%s: \"Mreoww...!\"\n", pet.name);
    }
    else {
        switch(choice) {
            case 1: printf("%s: \"This tastes paw-some!\"\n", pet.name); break;
            case 2: printf("%s: \"zzz... mumumumumumu... zzz\"\n", pet.name); break;
            case 3: printf("%s: \"WeooOOOOWWW!\"\n", pet.name); break;
            case 4: printf("%s: \"hisss!\"\n", pet.name); break;
            case 5: printf("%s: \"mreow...!\"\n", pet.name); break;
            default: printf("%s: \"Meow?\"\n", pet.name); break;
        }
    }

}
