//
// Created by ileana on 11/6/2019.
//

#ifndef FOOD_ORDERING_USER_H
#define FOOD_ORDERING_USER_H


typedef struct _user{
    char * username;
    char * password;
}user;

void signInOrUp(FILE * fptr, user ** existingUsers,int *noOfUsers,char * username, char * password, char * plainText, char * cipherText);
void readData(FILE * fptr,char * plainText, char * cipherText, int noOfUsers,user * existingUsers);
void freeUsers(user * users, int noOfUsers);


#endif //FOOD_ORDERING_USER_H
