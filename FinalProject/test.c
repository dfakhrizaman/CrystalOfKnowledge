#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "functions.h"

int main()
{
    int idHolder;
    char *titleHolder;
    char *authorHolder;
    int yearHolder;
    bool availableHolder;
    int intHolder;
    /* END of holder */

    FILE *pFile = fopen("database.txt", "r"); //* Opens file in "R" or READ mode

    while (!feof(pFile)) //! continue until reaching the end of file pFile
    {
        j = 1;
        // if (j > 5)
        // {
        //     j = 1;
        // }

        fgets(stringFromFile, 100, pFile);

        //! START OF STRING SPLITTING
        char *token = strtok(stringFromFile, ">"); //* strtok is for splitting strings into tokens,
                                                   //* in this case we split when met with ">" character
        while (token != NULL)
        {
            //printf("%s\n", token);

            switch (j)
            {
            case 1:
                // id
                idHolder = atoi(token);
                break;

            case 2:
                // title
                titleHolder = token;
                break;

            case 3:
                // author
                authorHolder = token;
                break;

            case 4:
                // release year
                yearHolder = atoi(token);
                break;

            case 5:
                // available
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

        // tempNode = createNode(idHolder, titleHolder, authorHolder, yearHolder, availableHolder); //* Create Node
        // headNode = insertAtHead(headNode, tempNode);                                             //* Insert at Head
        //insertAfterNode(headNode, createNode(idHolder, titleHolder, authorHolder, yearHolder, availableHolder));

        printf("%d\n\n", tempNode->bookId);
    }

    fclose(pFile); //* CLOSES FILE
    return 0;
}
