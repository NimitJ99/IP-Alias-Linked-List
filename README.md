# IP-Alias-Linked-List

Design Of a Linked List to store the IP address and it's corresponding Alias.

The program will read a file and import all IP/Alias pairs to a linked list.

Linked List Node:	struct address_t{
                      int octet[4];
                      char alias[11];
                      struct address_t *next;
                  }struct address_t *head = NULL;


Sample Content: 111.22.3.44 platte
                131.250.95.21 jet
                172.66.7.88 wabash
                111.22.5.66 green
                131.250.47.63 baker

Then the program will prompt the user to perform certain operations on the list.
Such as: Add address,
         Look up address,
         Update address,
         Delete address,
         Display list,
         Display aliases for location,
         Save to file,
         Quit.
