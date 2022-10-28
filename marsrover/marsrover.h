typedef struct
{
    int weight;
    int height;
} Plateau;


typedef enum
{
    E = 0, S, W, N,
} Direction;


typedef struct
{
    int x;
    int y;
    Direction direction;
    Plateau plateau;
} Rover;

