#ifndef FURREAL_DISPLAY_H
#define FURREAL_DISPLAY_H

#include "furreal_pet.h"

void displayStart(void);
void initializePet(struct Pet *pet);
void displayPet(struct Pet pet);
void displayStats(struct Pet pet);
void displayMenu(void);
void gameOver(struct Pet pet);
void displayDialogue(struct Pet pet, int choice);

#endif
