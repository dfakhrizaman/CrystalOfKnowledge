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
    int choice;
    bool loggedIn = false;
    guest_t *guestData;
    int wantedBookId;
    bool confirmBorrow = false;
    int intConfirm;

    headNode = importFile(headNode, tempNode);

    printCrystalOfKnowledge();

    printList(headNode);
    headNode = reverseList(headNode);
    printf("===================\n");
    printList(headNode);

    printf("\t\t\t    Press any key to continue to main menu!\n");
    getch();

    system("cls");

    printf("\n\n");
    printf("\t\t\t=====  WELCOME TO THE CRYSTAL OF KNOWLEDGE  =====\n\n");
    printf("\t\t\t\tPlease Input\n\n");
    printf("\t\t\t=====  1 to Login as administrator\n\n");
    printf("\t\t\t=====  2 to Enter as guest\n\n");
    printf("\t\t\tEnter Input = ");
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
                printf("\t\t\tEnter Input = ");
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

    //! CHOICE
    //TODO: Encase in while loop so if one case is done it returns to main menu
    while (choice != 5)
    {
        system("cls");

        //! MAIN MENU
        printf("\t\t\t=====  WELCOME TO THE CRYSTAL OF KNOWLEDGE  =====\n");

        if (loggedIn == true)
        {
            printf("\n\t\t\tHi Admin!\n");
            printf("\t\t\tWhat would you like to do?\n\n");
        }
        else if (loggedIn == false)
        {
            printf("\n\t\t\tWelcome %s", guestData->name);
            printf("\t\t\tWhat would you like to do?\n\n");
        }

        printf("\t\t\t    __________________    __________________\n");
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

        printf("\t\t\t=================================================\n");
        printf("\t\t\t|         1.	Library Catalog                 |\n");
        printf("\t\t\t|         2.	Borrow Book(s)                  |\n");
        printf("\t\t\t|         3.	Return Book(s)                  |\n");
        printf("\t\t\t|         4.	Information                     |\n");
        printf("\t\t\t|         5.	Sign Out                        |\n");
        printf("\t\t\t=================================================\n");

        printf("\t\t\tEnter Input = ");
        scanf("%d", &choice);

        while ((getchar()) != '\n') /* Flush buffer */
            ;

        system("cls");

        /* code */
        switch (choice)
        {
        case 1:
            //* Print Catalog
            printf("\n===\tLibrary Catalog\t===\n\n");
            printList(headNode);
            break;

        case 2:
            //! BORROW BOOK
            while (confirmBorrow != true)
            {
                printf("\n===\tLibrary Catalog\t===\n\n");
                printList(headNode);

                printf("Enter the ID of the book you want to borrow!\n");
                scanf("%d", &wantedBookId);

                while ((getchar()) != '\n') /* Flush buffer */
                    ;

                system("cls");

                tempNode = findByBookId(headNode, wantedBookId); //* Find book ID
                printBookData(tempNode);

                printf("\nAre you sure you want to borrow %s?\n", tempNode->bookTitle);
                printf("1. Yes, proceed\n2. No, I want to change book\n\n");

                printf("Enter input: ");
                scanf("%d", &intConfirm);

                while ((getchar()) != '\n') /* Flush buffer */
                    ;

                //! Confirmed borrow
                tempNode->isAvailable = false;
                //TODO: FIX Update Database
                //printDatabase(headNode);
                // FILE *pTempFile = fopen("temp_database.txt", "w");

                // fclose(pTempFile);
                // remove("database.txt");
                // rename("temp_database.txt", "database.txt");
                //system("cls");

                printReceipt(tempNode);

                if (intConfirm == 1)
                {
                    confirmBorrow = true;
                }

                getch();
                system("cls");
            }

            break;

        case 3:
            //TODO: returnBook()
            break;

        case 4:
            information();
            break;

        case 5:
            //* LOG OUT
            loggedIn = false;
            break;

        default:
            printf("You didn't input a number between 1 to 4, please input a number corresponding to the available coices!\n");
            break;
        }

        printf("\n\t\t\t    Press any key to continue!\n");
        getch();
    }
    return 0;
}
