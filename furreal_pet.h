#ifndef FURREAL_PET_H
#define FURREAL_PET_H

#define MAX_SIZE 100

struct Pet {
    char name[MAX_SIZE];
    int energy;
    int hunger;
    int happiness;
    int hygiene;
    int alive;
    double survivalTime;
};

#endif
