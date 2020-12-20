#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include "structures.c"
#include <time.h>

#define STRING_LIMIT 36

void printTime()
{
    time_t currentTime;
    time(&currentTime);
    int currentDay, currentMonth, currentYear;
    int returnDay, returnMonth, returnYear;

    struct tm *myTime = localtime(&currentTime);

    currentDay = myTime->tm_mday;
    currentMonth = myTime->tm_mon + 1;
    currentYear = myTime->tm_year + 1900;

    printf("Book borrowed on: %d/%d/%d\n", currentDay, currentMonth, currentYear); //* Print current time

    struct tm tm; // time after days added

    memset(&tm, 0, sizeof(struct tm));

    tm.tm_year = currentYear - 1900;
    tm.tm_mon = currentMonth - 1; // 0 = Jan, 1 = Feb etc
    tm.tm_mday = currentDay;
    tm.tm_mday += 14; //! increment days to add

    //time_t returnDate =
    time_t returnTime = mktime(&tm);

    struct tm *returnTimeStruct = localtime(&returnTime);

    returnDay = returnTimeStruct->tm_mday;
    returnMonth = returnTimeStruct->tm_mon + 1;
    returnYear = returnTimeStruct->tm_year + 1900;

    printf("Please return by: %d/%d/%d\n", returnDay, returnMonth, returnYear); //* Print current time
}

//* AUTHENTIFICATION FUNCTIONS
bool logIn(bool logStatus) // takes in loggedIn value
{
    char correctUsername[STRING_LIMIT] = "admin";
    char correctPassword[STRING_LIMIT] = "admin123";
    char inputUsername[STRING_LIMIT];
    char inputPassword[STRING_LIMIT];
    int i, checkUsername, checkPassword;

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

//* END OF AUTHENTIFICATION FUNCTIONS

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

//! FIND AND RETURN BOOK
node_t *findByBookId(node_t *head, int id)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        if (temp->bookId == id)
        {
            return temp; /* If id exists */
        }
        temp = temp->nextNode; /* recursion */
    }
    return NULL; /* If id doesn't exists */
}

void appendEnd(node_t *head, node_t *newNode)
{
    node_t *temp = head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }

    temp->nextNode = newNode;
}

//* END OF LINKED LIST FUNCTIONS

//! Function to print information regarding the program
void information()
{
    printf("\n\t\t\t\t===== INFORMATION =====\n\n");
    printf("\t\t\tIn this application, user can log in either as:\n");
    printf("\t\t\t1. Admin\n\t\t\t2. Guest\n\n");
    printf("\t\t\tGuest user can search for books catalog and borrow books\n");
    printf("\t\t\tAdmin can do all of the above and add/remove books\n");
}

//!IMPORTING FILE
node_t *importFile(node_t *headN, node_t *tempN)
{
    /* Holder for token */
    int idHolder;
    char *titleHolder;
    char *authorHolder;
    int yearHolder;
    bool availableHolder;
    int intHolder;
    /* END of holder */
    int j;
    char stringFromFile[100];

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

                switch (intHolder)
                {
                case 0:
                    availableHolder = false;
                    break;

                case 1:
                    availableHolder = true;
                    break;

                default:
                    break;
                }
                break;

            default:
                // default statements
                break;
            }
            token = strtok(NULL, ">");
            j++;
        } //! END OF STRING SPLITTING

        tempN = createNode(idHolder, titleHolder, authorHolder, yearHolder, availableHolder); //* Create Node
        headN = insertAtHead(headN, tempN);                                                   //* Insert at Head
    }
    //! END OF LINE SPLITTING

    fclose(pFile); //* CLOSES FILE
    //! END OF USING FILE

    return headN;
}

int findNodeSize(node_t *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int nodeSize = findNodeSize(head->nextNode);
        return nodeSize + 1;
    }
}

//TODO: UPDATE DATABASE.TXT AFTER BORROWING BOOK
void printDatabase(node_t *headN)
{
    node_t *temp = headN;
    int intAvail;
    FILE *pTempFile = fopen("temp_database.txt", "w");

    //reverseListToFile(headN, pTempFile);
    while (temp != NULL)
    {
        if (headN->isAvailable == true)
        {
            intAvail = 1;
        }
        else if (headN->isAvailable == false)
        {
            intAvail = 0;
        }

        printf("%s\n", headN->bookTitle);
        fprintf(pTempFile, "%d>%s>%s>%d>%d\n", headN->bookId, headN->bookTitle, headN->bookAuthor, headN->bookYear, intAvail);

        temp = temp->nextNode;
    }

    fclose(pTempFile);

    remove("database.txt");
    rename("temp_database.txt", "database.txt");
}

void reverse_print(node_t *headN, FILE *pTempFile)
{
    int intAvail;
    if (headN == NULL)
    {
        return;
    }
    if (headN->isAvailable == true)
    {
        intAvail = 1;
    }
    else if (headN->isAvailable == false)
    {
        intAvail = 0;
    }

    reverse_print(headN->nextNode, pTempFile);

    fprintf(pTempFile, "%d>%s>%s>%d>%d\n", headN->bookId, headN->bookTitle, headN->bookAuthor, headN->bookYear, intAvail);
}

node_t *reverseList(node_t *headNode)
{
    // no need to reverse if head is nullptr
    // or there is only 1 node.
    if (headNode == NULL || headNode->nextNode == NULL)
    {
        return headNode;
    }

    node_t *list_to_do = headNode->nextNode;

    node_t *reversedList = headNode;
    reversedList->nextNode = NULL;

    while (list_to_do != NULL)
    {
        node_t *temp = list_to_do;
        list_to_do = list_to_do->nextNode;

        temp->nextNode = reversedList;
        reversedList = temp;
    }

    return reversedList;
}

//! PRINT BOOK DATA
void printBookData(node_t *desiredBook)
{
    node_t *temp = desiredBook;

    printf("ID: %d\n", temp->bookId);
    printf("Title: %s\n", temp->bookTitle);
    printf("Author: %s\n", temp->bookAuthor);
    printf("Release Year: %d \n", temp->bookYear);
}

//! PRINT BANNER
void printCrystalOfKnowledge()
{
    printf("\n\t\t\t=================================================\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|          = Crystal of Knowledge =             |\n");
    printf("\t\t\t|        -----------------------------          |\n");
    printf("\t\t\t|                                               |\n");
    printf("\t\t\t=================================================\n\n\n");
}

//! PRINT RECEIPT
void printReceipt(node_t *borrowedBook)
{

    node_t *temp = borrowedBook;

    printCrystalOfKnowledge();
    printf("\nRECEIPT-----------------------------------------\n\n");
    printTime();
    printf("\n");
    printBookData(temp);
    printf("\n\nThank You for Coming!");
}