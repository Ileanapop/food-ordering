//
// Created by ileana on 12/6/2019.
//
#include<stdio.h>
#include<string.h>
#include <ctype.h>

#define MAX_USERNAME 50
#define MIN_LENGTH 7
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username\n"

int validUsername(char existingNames[][MAX_USERNAME],int noOfUsers, char username[],char existingPasswords[][MAX_USERNAME], char password[]) {
    for (int i = 0; i < noOfUsers; i++) {
        if (strcmp(existingNames[i], username) == 0) {
            strcpy(password,existingPasswords[i]);
            return 1;
        }
    }
    return 0;
}

int verifyDuplicateUser(char users[][MAX_USERNAME], int noOfUsers, char username[]){
    for(int i=0;i<noOfUsers;i++) {
        if (strcmp(username, users[i]) == 0)
            return 0;
    }
    return 1;
}
int isLength(char s[]) {
    return strlen(s) >= MIN_LENGTH;
}
int containsUsername(char password[], char username[]){
    if(strstr(password,username)==0)
        return 1;
    printf(ERROR_PASSWORD_NOT_USERNAME);
    return 0;
}
int containsSpecialCharacters(char s[]){
    if(strchr(s,'.') || strchr(s,'_') || strchr(s,'!'))
        return 1;
    return 0;
}
int containsDigits(char s[]){
    for(unsigned int i=0;i<=strlen(s);i++) {
        if (isdigit(s[i]))
            return 1;
    }
    return 0;
}
int validate(int (*fulfillsCondition)(char []), char password[], char message[]) {
    if (fulfillsCondition(password)) {
        return 1;
    } else {
        printf("%s",message);
    }
    return 0;
}