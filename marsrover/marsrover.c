#include <stdio.h>
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

Direction ds[4] = {N, E, S, W};

void turn_left(Rover *r)
{
    r->direction = ds[(r->direction + 4 - 1)%4];
}

void turn_right(Rover *r)
{
    r->direction = ds[(r->direction+1)%4];
}

