//
// Created by ileana on 11/6/2019.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "food.h"
#include "type.h"

#define MAX_FOOD_NAME 20
#define MAX_LINE 100
#define MAX_TYPE_NAME 25

food createFood();
void parseLineFood(char * line, int i, food * foods);
void readType(char * line, char * type, int * no);

void loadFoodData(FILE * pFile, int noOfFood,food * foods){
    char line[MAX_LINE];
    for(int i=0;i<noOfFood;i++){
        fgets(line,MAX_LINE,pFile);
        foods[i]= createFood();
        //foods[i].name = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        parseLineFood(line,i,foods);
    }
}

void parseLineFood(char * line, int i, food * foods){
    char *str="";
    readType(line,foods[i].name,&(foods[i].noOfTypes));
    foods[i].types = (type *)malloc(foods[i].noOfTypes * sizeof(type));
    for (int j = 0; j < foods[i].noOfTypes; j++) {
        foods[i].types[j].name = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        if(j==0)
            str=strtok(line,"(");
        else
            str=strtok(NULL,"(");
        readSpecificFoodsAndPrice(str,foods[i].types[j].name, &(foods[i].types[j].price));
    }
}

void readType(char * line, char * type, int * no){
    int i=0;
    while(line[i]!=' '){
        type[i]=line[i];
        i++;
    }
    type[i]='\0';
    i++;
    *no=0;
    while(line[i]!=':'){
        *no= (*no)*10+line[i]-'0';
        i++;
    }
    strcpy(line,line+i+2);  // delete the type of food, the character :  and the space following it
}

void displayFoodOptions(int noOfFood, food * foods){
    printf("Please choose the food you feel like eating today:\n");
    for(int i=0;i<noOfFood;i++)
    {
        putchar('a'+i);
        printf(") %s\n",foods[i].name);
    }
    printf("%c) Go back\n",'a'+noOfFood);
}

void freeFood(food * foods, int noOfFood){
    for(int i=0;i<noOfFood;i++) {
        for (int j = 0; j < foods[i].noOfTypes; j++) {
            freeType(&(foods[i].types[j]));
        }
        free(foods[i].types);
        free(foods[i].name);
    }
    free(foods);
}

food createFood(){
    food f;
    f.name = (char *) malloc(MAX_FOOD_NAME * sizeof(char));
    f.types = NULL;
    return f;
}
