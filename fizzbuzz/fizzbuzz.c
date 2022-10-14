#include "fizzbuzz.h"
#include <stdio.h>
#include <string.h>

void fizzbuzz(int input, char *output)
{
    if (input % 15 == 0)
    {
        strcpy(output, "fizzbuzz");
    }
    else if (input % 3 == 0)
    {
        strcpy(output, "fizz");
    }
    else if (input % 5 == 0)
    {
        strcpy(output, "buzz");
    }
    else 
    {   
        sprintf(output, "%d", input);
    }
}

