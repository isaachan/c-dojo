#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>

void fizzbuzz(int input, char *output)
{
    if (input % 3 == 0)
    {
        strcpy(output, "fizz");
    }
    else 
    {    
        strcpy(output, "1");
    }
}
