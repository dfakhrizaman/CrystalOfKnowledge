#include <stdio.h>
#include <stdlib.h>

//Sanditya Larope Sutanto
//1906423183

struct node
{
    int data;
    struct node *nextPtr;
};

typedef struct node Node;
typedef Node *NodePtr; //alias for the pointer of struct node

void addNode(int data, NodePtr *headAddress);
NodePtr reverseList(NodePtr headAddress);
//function prototype

int main()
{
    int input;
    NodePtr headAddress = NULL;

    do
    {
        printf("\n\nEnter an Integer (-1 to Exit) : ");
        scanf("%d", &input);
        addNode(input, &headAddress);                       //add Node
        NodePtr reversedHeadPtr = reverseList(headAddress); //Print the Linked List

    } while (input != -1);
}

void addNode(int data, NodePtr *headAddress)
{
    NodePtr tmpAddress = malloc(sizeof(Node)); //allocate new address
    tmpAddress->data = data;
    tmpAddress->nextPtr = NULL;

    tmpAddress->nextPtr = *headAddress;
    headAddress = tmpAddress;
}

NodePtr reverseList(NodePtr headAddress)
{
    NodePtr tempHeadAddress = NULL;
    if (headAddress != NULL)
    {
        printf("\nList berisi:\n");
        NodePtr iteratorPtr = headAddress;
        while (iteratorPtr != NULL)
        {
            addNode((iteratorPtr).data, &tempHeadAddress);
            printf("%d  ", (iteratorPtr).data);
            iteratorPtr = (iteratorPtr).nextPtr;
        }
        return tempHeadAddress;
    }
    else
    {
        printf("List kosong\n");
    }
}

void printList(NodePtr headAddress)
{
    if (headAddress != NULL)
    {
        printf("\nList berisi:\n");
        NodePtr iteratorPtr = headAddress;
        printf("\nreversed: ");
        while (iteratorPtr != NULL)
        {
            printf("%d  ", (iteratorPtr).data);
            iteratorPtr = (iteratorPtr).nextPtr;
        }
    }
    else
    {
        printf("List kosong\n");
    }
}