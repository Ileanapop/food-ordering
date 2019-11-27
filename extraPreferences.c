//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>


void displayDrinkOptions(int noOfDrinks, char food[], char ** drinks, double  * prices){
    printf("Please choose a drink to go with your %s:\n",food);
    for(int i=0;i<noOfDrinks;i++)
    {
        putchar('a'+i);
        printf(") %s: (%0.2f)\n",drinks[i],prices[i]);
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
void addAdditionalInformation(char info[]){
    printf("Any additional info?\n");
    gets(info);
}