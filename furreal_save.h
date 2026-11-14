#ifndef FURREAL_SAVE_H
#define FURREAL_SAVE_H

#include "furreal_pet.h"

void savePet(const struct Pet *pet);
int loadPet(struct Pet *pet);
void checkPetStatus(struct Pet *pet);
void decreaseStat(struct Pet *pet);
void updateSurvivalTime(struct Pet *pet);

#endif
