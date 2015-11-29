#include "inputLib.h"

char * getInput () {
    char text [ 2024 ];

    fgets ( text, 132, stdin );
    return text;
}