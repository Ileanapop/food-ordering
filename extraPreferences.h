//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_EXTRAPREFERENCES_H
#define FOOD_ORDERING_EXTRAPREFERENCES_H

#include "type.h"

void loadDrinksData(FILE * pFile,type * drinks);
void displayDrinkOptions(int noOfDrinks, char * food, type * drinks);
void displayCutlery();
void addAdditionalInformation(char * info);


#endif //FOOD_ORDERING_EXTRAPREFERENCES_H
