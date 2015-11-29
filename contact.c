#include "contact.h"

/*!Assigns both name and number to contact*/
void assignContactValues( Contact *contact, char *name, char *number ) {
    contact -> name = name;
    contact -> phoneNumber = number;
}

/*!Assigns number to a contact*/
void assignContactNumber( Contact *contact, char *number ) {
    contact -> phoneNumber = number;
}

/*!Assigns name to a contact*/
void assignContactName( Contact *contact, char *name ) {
    contact -> name = name;
}

/*!Prints out contact info*/
void printContactInfo( Contact *contact ) {
    printf("Name of contact %s\n", contact -> name);
    printf("Phonenumber of contact %s\n", contact -> phoneNumber);
}
