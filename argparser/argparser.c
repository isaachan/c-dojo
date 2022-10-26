#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "argparser.h"

int parse_port(char []);

enum State 
{
    WAITING_FOR_LABEL = 0,
    WAITING_FOR_PORT,
    WAITING_FOR_DIR,
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
            strcpy(p->path, argv[i]);
            currentState = WAITING_FOR_LABEL;
        }
    
    }
    return OK;
}

int parse_port(char input[])
{
    return atoi(input);
};
