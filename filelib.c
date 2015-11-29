#include "filelib.h"


void fileInit(char * filepath, FILE * specFile) {
    specFile = fopen(filepath, "w");        //creating the same, overwrites current file
    fclose(specFile);
}

/*Add more content to your text files*/
void appendContent ( FILE* file, char * filePath, char * str ) {
    file = fopen( filePath, "a");
    fprintf( file, "%s", str );
    fclose( file );
}

/*Get string content from text files*/
void printFileContent ( FILE* file, char * filePath ) {
    char text [ 2024 ];
    
    file = fopen( filePath, "r");
    
    while ( fgets ( text, 1023, file ) != NULL ) 
	{
        printf ( "%s", text );
    }
    
    fclose( file );
}

/*Checks to see if the file exists. 
 *Returns 0 if it does not and 1 if it does.*/
int fileExists ( FILE* file, char * filePath ) {
    int status = 0;
    file = fopen( filePath, "r");
    status = ( file==NULL ) ? 0 : 1;
    fclose( file );
    return status;
}