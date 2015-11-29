#include "phonebook.h"

int is_contact_found(int index, char *str1, PhoneBook *phoneBook);
void print_corresponding_contact(int index, PhoneBook *phoneBook);

char *get_full_name(char *firstName, char *lastName);

void phonebook_init(PhoneBook *phoneBook, int constructSize) {
    phoneBook -> absoluteSize = constructSize;
    phoneBook -> contact_cnt = 0;
    phoneBook -> contacts = (Contact *) malloc(constructSize *sizeof(Contact));
}

void load_file_content_to_phonebook(char *filePath, PhoneBook *phoneBook) {
    FILE* fp = fopen(filePath, "r");
    char fName[ 500 ];
    char lName[ 500 ];
    char number[ 500 ];
    char *fullName;
    
    phonebook_init(phoneBook, 1);

    while(fscanf(fp, "%s %s\n %s\n", fName, lName, number) != EOF) 
    { 
        fullName = get_full_name ( fName, lName );
        add_contact( phoneBook, fullName, number );
    }
    
    fclose(fp);
}

char *get_full_name (char *firstName, char *lastName) {  
    return strcat(strcat(firstName,  " "), strcat(lastName, "\n"));            
}

void add_contact(PhoneBook *phoneBook, char *name, char *number) {
    Contact *contacts;
    Contact *newContact = malloc(sizeof(Contact));
    int newMemorySize = 0;
    
    newContact -> name = malloc (strlen(name) + 1);
    newContact -> phoneNumber = malloc(strlen(number)+ 1);
    
    strcpy(newContact -> name, name);
    strcpy(newContact -> phoneNumber, number);

    newMemorySize = sizeof(*newContact) + phoneBook -> absoluteSize;
    contacts  = realloc( phoneBook -> contacts, newMemorySize);
    if (contacts != NULL) {
        phoneBook -> contacts = contacts;
    }

    phoneBook -> contacts[ phoneBook -> contact_cnt]    =   *newContact;
    phoneBook -> absoluteSize                           =   newMemorySize;
    phoneBook -> contact_cnt                            +=  1;    
}

int delete_contact_in_phonebook(PhoneBook *phoneBook, char name[])  {
    int index = get_index_of_phonebook( name, phoneBook);
    int newMemorySize = 0;
    size_t i;
    
    if (index >= 0) {
        newMemorySize = phoneBook -> absoluteSize - sizeof(phoneBook -> contacts [index]);
        for (i = index; i < phoneBook -> contact_cnt - 1; i++) {
            phoneBook -> contacts [i] = phoneBook -> contacts[i + 1];
        }
        phoneBook -> absoluteSize = newMemorySize;
        phoneBook -> contact_cnt -= 1;
    } else {
        return 0;
    }
    return 1;
}

void edit_contact_in_phonebook(PhoneBook *phoneBook, char name[], char newNumber[]) {
    int index = get_index_of_phonebook(name, phoneBook);

    if (index >= 0) {
        char *number = phoneBook ->contacts[index].phoneNumber;
        if (is_contact_in_phonebook_edited(phoneBook, name, newNumber) != -1) {
            printf("Successfully edited %s\n\n", name);
        }
        else {
            printf("Entry could not be found."); ///< prints entry not found
        }
    }
    else {
        printf("Could not find %s", name);
    }
}

int is_contact_in_phonebook_edited( PhoneBook *phoneBook, char name[], char newNumber[] ){
    int index = get_index_of_phonebook( name, phoneBook );

    if ( index >= 0 ) {     ///< Don't bother checking if there is no contact wit that name.
        phoneBook -> contacts[ index ].phoneNumber = 
                realloc(
                        phoneBook -> contacts[ index ].phoneNumber, 
                        strlen(newNumber) + 1
                        );
        
        phoneBook -> contacts[ index ].phoneNumber = newNumber; ///< strcpy does not work.
        return 1;
    }
    return -1;
}

/*! If the corresponding name is the same name found inside of
 *  phonebook, you'll retrieve the index of where the contact
 *  registered in phonebook is placed. Otherwise, you'll
 *  retrieve -1 which indicates that there is no contact to
 *  be found with that name.
 */
int get_index_of_phonebook(char name[], PhoneBook *phoneBook) {
    int i;

    for ( i = 0; i < phoneBook -> contact_cnt; i++ ) {
        if (strcmp(name, phoneBook -> contacts[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void save_new_contents_to_phonebook(char *filepath, PhoneBook *phoneBook) {
    FILE *file  = fopen( filepath, "w");
    int i;
    
    for ( i = 0; i < phoneBook -> contact_cnt; i++ )
    {
        fprintf( file,"%s%s\n", 
                phoneBook -> contacts[i].name, 
                phoneBook -> contacts[i].phoneNumber);
    }
    fclose( file );
}



void print_phonebook(PhoneBook *phoneBook) {
    printf("********************************************************\n");
    int i;

    for (i = 0; i < phoneBook -> contact_cnt; i++){
        printf("%d:\t%s\t%s\n", 
                i, phoneBook -> contacts[i].name, 
                phoneBook->contacts[i].phoneNumber);
    }
    printf("********************************************************\n");
}

void lookup_phone_book(PhoneBook *phoneBook, char *name) {
    printf("********************************************************\n");
    int i;
    int cnt = 0;    ///< Variable to keep count of contacts.
    
    /*!
     * If conctact's been found, the counter 'cnt' increments,
     * meaning that you've at least got one or more contacts
     * with the same name. However, if there were no contacts
     * to be found at all, notify user.
     */
    for ( i=0; i < phoneBook -> contact_cnt; i++ )
    {    
        if (is_contact_found( i, name, phoneBook) == 0)
        {
            cnt++;
            print_corresponding_contact(i, phoneBook);
        }
    }
    if (cnt == 0) {
        printf("Contact not found.\n");
    }
    printf("********************************************************\n");
}

void print_corresponding_contact(int index, PhoneBook *phoneBook) {
    printf(
           "%d:"
            "\t%s"
            "\t%s\n", 
           index, 
           phoneBook -> contacts[ index ].name, 
           phoneBook -> contacts[ index ].phoneNumber
           );
}

int is_contact_found(int index, char *str1, PhoneBook *phoneBook) {
    return strcmp( str1, phoneBook -> contacts[ index ].name );    
}
