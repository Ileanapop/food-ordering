//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>

void inputPersonalData(char username[], char password[]){
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    gets(password);
}
int getChoiceIndex(int noOfChoices, int *state) {
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