#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "structures.c"

#define STRING_LIMIT 36

//* LOGIN FUNCTIONS
bool logIn(bool logStatus) // takes in loggedIn value
{
    char correctUsername[STRING_LIMIT] = "admin";
    char correctPassword[STRING_LIMIT] = "admin123";
    char inputUsername[STRING_LIMIT];
    char inputPassword[STRING_LIMIT];
    int i, checkUsername, checkPassword;

    char cc[] = "admin";

    printf("==\tLOGIN PAGE\t==\n\n");

    printf("Enter your username : \n");
    fgets(inputUsername, STRING_LIMIT, stdin);       /* Get user input for username */
    inputUsername[strlen(inputUsername) - 1] = '\0'; /* Cut at space */

    printf("Enter your password : \n");
    fgets(inputPassword, STRING_LIMIT, stdin);       /* Get user input for password */
    inputPassword[strlen(inputPassword) - 1] = '\0'; /* Cut at space */

    /* Check username and password */
    checkUsername = strcmp(correctUsername, inputUsername);
    checkPassword = strcmp(correctPassword, inputPassword);

    //printf("%d %d", checkUsername, checkPassword);

    if (checkUsername == 0 && checkPassword == 0)
    {
        printf("\n\nLogged In Successfully\n");
        logStatus = true;
        return logStatus;
    }
    else
    {
        printf("\n\nIncorrect username or password\n");
        printf("Enter any key to continue...");
        getch();
        system("cls");
    }
}

guest_t *guestEnter() // loggedIn still false
{
    char stdNum[STRING_LIMIT];

    guest_t *guestData = (struct guest *)malloc(sizeof(guest_t));
    printf("==\tENTER AS GUEST\t==\n\n");

    printf("Please enter your Name : \n");
    fgets(guestData->name, STRING_LIMIT, stdin);

    printf("Please enter your Student Number : \n");
    //scanf("%d", &guestData->studentNum);
    fgets(stdNum, STRING_LIMIT, stdin);

    guestData->studentNum = atoi(stdNum);

    return guestData;
}
//* END OF LOGIN FUNCTIONS

//* LINKED LIST FUNCTIONS
void printList(node_t *headNode)
{
    node_t *temp = headNode;

    while (temp != NULL)
    {
        printf("ID: %d\n", temp->bookId);
        printf("Title: %s\n", temp->bookTitle);
        printf("Author: %s\n", temp->bookAuthor);
        printf("Release Year: %d \n", temp->bookYear);
        if (temp->isAvailable == true)
        {
            printf("Book is Available\n");
        }
        else
        {
            printf("Book is Unavailable\n");
        }

        printf("\n");

        temp = temp->nextNode;
    }
    printf("\n");
}

void printListTest(node_t *headNode)
{
    node_t *temp = headNode;

    while (temp != NULL)
    {
        printf("%d\n", temp->bookId);
        printf("\n");

        temp = temp->nextNode;
    }
    printf("\n");
}

node_t *createNode(int bookId, char *title, char *author, int releaseYear, bool available) // Create Node / Create book type variable //TODO: add more parameters for other datas i.e. title, author etc.
{
    /* 
    node_t *newNode = malloc(sizeof(node_t));
    somehow this gives error but the code can still run
    error message: a value of type "void *" cannot be used to initialize an entity of type "node_t *"
    */
    node_t *newNode = (struct node *)malloc(sizeof(node_t));
    newNode->bookId = bookId;
    strcpy(newNode->bookTitle, title);
    strcpy(newNode->bookAuthor, author);
    newNode->bookYear = releaseYear;
    newNode->isAvailable = available;
    newNode->nextNode = NULL;

    return newNode;
}

void *insertAtHead(node_t *head, node_t *newNode)
{
    newNode->nextNode = head;
    head = newNode;
    // return newNode; // should be put as the new headNode => headNode = isertAtHead(head, newNode/tempNode);
}

//newNode can take in createNode()
void insertAfterNode(node_t *nodeToInsertAfter, node_t *newNode) // we only need void not node_t as its not the head
{
    newNode->nextNode = nodeToInsertAfter->nextNode;
    nodeToInsertAfter->nextNode = newNode;
}

node_t *findByBookId(node_t *head, int id)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            return temp; /* If id exists */
        }
        temp = temp->nextNode; /* iteration */
    }
    return NULL; /* If id doesn't exists */
}

// void *appendEnd(node_t *head, int bookId, char *title, char *author, int releaseYear, bool available)
// {
//     node_t *temp = head;
//     while (temp->nextNode != NULL)
//     {
//         temp = temp->nextNode; /* recursion */
//     }

//     temp->nextNode = createNode(bookId, title, author, releaseYear, available);
// }
//* END OF LINKED LIST FUNCTIONS

//* Function to print information regarding the program
void information()
{
    printf("\n\t\t\t\t===== INFORMATION =====\n\n");
    printf("\t\t\tIn this application, user can log in either as:\n");
    printf("\t\t\t1. Admin\n\t\t\t2. Guest\n\n");
    printf("\t\t\tGuest user can search for books catalog and borrow books\n");
    printf("\t\t\tAdmin can do all of the above and add/remove books\n");
}
