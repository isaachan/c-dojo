
#include "marsrover.h"

void move(Rover *r)
{
    Direction d = r->direction;
    switch(r->direction)
    {
        case N:
            r->y++; // = r->y + 1;
            break;
        case S:
            r->y--;
            break;
        case E:
            r->x++;
            break;
        case W:
            r->x--;
            break;
    }
}

void turn_left(Rover *r)
{
}

void turn_right(Rover *r)
{
}

