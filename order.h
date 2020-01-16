//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

#include "type.h"
#include "food.h"

typedef struct _order {
    type foodChosen;
    type drink;
}order;

void displayFoodData(order * item, char * username,int drinkChoice, int noOfDrinks);
order createOrder(char * specificFood, double priceFood, char * drink, double priceDrink, int drinkChoice, int noOfDrinks);
void displayOrder(order * item, char * username, int cutlery, char * info,int drinkChoice, int noOfDrinks);
void getOrderConfirmation(double priceFood, double priceDrink, int drinkChoice,int noOfDrinks,int *confirmed, int *state,char username[]);
void showCutlery(int cutlery);
void showAddInfo(char info[]);

#endif //FOOD_ORDERING_ORDER_H