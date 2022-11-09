/******************************************************************************************
  Author:       Nimitkumar Jogani
  Date:         November 8, 2022
  Affiliation:  George Mason University
  Purpose:      This is a singly linked list program that reads IP/Alias from a file and perform various operation on
                the linked list and save it to new file.
  Last Modification: November 8, 2022
 ******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// function to save the linked list to a new user specified file
void save_file()
{
    //create new file
    FILE *newFile;

    // Input for name of file
    char input_str[12];
    printf("\nEnter the file name: ");
    scanf("%s", input_str);

    // Write linked list to new file
    struct address_t *tmp = head;
    newFile = fopen(input_str, "w");

    while (tmp != NULL)
    {
        fprintf(newFile, "%d.%d.%d.%d %s\n", tmp->octet[0], tmp->octet[1], tmp->octet[2], tmp->octet[3], tmp->alias);
        tmp = tmp->next;
    }
    printf("\nSuccessfully saved to new file.\n");

    //close file
    fclose(newFile);
}