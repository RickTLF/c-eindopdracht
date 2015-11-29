#include "stringman.h"

/*
 * Note: This file should actually be deleted
 * as it serves little purpose. 
 */

/* works the same way as strcmp, 
 * but get 1 instead of 0 if true*/
int get_choice ( char * str1, char * str2 ) {
    if ( strcmp ( str1, str2 ) == 0 ) {
        return 1;
    }
    return 0;
}

/*Looks for a particular character
and return it's index*/
int getCharIndex(char line[], char c) {
    int i = 0;
    for (i = 0 ; i < strlen( line ) ; i++) {
        if ( line[ i ] == c ) {
            return i;
        }
    }
}

