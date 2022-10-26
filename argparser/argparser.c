#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "argparser.h"

int parse_logging(char *, bool*);
int parse_port(char []);

enum State 
{
    WAITING_FOR_LABEL = 0,
    WAITING_FOR_PORT,
    WAITING_FOR_DIR,
    WAITING_FOR_LOGGING,
};

enum PARSE_RESULT parse_args(parameters *p, int args, char *argv[])
{ 
    //parameters p = {true, 80, ""};

    enum State currentState = WAITING_FOR_LABEL;
    for (int i = 1; i < args; i++)
    {
        if (currentState == WAITING_FOR_LABEL) 
        {
            if (strcmp(argv[i], "-p") == 0) 
            {
                currentState = WAITING_FOR_PORT;
                continue;
            }
            
            if (0 == strcmp(argv[i], "-d"))
            {
                currentState = WAITING_FOR_DIR;
                continue;
            }

            if (0 == strcmp(argv[i], "-l"))
            {
                currentState = WAITING_FOR_LOGGING;
                continue;
            }
        }

        if (currentState == WAITING_FOR_PORT)
        {
            int port = parse_port(argv[i]);
            if (0 == port)
                return INVALID_PORT;
            p->port = port;
            currentState = WAITING_FOR_LABEL;
        }
        
        if (currentState == WAITING_FOR_DIR)
        {
            strcpy(p->dir, argv[i]);
            currentState = WAITING_FOR_LABEL;
        }

        if (currentState == WAITING_FOR_LOGGING)
        {
            bool isLogging;
            parse_logging(argv[i], &isLogging);           
            p->logging = isLogging;
        }
    
    }
    return OK;
}


int parse_logging(char *input, bool* result)
{
    unsigned long int s_len = strlen(input);
    char upper[s_len];
    for (int i = 0; i < s_len; i++)
    {
        upper[i] = (unsigned char) toupper(input[i]);
    }
    if (0 == strcmp("TRUE", upper)) *result = true;
    if (0 == strcmp("FALSE", upper)) *result = false;
    return 0;
}


int parse_port(char input[])
{
    return atoi(input);
}





