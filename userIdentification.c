//
// Created by ileana on 11/6/2019.
//

#include<stdio.h>
#include<string.h>
#include <ctype.h>

#include<stdlib.h>

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

#define MAX_LEN 39
#define MAX_LINE 100

void signingIn(FILE * fptr, char ** existingNames,int noOfUsers,char username[],char ** existingPasswords, char password[],char * plainText, char *cipherText);
void singingUp(char ** users, int noOfUsers, char username[],char password[]);
void addNewUser(char ** existingUsers, char ** existingPasswords, int noOfUsers, char username[], char password[], char * plainText, char * cipherText);


void generateCharacters(char * plainText);
void decrypt(char * plainText, char * cipherText, char password[]);
void encrypt(char * plainText, char * cipherText, char password[]);

void signInOrUp(FILE * fptr, char ** existingNames,int *noOfUsers,char username[], char ** existingPasswords,char password[], char * plainText, char * cipherText){
    printf(SIGN_IN_UP);
    printf("a) %s",SIGN_IN);
    printf("b) %s",SIGN_UP);
    char c = getchar();
    getchar();
    if (c == 'a'){
        signingIn(fptr, existingNames,*noOfUsers,username,existingPasswords,password,plainText,cipherText);
    }
    else {
        singingUp(existingNames, *noOfUsers, username, password);
        (*noOfUsers)++;
        fseek(fptr,41,SEEK_SET);
        fprintf(fptr,"%d",*noOfUsers);
        fclose(fptr);
        fptr = fopen("D:\\CP\\food-ordering\\accounts.txt","a");
        addNewUser(existingNames,existingPasswords,*noOfUsers,username,password,plainText,cipherText);
        fprintf(fptr,"\n%s %s",username,password);
        fclose(fptr);
        fptr = fopen("D:\\CP\\food-ordering\\accounts.txt","r+");
    }
}

void signingIn(FILE * fptr, char  ** existingNames,int noOfUsers,char username[],char ** existingPasswords, char password[],char * plainText, char * cipherText){
    printf(SIGNING_IN);
    printf("---Username\n");
    gets(username);
    printf("---Password\n");
    char pass[50];
    gets(pass);
    if(validUsername(existingNames, noOfUsers,username, existingPasswords,password)==0){
        printf(USER_NOT_FOUND);
        signInOrUp(fptr,existingNames,&noOfUsers,username, existingPasswords,password,plainText,cipherText);
    }
    else {
        if (strcmp(pass, password) != 0) {
            printf(INCORRECT_PASSWORD);
            signingIn(fptr, existingNames, noOfUsers, username, existingPasswords, password,plainText,cipherText);
        }
    }
}

void singingUp(char ** users, int noOfUsers, char username[],char password[]){
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

void addNewUser(char ** existingUsers, char ** existingPasswords, int noOfUsers, char username[], char password[], char * plainText, char * cipherText){
    //printf("Memory Address existing users before realloc: %p\n",existingUsers);
    existingUsers= (char **)realloc(existingUsers,noOfUsers*sizeof(char*));
    //printf("Memory Address existing users after realloc: %p\n",existingUsers);
    existingUsers[noOfUsers-1] = NULL;
    for(int i=0;i<noOfUsers;i++) {
        existingUsers[i] = (char *) realloc(existingUsers[i], MAX_USERNAME * sizeof(char));
    }
    strcpy(existingUsers[noOfUsers-1],username);
    //printf("Memory Address existing passwords before realloc: %p\n",existingPasswords);
    existingPasswords= (char **)realloc(existingPasswords,noOfUsers*sizeof(char*));
    existingPasswords[noOfUsers-1] = NULL;
    for(int i=0;i<noOfUsers;i++) {
        existingPasswords[i] = (char *) realloc(existingPasswords[i], MAX_USERNAME * sizeof(char));
    }
    //printf("Memory Address existing passwords after realloc: %p\n",existingPasswords);
    encrypt(plainText,cipherText,password);
    strcpy(existingPasswords[noOfUsers-1],password);
}
void readData(FILE * fptr,char * plainText, char * cipherText, int noOfUsers,char ** usernames, char ** passwords){

    generateCharacters(plainText);
    char line[MAX_LINE];
    for(int i=0;i<noOfUsers;i++)
    {
        fgets(line,MAX_LINE,fptr);
        char *p;
        p=strtok(line," ");
        usernames[i]=(char *)malloc(MAX_USERNAME*sizeof(char));
        strcpy(usernames[i],p);
        p=strtok(NULL," \n");
        passwords[i]=(char *)malloc(MAX_USERNAME*sizeof(char));
        decrypt(plainText,cipherText,p);
        strcpy(passwords[i],p);
    }
}

void generateCharacters(char * plainText){
    for(int i=0;i<26;i++){
        plainText[i]=((char)'a'+i);
    }
    plainText[26]='0';
    plainText[27]='1';
    plainText[28]='2';
    plainText[29]='3';
    plainText[30]='4';
    plainText[31]='5';
    plainText[32]='6';
    plainText[33]='7';
    plainText[34]='8';
    plainText[35]='9';
    plainText[36]='.';
    plainText[37]='_';
    plainText[38]='!';
    plainText[39]='\0';
}

void decrypt(char * plainText, char * cipherText, char password[]){
    for(unsigned int i=0;i<strlen(password);i++)
    {
        char * p =strchr(cipherText,password[i]);
        int pos=p-cipherText;
        password[i]=plainText[pos];
    }
}

void encrypt(char * plaintext, char * ciphertext, char password[]){
    for(unsigned int i=0;i<strlen(password);i++)
    {
        char * p =strchr(plaintext,password[i]);
        int pos=p-plaintext;
        password[i]=ciphertext[pos];
    }
}