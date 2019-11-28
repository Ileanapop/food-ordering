//
// Created by ileana on 11/24/2019.
//

#ifndef FOOD_ORDERING_DATAINPUT_H
#define FOOD_ORDERING_DATAINPUT_H

void loadFoodData(FILE * pFile, int noOfFood,char ** food, char *** types, double ** prices, int *noOfTypes);
void loadDrinksData(FILE * pFile,char ** drinks, double * prices);
void freeFoodMemory(int noOfFood, char ** food, int * noOfTypes, char *** types, double ** prices);
void freeDrinksMemory(int noOfDrinks, char ** drinks, double * priceDrinks);

#endif //FOOD_ORDERING_DATAINPUT_H
