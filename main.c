#include "filelib.h"
#include "inputLib.h"
#include "stringman.h"
#include "phonebook.h"
#include "tweaks.h"

int main(int argc, char** argv) {
    FILE *testFile;
    char *fp = "test.txt";
    char nameBuffer[ 1023 ];
    char numberBuffer[ 1023 ]; 
    PhoneBook book1;    
    
    /*check to see if the file exits first*/  
    
    if(fileExists( testFile, fp) == 0)                              /*if it does not exist*/  
    {                                                          
        fileInit(fp, testFile);                                       /*create a new one*/   
    } 
    if( fileExists(testFile, fp) == 1)                             /*When it does exist*/      
    {                                       
        printHeader();
        load_file_content_to_phonebook(fp, &book1);                           /*Store any contacts made previously*/
        print_phonebook(&book1);
    }
    
    while(1) 
    {
        displayOptions ();    
        strcpy( nameBuffer, getInput() );                                   /*store input inside of a text*/
        
        /* Note that nameBuffer is not used as a variable for name */                                                                    
        displayOptionSelected ( nameBuffer );

        if(get_choice( nameBuffer, "add\n" ))                               /*add a contact*/
        {                             
            printf ("%s\n", "Please enter a name.");
            strcpy( nameBuffer, getInput() );                               /*copy input to a text variable*/
            printf( "\nName entered: %s\n", nameBuffer );            
            appendContent ( testFile, fp, nameBuffer );
            printf ("%s\n", "Please enter a phone number.");
            strcpy( numberBuffer, getInput ( ) );                               
            printf( "\nPhone number entered: %s\n", nameBuffer );
            appendContent ( testFile, fp, numberBuffer );                   /*in case you do not close the file properly*/                                                                  
            add_contact( &book1, nameBuffer, numberBuffer );                    
        }
        else if( get_choice( nameBuffer, "delete\n" ) ) 
        {                       
            printf ("%s\n", "Please enter a name to delete contact.");
            strcpy( nameBuffer, getInput() );                               
            printf( "\nName entered: %s\n", nameBuffer );            
            if (delete_contact_in_phonebook ( &book1, nameBuffer )) 
            {
                printf( "\nContact successfully deleted: %s\n", nameBuffer );
            } else {
                printf( "Contact could not be found.\n" );            
            }
        }
        else if( get_choice( nameBuffer, "edit\n") ) 
        {                        
            printf ("%s\n", "Please enter name to edit contact info.");            
            printf ("%s\n", "Please enter a name.");
            strcpy( nameBuffer, getInput() );                               
            printf( "\nName entered: %s\n", nameBuffer );            
            printf ("%s\n", "Please enter a phone number.");
            strcpy( numberBuffer, getInput ( ) );                               
            printf( "\nPhone number entered: %s\n", nameBuffer );
            edit_contact_in_phonebook( &book1, nameBuffer, numberBuffer );
        }
        else if(get_choice( nameBuffer, "lookup\n")) 
        {                         
            printf ("%s\n", "Please enter name to edit contact info.");            
            printf ("%s\n", "Please enter a name.");
            strcpy( nameBuffer, getInput() );                              
            printf( "\nName entered: %s\n", nameBuffer );            
            lookup_phone_book ( &book1, nameBuffer );
        }        
        else if(get_choice( nameBuffer, "quit\n")) {                         
            printf ("%s\n", "Bye!");
            save_new_contents_to_phonebook( fp, &book1 );        /*actually creates a new different file*/
            exit(1);
        }
        else {
            displayInputError();
        }
        printHeader();
        print_phonebook(&book1);
    }   
    return (EXIT_SUCCESS);
}