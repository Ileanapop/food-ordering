//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>
#include<string.h>

void displayFoodData(char * food,double priceFood, char drink[], double priceDrink, char username[], int drinkChoice, int noOfDrinks){
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("---%s: (%0.2f)\n",food,priceFood);
    if(drinkChoice!=noOfDrinks) {
        printf("---%s: (%0.2f)\n", drink, priceDrink);
    }
}

void showCutlery(int cutlery){
    if(cutlery==1) {
        printf("Cutlery: ");
        printf("yes\n");
    }
}

void showAddInfo(char info[]){
    if(strcmp(info,"")!=0) {
        printf("Additional info: %s\n", info);
    }
}

void displayOrder(char * food,double priceFood, char drink[], double priceDrink, char username[], int cutlery, char info[],int drinkChoice, int noOfDrinks){
    displayFoodData(food,priceFood,drink,priceDrink,username,drinkChoice,noOfDrinks);
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