//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H


#include "type.h"

typedef struct _food{
    char * name;
    int noOfTypes;
    type * types;
}food;

void loadFoodData(FILE * pFile, int noOfFood,food * foods);
void displayFoodOptions(int noOfFood, food * foods);
food createFood();
void freeFood(food * foods, int noOfFood);

#endif //FOOD_ORDERING_FOOD_H
