#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "argparser.h"

int parse_port(char []);

enum State {
    WAITING_FOR_LABEL = 0,
    WAITING_FOR_PORT,
};

parameters parse_args(int args, char *argv[])
{ 
    parameters p = {true, 80, ""};

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
        }

        if (currentState == WAITING_FOR_PORT)
        {
            int port = parse_port(argv[i]);
            p.port = port;
        }
    
    }
    return p;
}

int parse_port(char input[])
{
    return 8080;
};
