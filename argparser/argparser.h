enum PARSE_RESULT 
{
    OK = 0,
    INVALID_PORT,
    INVALID_LOGGING,
    INVALID_LABEL,
};

typedef struct
{
    bool logging;
    int port;
    char dir[40];
} parameters;

enum PARSE_RESULT parse_args(parameters *, int, char *[]);
