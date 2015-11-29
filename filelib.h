/* 
 * File:   filelib.h
 * Author: Rick
 *
 * Created on November 14, 2015, 1:26 AM
 */

#ifndef FILELIB_H
#define FILELIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "phonebook.h"

void fileInit(char * filepath, FILE * specFile);
void appendContent ( FILE* file, char * filePath, char * str );
void printFileContent ( FILE* file, char * filePath );
int fileExists ( FILE* file, char * filePath );

#ifdef __cplusplus
extern "C" {   
    
#endif




#ifdef __cplusplus
}
#endif

#endif /* FILELIB_H */

