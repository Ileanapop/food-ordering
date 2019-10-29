#include <stdio.h>

int main() {
    printf("Welcome to Food Thingies!\n");

    //User input
    char username[20];
    char password[20];
    int state=0;
    int confirmed=0;
    int choice,foodChoice,drinkChoice;
    char addInfo[50];

    // Food data
    int noOfFood=3;
    char food[][15]={"Pizza","Pasta","Salad"};
    int noOfTypes[5]={3,2,3};
    char type[3][4][17]={
            {"Pizza Carbonara","Pizza Diavola","Pizza Margherita"},
            {"Chicken alfredo","Mac&cheese"},
            {"Tuna Salad","Chicken Salad","Greek Salad","Cobb"}};
    double prices[3][4]={
            {21, 23, 19},
            {23, 21},
            {23, 22, 19, 21}};
    int typeChoice,noOfDrinks=4;
    char drinks[][10]={"Coca-cola","Fanta","Lipton","Water"};
    double priceDrinks[6]={5,5,5,4};
    int cutlery=0;

    while(!confirmed)
    {
        switch(state)
        {
            case 0:
            {
                //User Authentification
                printf("Please sign in to continue!\n");
                printf("---Username\n");
                gets(username);
                printf("---Password\n");
                gets(password);
                state++;
                break;
            }
            case 1:
            {
                //Choose the food
                printf("Please choose the food you feel like eating today:\n");
                for(int i=0;i<noOfFood;i++)
                {
                    putchar('a'+i);
                    printf(") %s\n",food[i]);
                }
                printf("%c) Go back\n",'a'+noOfFood);
                choice = getchar();
                getchar();
                if(choice=='a'+noOfFood)
                {
                    state--;
                    break;
                }
                foodChoice=choice-'a';
                state++;
                break;
            }
            case 2:
            {
                //Type of the previously chosen food
                printf("Please choose the type of %s: \n",food[foodChoice]);
                for(int i=0;i<noOfTypes[foodChoice];i++)
                {
                    putchar('a'+i);
                    printf(") %s (%0.2f)\n",type[foodChoice][i],prices[foodChoice][i]);
                }
                printf("%c) Go back\n",noOfTypes[foodChoice]+'a');
                choice=getchar();
                getchar();
                if(choice==noOfTypes[foodChoice]+'a')
                {
                    state--;
                    break;
                }
                state++;
                typeChoice=choice-'a';
            }
            case 3:
            {
                //Choose the type of drink
                printf("Please choose a drink to go with your %s:\n",food[foodChoice]);
                for(int i=0;i<noOfDrinks;i++)
                {
                    putchar('a'+i);
                    printf(") %s (%0.2f)\n",drinks[i],priceDrinks[i]);
                }
                printf("%c) Go back\n",'a'+noOfDrinks);
                choice=getchar();
                getchar();
                if(choice=='a'+noOfDrinks)
                {
                    state--;
                    break;
                }
                state++;
                drinkChoice=choice-'a';
                break;
            }
            case 4:
            {
                //Cutlery
                printf("Do you want cutlery?\n");
                printf("a) Yes\n");
                printf("b) No, thanks!\n");
                printf("c) Go back\n");
                choice=getchar();
                getchar();
                if(choice=='c')
                {
                    state--;
                    break;
                }
                else
                    if(choice=='a')
                        cutlery=1;
                    else
                        cutlery=0;
                state++;
                break;
            }
            case 5:
            {
                //Additional info
                printf("Any additional info?\n");
                gets(addInfo);
            }
            case 6:
            {
                //Display Order
                printf("This is your order:\n");
                printf("-------------------\n");
                printf("Name: %s\n", username);
                printf("Food items:\n");
                printf("---%s: (%0.2f)\n",type[foodChoice][typeChoice],prices[foodChoice][typeChoice]);
                printf("---%s: (%0.2f)\n",drinks[drinkChoice],priceDrinks[drinkChoice]);
                printf("Cutlery: ");
                if(cutlery==1)
                    printf("yes\n");
                else
                    printf("no\n");
                printf("Additional info: %s\n",addInfo);
                printf("Payment amount (%0.2f)\n",prices[foodChoice][typeChoice]+priceDrinks[drinkChoice]);
                printf("--------------------\n");
                printf("a) Confirm order\n");
                printf("b) Go back\n");
                choice = getchar();
                if(choice=='a') {
                    confirmed = 1;
                    printf("Order confirmed! Thank you for buying from us, %s!\n",username);
                }
                else{
                    state--;
                }
                getchar();
                break;
            }
        }
    }
    return 0;
}