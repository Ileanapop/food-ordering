//
// Created by ileana on 11/24/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_FOOD_NAME 20
#define MAX_TYPE_NAME 25
#define MAX_LINE 100
#define MAX_DRINK_NAME 15

void parseLineFood(char * line, int i, char ** food, char *** types, double ** prices, int *noOfTypes);
void readType(char * line, char * type, int *no);
void readSpecificFoodsAndPrice(char * line, char * type, double *price);
double returnPrice(char * str);
unsigned int returnPositionOfLastDelimiter(char * str, char delimiter);

void loadFoodData(FILE * pFile, int noOfFood,char ** food, char *** types, double ** prices, int *noOfTypes){
    char line[MAX_LINE];
    for(int i=0;i<noOfFood;i++){
        fgets(line,MAX_LINE,pFile);
        food[i] = (char*)malloc(MAX_FOOD_NAME* sizeof(char));
        parseLineFood(line,i,food,types,prices,noOfTypes);
    }
}

void loadDrinksData(FILE * pFile, char ** drinks, double * prices){
    char line[MAX_LINE],*p;
    fgets(line,MAX_LINE,pFile);
    int crtDrinkNo=0;   //no of the drink read at the moment
    for(p=strtok(line,"(");p!=0;p=strtok(NULL,"(")){
        drinks[crtDrinkNo] = (char*)malloc(MAX_DRINK_NAME * sizeof(char));
        readSpecificFoodsAndPrice(p,drinks[crtDrinkNo],&prices[crtDrinkNo]);
        crtDrinkNo++;
    }
}

void parseLineFood(char * line, int i, char ** food,char *** types, double ** prices, int *noOfTypes){
    char *str="";
    readType(line,food[i],&noOfTypes[i]);
    types[i] = (char**)malloc(noOfTypes[i] * sizeof(char*));
    prices[i] = (double*)malloc(noOfTypes[i] * sizeof(double));
    for (int j = 0; j < noOfTypes[i]; j++) {
        types[i][j] = (char *) malloc(MAX_TYPE_NAME * sizeof(char));
        if(j==0)
            str=strtok(line,"(");
        else
            str=strtok(NULL,"(");
        readSpecificFoodsAndPrice(str,types[i][j], &prices[i][j]);
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

unsigned int returnPositionOfLastDelimiter(char * str, char delimiter){
    unsigned int k;
    for(unsigned int i=strlen(str)-1;i>=0;i--){
        if(str[i]==delimiter)  {                           // with this function we can find the last position of
            k=i;                                    // the delimiter '-' in case of having more than one delimiters '-'
            break;                                      // and they can be in the name of the food type or drink
        }                                                        // eg: coca-cola
    }
    return k;
}

void readSpecificFoodsAndPrice(char * line, char * type, double *price){
    unsigned int k=returnPositionOfLastDelimiter(line,'-');
    strncpy(type,line,k);
    type[k-1]='\0';
    strcpy(line,line+k+2);    //copy in string line the left part of '-' which is the price and then extract it
    *price = returnPrice(line);
}

double returnPrice(char * str){
    int i=0;
    double price=0;
    while(str[i]!='.' && str[i]!=')') {
        price = price * 10 + str[i] - '0';
        i++;
    }
    if(str[i]=='.'){         // the format of the price can be for example 13.55
        int p=1;
        i++;
        while(str[i]!=')'){
            p=p*10;
            price = price * 10+str[i]-'0';
            i++;
        }
        price=price/p;
    }
    return price;
}

void freeFoodMemory(int noOfFood, char ** food, int * noOfTypes, char *** types, double ** prices){
    for(int i=0;i<noOfFood;i++){
        for(int j=0;j<noOfTypes[i];j++){
            free(types[i][j]);
        }
        free(types[i]);
        free(prices[i]);
        free(food[i]);
    }
    free(types);
    free(prices);
    free(food);
    free(noOfTypes);
}

void freeDrinksMemory(int noOfDrinks, char ** drinks, double * priceDrinks){
    for(int i=0;i<noOfDrinks;i++) {
        free(drinks[i]);
    }
    free(drinks);
    free(priceDrinks);
}