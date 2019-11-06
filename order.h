//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_ORDER_H
#define FOOD_ORDERING_ORDER_H

void displayFoodData(char food[],double priceFood, char drink[], double priceDrink, char username[]);
void showCutlery(int cutlery);
void showAddInfo(char info[]);
void getOrderConfirmation(double priceFood, double priceDrink, int *confirmed, int *state,char username[]);

#endif //FOOD_ORDERING_ORDER_H
