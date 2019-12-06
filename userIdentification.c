//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include "validationRules.h"

#define SIGN_IN_UP "Do you want to sign in or sign up?\n"
#define SIGN_IN "Sign in\n"
#define SIGN_UP "Sign up\n"
#define SIGNING_IN "Signing in!\n"
#define SIGNING_UP "Signing up!\n"
#define USER_NOT_FOUND "Username doesn't exist\n"
#define INCORRECT_PASSWORD 	"Incorrect password\n"
#define DUPLICATE_USER "Please choose another username!\n"
#define MAX_USERNAME 50
#define ERROR_PASSWORD_LONG "The password must be at least 7 chars long\n"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}\n"
#define ERROR_PASSWORD_DIGITS "The password must contain digits\n"

void signingIn(char existingNames[][MAX_USERNAME],int noOfUsers,char username[],char existingPasswords[][MAX_USERNAME], char password[]);
void singingUp(char users[][MAX_USERNAME], int noOfUsers, char username[],char password[]);
void addNewUser(char existingUsers[][MAX_USERNAME], char existingPasswords[][MAX_USERNAME], int noOfUsers, char username[], char password[]);


void signInOrUp(char existingNames[][MAX_USERNAME],int *noOfUsers,char username[], char existingPasswords[][MAX_USERNAME],char password[]) {
    printf(SIGN_IN_UP);
    printf("a) %s",SIGN_IN);
    printf("b) %s",SIGN_UP);
    char c = getchar();
    getchar();
    if (c == 'a'){
        signingIn(existingNames,*noOfUsers,username,existingPasswords,password);
    }
    else {
        singingUp(existingNames, *noOfUsers, username, password);
        (*noOfUsers)++;
        addNewUser(existingNames,existingPasswords,*noOfUsers,username,password);
    }
}

void signingIn(char  existingNames[][MAX_USERNAME],int noOfUsers,char username[],char existingPasswords[][MAX_USERNAME], char password[]){
    printf(SIGNING_IN);
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    char pass[50];
    gets(pass);
    if(validUsername(existingNames, noOfUsers,username, existingPasswords,password)==0){
        printf(USER_NOT_FOUND);
        signInOrUp(existingNames,&noOfUsers,username, existingPasswords,password);
    }
    else {
        if (strcmp(pass, password) != 0) {
            printf(INCORRECT_PASSWORD);
            signingIn(existingNames, noOfUsers, username, existingPasswords, password);
        }
    }
}

void singingUp(char users[][MAX_USERNAME], int noOfUsers, char username[],char password[]){
    printf(SIGNING_UP);
    printf("---Username\n");
    gets(username);
    while(verifyDuplicateUser(users,noOfUsers, username)==0){
        printf(DUPLICATE_USER);
        printf("---Username\n");
        gets(username);
    }
    printf("---Password\n");
    gets(password);
    int isOk=validate(&isLength, password, ERROR_PASSWORD_LONG) && containsUsername(password,username) && validate(&containsSpecialCharacters, password, ERROR_PASSWORD_SPECIAL_CHAR) && validate(&containsDigits,password,ERROR_PASSWORD_DIGITS);
    while(isOk==0){
        printf("---Password\n");
        gets(password);
        isOk=validate(&isLength, password, ERROR_PASSWORD_LONG) && containsUsername(password,username) && validate(&containsSpecialCharacters, password, ERROR_PASSWORD_SPECIAL_CHAR) && validate(&containsDigits,password,ERROR_PASSWORD_DIGITS);
    }
}

void addNewUser(char existingUsers[][50], char existingPasswords[][MAX_USERNAME], int noOfUsers, char username[], char password[]){
    strcpy(existingUsers[noOfUsers-1],username);
    strcpy(existingPasswords[noOfUsers-1],password);
}