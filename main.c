#include <stdio.h>

#include "food.h"
#include "extraPreferences.h"
#include "order.h"
#include "input.h"

#define MAX_FOOD_NAME 15
#define MAX_TYPE_NAME 17  //food type
#define MAX_DRINK_NAME 15

int main() {

    //User input
    char username[20], password[20], addInfo[50]="";
    int state=0, confirmed=0;
    int foodChoice, drinkChoice, typeChoice, cutlery=0;
    // Food data
    int noOfFood=3, noOfTypes[5]={3,2,4},noOfDrinks=5;
    char food[][MAX_FOOD_NAME]={"Pizza","Pasta","Salad"};
    char type[3][4][MAX_TYPE_NAME]={
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}};
    char drinks[][MAX_DRINK_NAME]={"Coca-cola","Fanta","Lipton","Water","No, thanks!"};
    double prices[3][4]={
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}};
    double priceDrinks[7]={5,5,5,4,0};

    while(!confirmed){
        switch(state){
            case 0:{
                inputPersonalData(username, password);
                state++;
                break;
            }
            case 1:{
                displayFoodOptions(noOfFood,food);
                foodChoice= getChoiceIndex(noOfFood,&state);
                break;
            }
            case 2:{
                displayFoodType(noOfTypes[foodChoice],food[foodChoice],type[foodChoice],prices[foodChoice]);
                typeChoice = getChoiceIndex(noOfTypes[foodChoice],&state);
                break;
            }
            case 3:{
                displayDrinkOptions(noOfDrinks,food[foodChoice],drinks,priceDrinks);
                drinkChoice = getChoiceIndex(noOfDrinks, &state);
                break;
            }
            case 4:{
                displayCutlery();
                cutlery=getChoiceIndex(2,&state)+1;
                break;
            }
            case 5:{
                addAdditionalInformation(addInfo);
            }
            case 6:{
                displayOrder(type[foodChoice][typeChoice],prices[foodChoice][typeChoice],drinks[drinkChoice], priceDrinks[drinkChoice], username, cutlery, addInfo);
                getOrderConfirmation(prices[foodChoice][typeChoice], priceDrinks[drinkChoice], &confirmed, &state, username);
                break;
            }
        }
    }
    return 0;
}