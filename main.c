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

    displayStart();
    scanf("%d", &choiceStart);

        switch(choiceStart){
            case 1: // check on saved pet
                    // load save
                    // input validation if no save
            break;
            case 2: // new pet
                    // new input
            break;
            case 3:
                // quit
            break;
            default: // input validation
            break;
        }
                    // now u have ur pet ready to interact with
     while(1) {
        displayMenu();
        scanf("%d", &choiceInteract);
     }
    return 0;
}
