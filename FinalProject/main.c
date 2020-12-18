#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "functions.h"

//* main function
int main()
{
    node_t *headNode = NULL;
    node_t *tempNode;
    //int i;
    char stringFromFile[100];
    int j;
    int choice;
    bool loggedIn = false;
    guest_t *guestData;

    /* Holder for token */
    int idHolder;
    char *titleHolder;
    char *authorHolder;
    int yearHolder;
    bool availableHolder;
    int intHolder;
    /* END of holder */

    //! START OF USING FILE
    FILE *pFile = fopen("database.txt", "r"); //* Opens file in "R" or READ mode

    while (!feof(pFile)) //! continue until reaching the end of file pFile
    {
        j = 1;
        fgets(stringFromFile, 100, pFile);

        //! START OF STRING SPLITTING
        char *token = strtok(stringFromFile, ">"); //* strtok is for splitting strings into tokens,
                                                   //* in this case we split when met with ">" character
        while (token != NULL)
        {
            switch (j)
            {
            case 1:
                //* id
                idHolder = atoi(token);
                break;

            case 2:
                //* title
                titleHolder = token;
                break;

            case 3:
                //* author
                authorHolder = token;
                break;

            case 4:
                //* release year
                yearHolder = atoi(token);
                break;

            case 5:
                //* available
                intHolder = atoi(token);

                if (intHolder = 0)
                {
                    availableHolder = false;
                }
                else
                {
                    availableHolder = true;
                }
                break;

            default:
                // default statements
                break;
            }
            token = strtok(NULL, ">");
            j++;
        } //! END OF STRING SPLITTING

        tempNode = createNode(idHolder, titleHolder, authorHolder, yearHolder, availableHolder); //* Create Node
        headNode = insertAtHead(headNode, tempNode);                                             //* Insert at Head
    }

    fclose(pFile); //* CLOSES FILE
                   //! END OF USING FILE

    printf("\n\t\t\t=================================================\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|          = Crystal of Knowledge =             |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t=================================================\n\n\n");

    printf("\t\t\t    Press any key to continue to main menu!\n");
    getch();

    system("cls");

    printf("\n\n");
    printf("\t\t\t=====  WELCOME TO THE CRYSTAL OF KNOWLEDGE  =====\n\n");
    printf("\t\t\t\tPlease Input\n\n");
    printf("\t\t\t=====  1 to Login\n\n");
    printf("\t\t\t=====  2 to Enter as guest\n\n");

    scanf("%d", &choice);
    while ((getchar()) != '\n') /* Flush buffer */
        ;

    system("cls");

    //! LOGIN
    if (choice == 1)
    {
        while (loggedIn == false)
        {

            loggedIn = logIn(loggedIn);

            if (loggedIn == false)
            {
                printf("Input 1 to reattempt login or 2 to login as guest!\n");
                scanf("%d", &choice);

                while ((getchar()) != '\n') /* Flush buffer */
                    ;

                system("cls");

                if (choice == 2)
                {
                    guestData = guestEnter();
                    break;
                }
            }
        }
    } //! END OF LOGIN

    //! ENTER AS GUEST
    else if (choice == 2)
    {
        guestData = guestEnter();
    }

    printf("\t\t\t    Press any key to continue to main menu!\n");
    getch();

    system("cls");

    //! MAIN MENU
    printf("\t\t\t=====  WELCOME TO THE CRYSTAL OF KNOWLEDGE  =====\n\n\n");

    printf("\t\t\t    __________________   __________________\n");
    printf("\t\t\t.-/|                  \\ /                  |\\-.\n");
    printf("\t\t\t||||      CRYSTAL      |                   ||||\n");
    printf("\t\t\t||||                   |       WELCOME     ||||\n");
    printf("\t\t\t||||    ============   |                   ||||\n");
    printf("\t\t\t||||                   |      WILLKOMMEN   ||||\n");
    printf("\t\t\t||||        OF         |                   ||||\n");
    printf("\t\t\t||||                   |      BIENVENUE    ||||\n");
    printf("\t\t\t||||    ============   |                   ||||\n");
    printf("\t\t\t||||                   |     TERVETUOLA    ||||\n");
    printf("\t\t\t||||     KNOWLEDGE     |                   ||||\n");
    printf("\t\t\t||||                   |                   ||||\n");
    printf("\t\t\t||||__________________ | __________________||||\n");
    printf("\t\t\t||/===================\\|/===================\\||\n");
    printf("\t\t\t`--------------------~___~-------------------''\n\n");

    printf("\n\t\t\t=================================================\n");
    printf("\t\t\t|         1.	Library Catalog                 |\n");
    printf("\t\t\t|         2.	Borrow Book(s)                  |\n");
    printf("\t\t\t|         3.	Information                     |\n");
    printf("\t\t\t|         4.	Sign Out                        |\n");
    printf("\t\t\t=================================================\n\n\n");

    printf("\t\t\tEnter Input = ");
    scanf("%d", &choice);

    while ((getchar()) != '\n') /* Flush buffer */
        ;

    system("cls");

    //!CHOICE
    //TODO: Add While loop so if one case is done it returns to main menu
    switch (choice)
    {
    case 1:
        printf("\n===\tLibrary Catalog\t===\n\n");
        printList(headNode);
        break;

    case 2:
        /* code */
        break;

    case 3:
        information();
        break;

    default:
        break;
    }

    printf("\n\t\t\t    Press any key to continue to main menu!\n");
    getch();
    return 0;
}
