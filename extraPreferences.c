//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "type.h"

#define MAX_DRINK_NAME 15
#define MAX_LINE 100

void loadDrinksData(FILE * pFile, type * drinks){
    char line[MAX_LINE],*p;
    fgets(line,MAX_LINE,pFile);
    int crtDrinkNo=0;   //no of the drink read at the moment
    for(p=strtok(line,"(");p!=0;p=strtok(NULL,"(")){
        drinks[crtDrinkNo].name = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        readSpecificFoodsAndPrice(p,drinks[crtDrinkNo].name,&(drinks[crtDrinkNo].price));
        crtDrinkNo++;
    }
}
void displayDrinkOptions(int noOfDrinks, char * food, type * drinks){
    printf("Please choose a drink to go with your %s:\n",food);
    for(int i=0;i<noOfDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s: (%0.2f)\n",drinks[i].name,drinks[i].price);
    }
    printf("%c) No, thanks!\n",'a'+noOfDrinks);
    printf("%c) Go back\n",'a'+noOfDrinks+1);
}

void displayCutlery(){
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No, thanks!\n");
    printf("c) Go back\n");
}
void addAdditionalInformation(char * info){
    printf("Any additional info?\n");
    gets(info);
}
