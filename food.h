//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_FOOD_H
#define FOOD_ORDERING_FOOD_H
#define MAX_FOOD_NAME 15
#define MAX_TYPE_NAME 17  //food type

void displayFoodOptions(int noOfFood, char food[][MAX_FOOD_NAME]);
void displayFoodType(int noOfTypes, char food[],char typesFoodChosen[][MAX_TYPE_NAME],double prices[]);

#endif //FOOD_ORDERING_FOOD_H
