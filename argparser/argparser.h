enum PARSE_RESULT 
{
    OK = 0,
    INVALID_PORT,
};

typedef struct
{
    bool logging;
    int port;
    char* path;
} parameters;

enum PARSE_RESULT parse_args(parameters *, int, char *[]);
