#include "furreal_interact.h"

void play(struct Pet *pet) {
    pet->energy -= 15;
    pet->happiness += 20;
}
void eat(struct Pet *pet) {
    pet->energy += 15;
    pet->hunger += 20;
}
void sleep(struct Pet *pet){
    pet->energy +=50;
}
void bath(struct Pet *pet){
    pet->energy -=10;
    pet->hygiene +=50;
}
void poke(struct Pet *pet){
    pet->energy -=10;
    pet->happiness -=50;
}
