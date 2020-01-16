//
// Created by ileana on 11/24/2019.
//

#ifndef FOOD_ORDERING_TYPE_H
#define FOOD_ORDERING_TYPE_H



typedef struct _type {
    char * name;
    double price;
}type;


void readSpecificFoodsAndPrice(char * line, char * type, double *price);
void displayFoodType(int noOfTypes, char * food,type * types);
void freeType(type * types);

#endif //FOOD_ORDERING_TYPE_H
