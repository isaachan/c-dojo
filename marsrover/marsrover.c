#include <stdio.h>
#include "marsrover.h"

void move(Rover *r)
{
    Direction d = r->direction;
    switch(r->direction)
    {
        case N:
            if (r->y < r->plateau.height - 2) r->y++;
            break;
        case S:
            if (r->y > 0) r->y--;
            break;
        case E:
            if (r->x < r->plateau.weight - 2) r->x++;
            break;
        case W:
            if (r->x > 0) r->x--;
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

