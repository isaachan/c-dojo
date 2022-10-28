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

void turn_left(Rover *r)
{
    if (r->direction == N) 
    {
        r->direction = W;
        return;
    }
    if (r->direction == W) 
    {
        r->direction = S;
        return;
    }
    if (r->direction == S)
    {
        r->direction = E;
        return;
    }
    if (r->direction == E)
    {
        r->direction = N;
        return;
    }


}

void turn_right(Rover *r)
{
}

