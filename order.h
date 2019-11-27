//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

void displayFoodData(char * food,double priceFood, char drink[], double priceDrink, char username[],int drinkChoice, int noOfDrinks);
void showCutlery(int cutlery);
void showAddInfo(char info[]);
void displayOrder(char * food,double priceFood, char drink[], double priceDrink, char username[], int cutlery, char info[],int drinkChoice, int noOfDrinks);
void getOrderConfirmation(double priceFood, double priceDrink, int drinkChoice,int noOfDrinks,int *confirmed, int *state,char username[]);

#endif //FOOD_ORDERING_ORDER_H