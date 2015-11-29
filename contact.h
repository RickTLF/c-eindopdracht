#ifndef CONTACT_H
#define CONTACT_H

typedef struct {
    char *name;
    char *phoneNumber;
}Contact;

//Assigns both name and number to contact
void assignContactValues( Contact *contact, char *name, char *number );
void editContact( Contact *target, char name [], char number[] );
void assignContactNumber( Contact *contact, char *number );
void assignContactName( Contact *contact, char *name );
void printContactInfo( Contact *contact );

#endif /* CONTACT_H */

