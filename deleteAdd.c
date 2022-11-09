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

// Function to delete address
void delete_address(){
    //Declare variables
    char dAlias[11],c;
    int count=0;

    // Input for alias
    printf("Enter Alias:");
    scanf("%s",dAlias);
    struct address_t *tmp;
    tmp=head;

    // Searching for Address based on alias
    while(strcmp(tmp->alias,dAlias))
    {
        tmp=tmp->next;
        count++;
        if(tmp==NULL){
            printf("Alias does not exist!\n");
            return;
        }
    }

    // print IP/alias to be deleted
    printf("The address is: %d.%d.%d.%d\n",tmp->octet[0],tmp->octet[1],tmp->octet[2],tmp->octet[3] );

    // Ask confirmation for deletion
    printf("To confirm deletion press Y, to abort press N: ");
    scanf("%s",&c);
    getchar();

    // deleting node on confirmation.
    if(strcmp(&c,"Y")==0){
        tmp=head;
        for(int i=0;i<count-1;i++){
            tmp=tmp->next;
        }
        tmp->next=tmp->next->next;
    }
}
