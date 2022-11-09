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

// initailize UDF
void d_alias(char dAlias[15]);
void read_file();
void import_to_list(FILE *fp,char line[256]);
void check_dup_addr(int a,int b,int c,int d);

// main function
int main(){

    read_file();

    // Vairable for menu choice
    int choice = 0;

    // Menu to perform the opration on the linklist
    do
    {
        printf("\n1.Add address \n2.Look Up Address \n3.Update Address \n4.Delete Address \n5.Display List \n6.Display aliases for location \n7.Save to file \n8.Exit\n");
        printf("\nEnter the choice : ");
        scanf("%d", &choice);
        getchar();

        // Switch case used to perform the operation
        switch (choice)
        {
            case 1:
                add_address();
                break;
            case 2:
                lookup_address();
                break;
            case 3:
                update_address();
                break;
            case 4:
                delete_address();
                break;
            case 5:
                display_list();
                break;
            case 6:
                display_4_location();
                break;
            case 7:
                save_file();
                break;
            case 8:
                f_exit();
                break;
            default:
                printf("Invalid entry..\n");
                break;
        }
    } while (choice != 8);

}

// Function to read external file
void read_file(){
    FILE *fp = fopen("CS531_Inet.txt", "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Could not open file");
    }
    char line[256];

    import_to_list(fp,line);
    //add_address();
    fclose(fp);
}

// Function to import IP/Alias from external file to linked List
void import_to_list(FILE *fp, char line[256]){
    while(fgets(line,200,fp)!=NULL){

        //Define temp nodes for traversal
        struct address_t *tmp,*tmp2;
        tmp=(struct address_t *) malloc(sizeof (struct address_t));

        // Read IP/Alias pair from each line and add to linked list.
        int a,b,c,d;
        sscanf(line,"%d.%d.%d.%d %s\n",&a,&b,&c,&d,tmp->alias);
        tmp->octet[0]=a;
        tmp->octet[1]=b;
        tmp->octet[2]=c;
        tmp->octet[3]=d;
        tmp->next=NULL;
        if(head==NULL){
            head=tmp;
        }
        else{
            tmp2=head;
            while(tmp2->next!=NULL){
                tmp2=tmp2->next;
            }
            tmp2->next=tmp;
        }
    }
}

// Function to check for duplicate addresses
void check_dup_addr(int a,int b,int c,int d){

    struct address_t *tmp = head;
    while(tmp->next!=NULL){
        if(tmp->octet[0]==a && tmp->octet[1]==b && tmp->octet[2]==c && tmp->octet[3]==d){
            printf("Duplicate address entered!\n");
            return;
        }
        tmp=tmp->next;
    }

}

// Function to check for duplicate aliases
void d_alias(char dAlias[15]){
    struct address_t *tmp = head;
    while(tmp->next!=NULL){
        if(!strcmp(tmp->alias, dAlias)){
            printf("Duplicate alias entered!\n");
            return;
        }
        tmp=tmp->next;
    }
}

void check_validAlias(){

}




