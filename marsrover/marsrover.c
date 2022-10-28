#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "marsrover.h"

bool is_in_bounary(const Plateau * p, const int x, const int y)
{
    return x >= 0 && (x <= p->weight-1) 
        && y >= 0 && (y <= p->height-1);
}

void move(Rover *r)
{
    Direction d = r->direction;
    Plateau *p = &(r->plateau);
    switch(r->direction)
    {
        case N:
            if (is_in_bounary(p, r->x, r->y+1)) r->y++;
            break;
        case S:
            if (is_in_bounary(p, r->x, r->y-1)) r->y--;
            break;
        case E:
            //if (r->x < r->plateau.weight - 2) r->x++;
            if (is_in_bounary(p, r->x+1, r->y)) r->x++;
            break;
        case W:
            //if (r->x > 0) r->x--;
            if (is_in_bounary(p, r->x-1, r->y)) r->x--;
            break;
    }
}

Direction ds[4] = {N, E, S, W};

void turn_left(Rover *r)
{
    r->direction = ds[((r->direction-1)+4)%4];
}

void turn_right(Rover *r)
{
    r->direction = ds[(r->direction+1)%4];
}

void execute(Rover *r, const char *command)
{
    for (int i = 0; i < strlen(command); i++)
    {
        switch(command[i])
        {
            case 'M':
                move(r);
                break;
            case 'L':
                turn_left(r);
                break;
            case 'R':
                turn_right(r);
                break;
            defalut:
                printf("Unkown command: [%c].\n", command[i]);
        }
    }    
}
