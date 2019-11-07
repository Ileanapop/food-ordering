//
// Created by ileana on 11/6/2019.
//
#include<stdio.h>
#define MAX_FOOD_NAME 15
#define MAX_TYPE_NAME 17  //food type

void displayFoodOptions(int noOfFood, char food[][MAX_FOOD_NAME]){
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFood;i++)
    {
        putchar('a'+i);
        printf(") %s\n",food[i]);
    }
    printf("%c) Go back\n",'a'+noOfFood);
}

void displayFoodType(int noOfTypes, char food[],char typesFoodChosen[][MAX_TYPE_NAME],double prices[]){
    printf("Please choose the type of %s: \n",food);
    for(int i=0;i<noOfTypes;i++)
    {
        putchar('a'+i);
        printf(") %s: (%0.2f)\n",typesFoodChosen[i],prices[i]);
    }
    printf("%c) Go back\n",noOfTypes+'a');
}