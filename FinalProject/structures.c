#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// typedef enum
// {
//     false = 0,
//     true = 1
// } bool;

/* BOOK STRUCT */
struct node // linked list of Books
{
    /* data */
    int bookId;
    char bookTitle[100];
    char bookAuthor[100];
    int bookYear;
    bool isAvailable;
    struct node *nextNode;
};
typedef struct node node_t;

/* GUEST DATA STRUCT */
struct guest
{
    /* data */
    char name[48];
    int studentNum;
    node_t *borrowedBook;
};
typedef struct guest guest_t;

// for (i = 0; i < 20; i++)
// {
//     tempNode = createNodeTest(i);                        //* Create Node
//     headNode = insertAtEnd(tempNode, createNodeTest(i)); //* Insert at Head
// }

//* CREATE NODE AFTER SPECIFIC NODE
// tempNode = findByBookId(headNode, 13);       //* Find the desired node to put after
// insertAfterNode(tempNode, createNode(72));   //* Insert the new node after it

// printf("found %d\n", tempNode->bookId);
//printListTest(headNode);

/*
    //*CREATE NODE AT END
    tempNode = findEnd(headNode);
    insertAtEnd(tempNode, createNode(x));
    */

/*//* LOOP TO CREATE LINKED LIST AND APPEND AT END
    tempNode = createNode();                     //* Create Node
    headNode = insertAtHead(headNode, tempNode); //* Insert at Head
    while ()
    {
        tempNode = findEnd(headNode);              //* Find end of list
        insertAfterNode(tempNode, createNode(x));  //* Insert at end of list
    }
    */