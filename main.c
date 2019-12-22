#include <stdio.h>
#include<stdlib.h>
#include "food.h"
#include "extraPreferences.h"
#include "order.h"
#include "user.h"
#include "type.h"

#define LOAD_DATA "Please load the data\n"
#define MAX_LINE 100
#define MAX_LEN 39


void readNoOfEachCategory(FILE *pFile, char line[], int *no);   // Category: food or drink
void freeData(int noOfFood, food * foods, type * drinks);
int getChoiceIndex(int noOfChoices, int *state);

int main() {

    // User input
    char username[20], password[20], addInfo[50]="",line[MAX_LINE]="";
    char *plainText,*cipherText;
    int noOfUsers;
    int state=0, confirmed=0;
    int foodChoice, drinkChoice, typeChoice, cutlery=0;
    // Food data
    int noOfFood,noOfDrinks;

    FILE *fptr;
    fptr = fopen("D:\\CP\\food-ordering\\data.txt","r");
    if(fptr==NULL){
        printf(LOAD_DATA);
        fptr=stdin;
    }
    readNoOfEachCategory(fptr,line,&noOfFood);
    food *foods = (food *)malloc(noOfFood*sizeof(food));

    loadFoodData(fptr,noOfFood,foods);

    readNoOfEachCategory(fptr,line,&noOfDrinks);

    type * drinks = (type *)malloc(noOfDrinks* sizeof(type));

    loadDrinksData(fptr,drinks);

    printf("Welcome to Food Thingies!\n");
    FILE * pFile;
    pFile = fopen("D:\\CP\\food-ordering\\accounts.txt","r+");
    plainText=(char *)malloc(MAX_LEN*sizeof(char));
    cipherText=(char *)malloc(MAX_LEN*sizeof(char));

    fgets(cipherText,MAX_LINE,pFile);
    cipherText[MAX_LEN]='\0';
    fscanf(pFile,"%d",&noOfUsers);
    fgetc(pFile);

    user * existingUsers = (user *)malloc(noOfUsers*sizeof(user));

    readData(pFile,plainText,cipherText,noOfUsers,existingUsers);

    enum State {
        SIGN_IN, CHOOSE_FOOD, CHOOSE_TYPE, CHOOSE_DRINK, CHOOSE_CUTLERY, INPUT_ADD_INFO, CONFIRM_ORDER
    };

    while(!confirmed){
        switch(state){
            case SIGN_IN:{
                signInOrUp(pFile,&existingUsers,&noOfUsers,username,password,plainText,cipherText);
                state++;
                break;
            }
            case CHOOSE_FOOD:{
                displayFoodOptions(noOfFood,foods);
                foodChoice= getChoiceIndex(noOfFood,&state);
                break;
            }
            case CHOOSE_TYPE:{
                displayFoodType(foods[foodChoice].noOfTypes,foods[foodChoice].name,foods[foodChoice].types);
                typeChoice = getChoiceIndex(foods[foodChoice].noOfTypes,&state);
                break;
            }
            case CHOOSE_DRINK:{
                displayDrinkOptions(noOfDrinks,foods[foodChoice].name,drinks);
                drinkChoice = getChoiceIndex(noOfDrinks+1, &state);
                break;
            }
            case CHOOSE_CUTLERY:{
                displayCutlery();
                cutlery=getChoiceIndex(2,&state)+1;
                break;
            }
            case INPUT_ADD_INFO:{
                addAdditionalInformation(addInfo);
            }
            case CONFIRM_ORDER:{
                order item = createOrder(foods[foodChoice].types[typeChoice].name,foods[foodChoice].types[typeChoice].price,drinks[drinkChoice].name, drinks[drinkChoice].price,drinkChoice,noOfDrinks);
                displayOrder(&item, username, cutlery, addInfo,drinkChoice,noOfDrinks);
                getOrderConfirmation(foods[foodChoice].types[typeChoice].price, drinks[drinkChoice].price,drinkChoice,noOfDrinks,&confirmed, &state, username);
                break;
            }
        }
    }
    fclose(fptr);
    fclose(pFile);
    freeData(noOfFood,foods,drinks);
    freeUsers(existingUsers,noOfUsers);
    return 0;
}

int getChoiceIndex(int noOfChoices, int *state){
    int choiceIndex;
    char choice = getchar();
    // consume new line
    getchar();
    choiceIndex = choice-'a';
    if(choice == 'a'+noOfChoices) {
        (*state)--; // *state-- <=> *(state--)
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

void readNoOfEachCategory(FILE * pFile, char line[], int *no){
    fscanf(pFile,"%d %s",no,line);
    fgetc(pFile);
}

void freeData(int noOfFood, food * foods, type * drinks){
    freeFood(foods, noOfFood);
    freeType(drinks);
    free(drinks);
}