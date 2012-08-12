/* 
 * Eric Gallager
 * 
 * Problem: In this assignment you should change the program so that it will take a number of contacts specified by the user, rather than the hard coded 4 contacts.
 * Interesting things happened: Apparently in C you are allowed to declare an array with a variable, but this was due to a change in the C standard between 1989 and 1999. 
 * The following links are a discussion of the standard:
 * http://stackoverflow.com/questions/448844/variable-sized-arrays-in-c 
 * http://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CONTACTS 4

// This structure is useful for recording someone's contact information.
typedef struct Rolodex
{
    char Name[50];
    char TelephoneNumber[15];
} Rolodex_t;

int main(void)
{
    int i;
    char Input[100];
	int contacts_v = CONTACTS; // make constant into variable
	printf("\n Enter the number of contents you are going to enter\n> "); // prompt
	scanf("%i", &contacts_v); // get input
	
    Rolodex_t TheRolodex[contacts_v];

    i = 0; // reset
    // This loop allows us to enter the contact information from the command line
    for(i; i < contacts_v; i++)
    {
        printf("\n Enter Contact Number %d's Name\n> ", i+1);
        scanf("%s", Input);
        strcpy(TheRolodex[i].Name, Input);
        printf("\n Enter Contact Number %d's Phone Number\n> ",i+1);
        scanf("%s",Input);
        strcpy(TheRolodex[i].TelephoneNumber, Input);
    }
	
	/* The following loop displays the information entered */
    printf("\n \n The Contacts Entered were: \n");
    for(i = 0; i < contacts_v; i++)
    {
        printf("%s \n", TheRolodex[i].Name);
        printf("\t%s\n \n", TheRolodex[i].TelephoneNumber);
    }

    return 0;
}
