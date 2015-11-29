
#include "tweaks.h"

void printHeader ( void ) {
    printf("****************************************************\n");
    printf("Telefoonlijst\n");    
    printf("Eindopdracht c-programmeren, Rick Kock - 2070163\n");
    printf("****************************************************\n");
}

void displayOptions ( void ) {
    printf( "\n%s\n", "What do you wish to do?" );
    printf( "%s\n\n", "add/ delete/ edit/ lookup/ quit" );
}

void displayOptionSelected (char * str) {
     printf( "\nOption selected: %s\n", str );
}

void displayInputError( void ) {
    printf ("%s\n", "Invalid string input.");
}
