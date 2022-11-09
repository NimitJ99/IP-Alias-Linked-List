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

// Function to display Alias for input address
void display_4_location() {

    //Declaring Variables
    int a, b, flag = 0;
    struct address_t *tmp = head;

    // Ipnput for Address Location
    printf("Enter address location for the alias.\n");
    printf("Enter address #1:");
    scanf("%d", &a);
    getchar();
    printf("Enter address #2:");
    scanf("%d", &b);
    getchar();

    // Display all Aliases for corresponding Address
    while (tmp != NULL) {
        if(tmp->octet[0] == a && tmp->octet[1] == b) {
            printf("The alias for address %d.%d.%d.%d is %s\n", tmp->octet[0], tmp->octet[1], tmp->octet[2], tmp->octet[3],
                   tmp->alias);
            flag = 1;
        }
        tmp = tmp->next;
    }

    // Print error if no Alias found.
    if(flag==0){
        printf("No such alias Exists!\n");
    }

}