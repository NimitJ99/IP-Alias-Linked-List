//
// Created by NimitJ on 11/7/2022.
//

// Initialize UDF
void add_address();
void lookup_address();
void delete_address();
void update_address();
void display_4_location();
void display_list();
void save_file();
void f_exit();

// Define List Node
struct address_t{
    int octet[4];
    char alias[11];
    struct address_t *next;
};
struct address_t *head;
