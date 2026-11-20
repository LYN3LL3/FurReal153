#include "furreal_save.h"
#include "furreal_pet.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

static time_t sessionStart = 0;
static time_t lastStatUpdate = 0;
static double sessionBase = 0;
static int timerStarted = 0;

static void startTimer(struct Pet *pet) {
    if (!timerStarted) {
        sessionStart = time(NULL);
        lastStatUpdate = sessionStart;
        sessionBase = pet->age;
        timerStarted = 1;
    }
}

void savePet(const struct Pet *pet){
    FILE *file;
    struct Pet *mutablePet = (struct Pet *)pet;

    if (pet == NULL) {
        return;
    }

    startTimer(mutablePet);
    updateSurvivalTime(mutablePet);

    file = fopen("pet_save.txt", "w");

    if (file == NULL) {
        printf("Error: Unable to save pet!\n");
        return;
    }

    fprintf(file, "%s\n", pet->name);

    fprintf(file, "%d %d %d %d %d %.2f\n",
        pet->energy,
        pet->hunger,
        pet->happiness,
        pet->hygiene,
        pet->alive,
        pet->age
    );

    fclose(file);

    printf("Pet progress successfully saved!\n");
}


int loadPet(struct Pet *pet){
   FILE *file;
    struct Pet temp;

    file = fopen("pet_save.txt", "r");
    if (file == NULL) {
        return 0;
    }

    if (fgets(temp.name, MAX_SIZE, file) == NULL) {
        fclose(file);
        return 0;
    }

    temp.name[strcspn(temp.name, "\n")] = '\0';

    /* Reject if the saved name is blank */
    if (strlen(temp.name) == 0) {
        fclose(file);
        return 0;
    }

    if (fscanf(file, "%d %d %d %d %d %d",
        &temp.energy,
        &temp.hunger,
        &temp.happiness,
        &temp.hygiene,
        &temp.alive,
        &temp.age) != 6) {

        fclose(file);
        return 0;
    }

    fclose(file);

    *pet = temp;

    /* Resume timer from saved survival time */
    timerStarted = 0;
    startTimer(pet);

    printf("Welcome back, %s!\n", pet->name);

    return 1;
}


void checkPetStatus(struct Pet *pet){
    if (pet == NULL) {
        return;
    }

    if (pet->energy <= 0 ||
        pet->hunger <= 0 ||
        pet->happiness <= 0 ||
        pet->hygiene <= 0) {

        pet->alive = 0;
    }
    else {
        pet->alive = 1;
    }
}


void decreaseStat(struct Pet *pet){
    time_t currentTime;
    int minutes;

    if (pet == NULL || pet->alive == 0) {
        return;
    }

    startTimer(pet);

    currentTime = time(NULL);

    minutes = (int)(difftime(currentTime, lastStatUpdate) / 60);

    if (minutes > 0) {

        pet->hunger -= 10 * minutes;
        pet->happiness -= 10 * minutes;
        pet->hygiene -= 10 * minutes;

        if (pet->hunger < 0)
            pet->hunger = 0;

        if (pet->happiness < 0)
            pet->happiness = 0;

        if (pet->hygiene < 0)
            pet->hygiene = 0;

        lastStatUpdate += minutes * 60;

        checkPetStatus(pet);
    }
}

void updateSurvivalTime(struct Pet *pet){
    time_t currentTime;

    if (pet == NULL) {
        return;
    }

    startTimer(pet);

    currentTime = time(NULL);

    if (pet->alive) {
        pet->age =
            sessionBase + difftime(currentTime, sessionStart);
    }
}
