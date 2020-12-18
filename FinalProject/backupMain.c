#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "structures.c"

// typedef enum // enum
// {
//     false = 0,
//     true = 1
// } Bool;

int main()
{

    int n;
    int choice;
    bool *loggedIn;
    *loggedIn = false;

    printf("\n\t\t\t=================================================\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|          = Crystal of Knowledge =             |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t=================================================\n\n\n");

    printf("\t\t\t=====WELCOME TO THE CRYSTAL OF KNOWLEDGE=====\n");

    printf("\t\t\t=====1.) Login\t\t=====\n\n");
    printf("\t\t\t=====2.) Books Catalog\t=====\n\n");
    printf("\t\t\t=====3.) Log Out\t\t=====\n\n");
    printf("\t\t\t=====4.) Information\t\t=====\n\n");
    printf("\t\t\t=====5.) Exit\t\t=====\n\n");
    printf("Enter Input = ");
    scanf("%d", &n);

    switch (choice)
    {
    case 1:
        logIn(loggedIn);
        break;

    case 2:
        // print Catalog
        break;

    case 3:
        // logout
        break;

    case 4:
        information();
        break;

    default:
        break;
    }

    // if (var == true)
    // {
    //     /* code */
    //     printf("Correct");
    // }

    return 0;
}

void information()
{
}

void logIn(bool *loggedIn)
{
    char username[20];
    char password[6];
    int i;

    printf("Enter your username : ");
    scanf("%s", username);

    printf("Enter your password : ");
    for (i = 0; i < 6; i++)
    {
        password[i] = getch();
        printf("*");
    }
    password[i] = '\0';

    if (!strcmp(username, "admin") && !strcmp(password, "abcdef"))
    {
        printf("\n\nLogged In Successful");
        *loggedIn = true;
    }
    else
    {
        printf("\n\nIncorrect username or password\n");
        printf("Enter any key to continue...");
        getch();
        system("cls");
        main();
    }
}