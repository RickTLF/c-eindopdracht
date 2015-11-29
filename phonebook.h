/**
 * PhoneBook
 *
 *
 * \brief Provide an example
 *
 * This class is meant as an example.  It is not useful by itself
 * rather its usefulness is only a function of how much it helps
 * the reader.  It is in a sense defined by the person who reads it
 * and otherwise does not exist in any real form. 
 *
 * \note Attempts at zen rarely work.
 *
 * \author Rick Kock
 *
 * \version 1.3
 *
 * \date 21/11/2015 14:16:20 $
 *
 * Contact: ritKock@avans.nl
 *
 * Created on: Wed okt 12 18:39:37 2015
 *
 *
 */
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.h"
#include "stringman.h"
#include "inputLib.h"
#include "filelib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int absoluteSize;
    int contact_cnt;
    Contact * contacts;
}PhoneBook;

void load_file_content_to_phonebook ( char * filePath, PhoneBook * phoneBook );
void phonebook_init( PhoneBook * phoneBook, int constructSize );
void addContactToPhoneBook( PhoneBook*phoneBook, Contact contact);
void print_phonebook(PhoneBook *phoneBook);
void add_contact (  PhoneBook * phoneBook, char * name, char * number  );
int delete_contact_in_phonebook(PhoneBook*phoneBook, char name[]);
int get_index_of_phonebook(char name[], PhoneBook*phoneBook);
void edit_contact_in_phonebook(PhoneBook*phoneBook, char name[], char newNumber[]);
int is_contact_in_phonebook_edited(PhoneBook *phoneBook, char name[], char newNumber[]);
void save_new_contents_to_phonebook( char * filepath, PhoneBook * phoneBook);
void lookup_phone_book ( PhoneBook *phoneBook, char * name );

#endif /* PHONEBOOK_H */

