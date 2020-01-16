//
// Created by ileana on 11/24/2019.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "type.h"


#define MAX_LINE 100

double returnPrice(char * str);
unsigned int returnPositionOfLastDelimiter(char * str, char delimiter);


void readSpecificFoodsAndPrice(char * line, char * type, double *price){
    unsigned int k=returnPositionOfLastDelimiter(line,'-');
    strncpy(type,line,k);
    type[k-1]='\0';
    strcpy(line,line+k+2);    //copy in string line the left part of '-' which is the price and then extract it
    *price = returnPrice(line);
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

void displayFoodType(int noOfTypes, char * food,type * types){
    printf("Please choose the type of %s: \n",food);
    for(int i=0;i<noOfTypes;i++)
    {
        putchar('a'+i);
        printf(") %s: (%0.2f)\n",types[i].name,types[i].price);
    }
    printf("%c) Go back\n",noOfTypes+'a');
}

void freeType(type * types){
    free(types->name);
}
