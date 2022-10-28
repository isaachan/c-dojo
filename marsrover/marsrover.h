typedef struct
{
    int weight;
    int height;
} Plateau;


typedef enum
{
    N = 0, E, S, W,
} Direction;


typedef struct
{
    int x;
    int y;
    Direction direction;
    Plateau plateau;
} Rover;

void move(Rover *);

void turn_left(Rover *);

void turn_right(Rover *);

void execute(Rover *, char *);

