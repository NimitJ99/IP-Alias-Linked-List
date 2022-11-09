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

// Function to add new Address to the list.
void add_address(){

    // Declare Variables
    struct address_t *tmp,*tmp2;
    tmp=(struct address_t *) malloc(sizeof (struct address_t));
    int a,b,c,d;
    char ip[256],tAlias[11];

    // Taking input for IP address
    printf("Enter IP:");
    scanf("%s", ip);

    // Extracting octet numbers from input string
    sscanf(ip,"%d.%d.%d.%d\n",&a,&b,&c,&d);

    // Checking for valid IP
    while(0>a || a>255 || 0>b || b>255 || 0>c || c>255 || 0>d || d>255){
        printf("Invalid IP, Enter IP (0-255):");
        scanf("%s", ip);
        sscanf(ip,"%d.%d.%d.%d\n",&a,&b,&c,&d);
    }

    // Calling Duplicate Address check function
    check_dup_addr(a,b,c,d);

    // Input for Alias
    printf("Enter Alias:");
    scanf("%s", tAlias);

    // Checking for valid Alias
    while(strlen(tAlias)>10){
        printf("Alias Length Exceeded!\nEnter Alias Again: ");
        scanf("%s",tAlias);
    }

    // Calling Duplicate Alias check function
    d_alias(tAlias);

    // Storing input IP/Alias in temp Node
    strcpy(tmp->alias,tAlias);
    tmp->octet[0]=a;
    tmp->octet[1]=b;
    tmp->octet[2]=c;
    tmp->octet[3]=d;
    tmp->next=NULL;

    // Adding temp node to the Linked List
    if(head==NULL){
        head=tmp;
    }
    else{
        tmp2=head;
        while(tmp2->next!=NULL){
            while(tmp2==tmp){
                printf("duplicate pair!");
            }
            tmp2=tmp2->next;
        }
        tmp2->next=tmp;
    }

}