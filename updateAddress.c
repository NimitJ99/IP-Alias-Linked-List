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

// Function to update existing address
void update_address(){

    // Input for Alias
    char dAlias[11];
    printf("Enter Alias for address to be updated:");
    scanf("%s",dAlias);

    // Display corresponding address for entered alias
    struct address_t *tmp;
    tmp=head;
    while(strcmp(tmp->alias,dAlias))
    {
        tmp=tmp->next;
        if(tmp==NULL){
            printf("Alias does not exist!\n");
            return;
        }
    }
    printf("The address is: %d.%d.%d.%d\n",tmp->octet[0],tmp->octet[1],tmp->octet[2],tmp->octet[3] );

    // Input for new address
    char ip[11];
    printf("Enter new address:");
    scanf("%s",ip);
    int a,b,c,d;
    sscanf(ip,"%d.%d.%d.%d\n",&a,&b,&c,&d);

    // Check for valid address
    while(0>a || a>255 || 0>b || b>255 || 0>c || c>255 || 0>d || d>255){
        printf("Invalid IP, Enter IP (0-255):");
        scanf("%s", ip);
        sscanf(ip,"%d.%d.%d.%d\n",&a,&b,&c,&d);
    }

    // Check if duplicate address exists
    check_dup_addr(a,b,c,d);

    //Update address
    tmp->octet[0]=a;
    tmp->octet[1]=b;
    tmp->octet[2]=c;
    tmp->octet[3]=d;
    printf("IP successfully Updated!\n")
}
