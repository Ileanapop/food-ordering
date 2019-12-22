//
// Created by ileana on 12/6/2019.
//

#ifndef FOOD_ORDERING_VALIDATIONRULES_H
#define FOOD_ORDERING_VALIDATIONRULES_H
#define MAX_USERNAME 50

#include "user.h"

int validUsername(user * existingUsers,int noOfUsers, char username[],char password[]);
int verifyDuplicateUser(user * existingUsers, int noOfUsers, char username[]);
int isLength(char s[]);
int containsUsername(char password[], char username[]);
int containsSpecialCharacters(char s[]);
int containsDigits(char s[]);
int validate(int (*fulfillsCondition)(char []), char password[], char message[]);

#endif //FOOD_ORDERING_VALIDATIONRULES_H
