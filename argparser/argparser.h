typedef struct
{
    bool logging;
    int port;
    char* path;
} parameters;

parameters parse_args(int, char *[]);
