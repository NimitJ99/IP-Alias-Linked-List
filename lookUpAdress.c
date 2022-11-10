/******************************************************************************************
  Author:       Nimitkumar Jogani
  Date:         November 8, 2022
  Purpose:      This is a singly linked list program that reads IP/Alias from a file and perform various operation on
                the linked list and save it to new file.
  Last Modification: November 8, 2022
 ******************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

// Function to search address
void lookup_address(){
    if(head==NULL){
        printf("list is empty");
        return;
    }

    char str[11];

    // Input for Alias
    printf("Enter alias of address to be searched:");
    scanf("%s",str);

    //Define temp node for traversal
    struct address_t *hom = head;

    //Display result for search
    while(strcmp(hom->alias,str)){
        if(hom==NULL){
            printf("Alias does not exist!\n");
            return;
        }
        hom=hom->next;
    }
    printf("%d.%d.%d.%d\n",hom->octet[0],hom->octet[1],hom->octet[2],hom->octet[3] );
}
