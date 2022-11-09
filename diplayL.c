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

// Function to display List
void display_list(){
    printf("The List elements are:\n");

    struct address_t *curr;
    curr=head;
    if(curr==NULL){
        printf("List is Empty!\n")
    }
    while(curr!=NULL)
    {
        printf("%d.%d.%d.%d %s\n",curr->octet[0],curr->octet[1],curr->octet[2],curr->octet[3],curr->alias );
        curr=curr->next ;
    }
}