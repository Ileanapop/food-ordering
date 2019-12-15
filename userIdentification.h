//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_USERIDENTIFICATION_H
#define FOOD_ORDERING_USERIDENTIFICATION_H


void signInOrUp(FILE * fptr, char ** existingNames,int *noOfUsers,char username[],char ** existingPasswords, char password[], char * plainText, char * cipherText);
void readData(FILE * fptr,char * plainText, char * cipherText, int noOfUsers,char ** usernames, char ** passwords);

#endif //FOOD_ORDERING_USERIDENTIFICATION_H
