#include <stdio.h>
#include<stdlib.h>
#include "food.h"
#include "extraPreferences.h"
#include "order.h"
#include "userIdentification.h"
#include "dataInput.h"

#define LOAD_DATA "Please load the data\n"
#define MAX_LINE 100
#define MAX_LEN 39

void readNoOfEachCategory(FILE *pFile, char line[], int *no);   // Category: food or drink

int main() {

    //User input
    char username[20], password[20], addInfo[50]="",line[MAX_LINE]="";
    char ** existingNames, ** existingPasswords;
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

    char ** food = (char**)malloc(noOfFood * sizeof(char*));
    char *** types = (char***)malloc(noOfFood * sizeof(char**));
    double ** prices = (double**)malloc(noOfFood * sizeof(double*));
    int * noOfTypes = (int*)malloc(noOfFood * sizeof(int));
    loadFoodData(fptr,noOfFood,food,types,prices,noOfTypes);

    readNoOfEachCategory(fptr,line,&noOfDrinks);

    char ** drinks = (char**)malloc(noOfDrinks * sizeof(char*));
    double * priceDrinks = (double*)malloc(noOfDrinks * sizeof(double));
    loadDrinksData(fptr,drinks,priceDrinks);

    printf("Welcome to Food Thingies!\n");
    FILE * pFile;
    pFile = fopen("D:\\CP\\food-ordering\\accounts.txt","r+");
    plainText=(char *)malloc(MAX_LEN*sizeof(char));
    cipherText=(char *)malloc(MAX_LEN*sizeof(char));

    fgets(cipherText,MAX_LINE,pFile);
    cipherText[MAX_LEN]='\0';
    fscanf(pFile,"%d",&noOfUsers);
    fgetc(pFile);

    existingNames=(char **)malloc(noOfUsers*sizeof(char*));
    existingPasswords=(char **)malloc(noOfUsers*sizeof(char*));

    readData(pFile,plainText,cipherText,noOfUsers,existingNames,existingPasswords);
    //for(int i=0;i<noOfUsers;i++)
      //  printf("%s* %s*\n",existingNames[i],existingPasswords[i]);

    while(!confirmed){
        switch(state){
            case 0:{
                signInOrUp(pFile,existingNames,&noOfUsers,username,existingPasswords,password,plainText,cipherText);
                state++;
                break;
            }
            case 1:{
                displayFoodOptions(noOfFood,food);
                foodChoice= getChoiceIndex(noOfFood,&state);
                break;
            }
            case 2:{
                displayFoodType(noOfTypes[foodChoice],food[foodChoice],types[foodChoice],prices[foodChoice]);
                typeChoice = getChoiceIndex(noOfTypes[foodChoice],&state);
                break;
            }
            case 3:{
                displayDrinkOptions(noOfDrinks,food[foodChoice],drinks,priceDrinks);
                drinkChoice = getChoiceIndex(noOfDrinks+1, &state);
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
                displayOrder(types[foodChoice][typeChoice],prices[foodChoice][typeChoice],drinks[drinkChoice], priceDrinks[drinkChoice], username, cutlery, addInfo,drinkChoice,noOfDrinks);
                getOrderConfirmation(prices[foodChoice][typeChoice], priceDrinks[drinkChoice],drinkChoice,noOfDrinks,&confirmed, &state, username);
                break;
            }
        }
    }
    fclose(fptr);
    fclose(pFile);
    freeFoodMemory(noOfFood,food,noOfTypes,types,prices);
    freeDrinksMemory(noOfDrinks, drinks,priceDrinks);
    //free(plainText);
    //free(cipherText);
    for(int i=0;i<noOfUsers;i++){
        free(existingNames[i]);
        free(existingPasswords[i]);
    }
    free(existingNames);
    free(existingPasswords);

    return 0;
}
void readNoOfEachCategory(FILE * pFile, char line[], int *no){
    fscanf(pFile,"%d %s",no,line);
    fgetc(pFile);
}