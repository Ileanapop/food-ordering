//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "order.h"
#include "food.h"

#define MAX_DRINK_NAME 15
#define MAX_TYPE_NAME 25

void displayFoodData(order * item, char * username, int drinkChoice, int noOfDrinks){
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("---%s: (%0.2f)\n",item->foodChosen.name,item->foodChosen.price);
    if(drinkChoice!=noOfDrinks) {
        printf("---%s: (%0.2f)\n", item->drink.name, item->drink.price);
    }
}

void displayOrder(order * item, char * username, int cutlery, char * info,int drinkChoice, int noOfDrinks){
    displayFoodData(item,username,drinkChoice,noOfDrinks);
    showCutlery(cutlery);
    showAddInfo(info);
}

void getOrderConfirmation(double priceFood, double priceDrink,int drinkChoice,int noOfDrinks, int *confirmed, int *state,char username[]){
    char choice;
    if(drinkChoice == noOfDrinks)
        priceDrink=0;
    printf("Payment amount (%0.2f)\n",priceFood+priceDrink);
    printf("--------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
    choice = getchar();
    if(choice=='a') {
        *confirmed = 1;
        printf("Order confirmed! Thank you for buying from us, %s!\n",username);
    }
    else{
        (*state)--;
    }
    getchar();
}

order createOrder(char * specificFood, double priceFood, char * drinkChosen, double priceDrink, int drinkChoice, int noOfDrinks){
    order item;
    item.foodChosen.name=(char *)malloc(MAX_TYPE_NAME * sizeof(char));
    item.drink.name = (char *)malloc(MAX_DRINK_NAME * sizeof(char));
    strcpy(item.foodChosen.name,specificFood);
    if(drinkChoice!=noOfDrinks) {
        item.drink.price = priceDrink;
        strcpy(item.drink.name, drinkChosen);
    }
    else {
        item.drink.price = 0;
        strcpy(item.drink.name, "");
    }
    item.foodChosen.price=priceFood;
    return item;
}
void showAddInfo(char info[]){
    if(strcmp(info,"")!=0) {
        printf("Additional info: %s\n", info);
    }
}
void showCutlery(int cutlery){
    if(cutlery==1) {
        printf("Cutlery: ");
        printf("yes\n");
    }
}