#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "marsrover.h"

void assert_rover_status(Rover *p, int expected_x, int expected_y, Direction expected_d)
{
    assert_true(expected_x == p->x);
    assert_true(expected_y == p->y);
    assert_true(expected_d == p->direction);
}

void setup_plateau_and_init_position()
{
    Plateau p = {5, 10};
    Rover r = {0, 0, N, p};

    assert_true(0 == r.x);
    assert_true(0 == r.y);
    assert_true(N == r.direction);
    assert_true(5 == r.plateau.weight);
    assert_true(10 == r.plateau.height);
}

void rover_execute_M_command()
{
    Plateau p = {5, 10};
    Rover r;
     
    r = (Rover) { 1, 1, N, p };
    move(&r);
    assert_rover_status(&r, 1, 2, N);

    r = (Rover) { 1, 1, S, p };
    move(&r);
    assert_rover_status(&r, 1, 0, S);
    
    r = (Rover) { 1, 1, E, p };
    move(&r);
    assert_rover_status(&r, 2, 1, E);

    r = (Rover) { 1, 1, W, p };
    move(&r);
    assert_rover_status(&r, 0, 1, W);
}

void rover_ignore_M_if_overstep_bounary()
{
    Plateau p = {5, 10};
    Rover r;

    r = (Rover) {0, 0, W, p};
    move(&r);
    assert_rover_status(&r, 0, 0, W);

    r = (Rover) {0, 0, S, p};
    move(&r);
    assert_rover_status(&r, 0, 0, S);

    r = (Rover) {p.weight-1, p.height-1, N, p};
    move(&r);
    assert_rover_status(&r, p.weight-1, p.height-1, N);

    r = (Rover) {p.weight-1, p.height-1, E, p};
    move(&r);
    assert_rover_status(&r, p.weight-1, p.height-1, E);
}



void rover_execute_L_command()
{
    Plateau p = {5, 10};
    Rover r;

    r = (Rover) {1, 1, N, p};
    turn_left(&r);
    assert_rover_status(&r, 1, 1, W);

    r = (Rover) {1, 1, W, p};
    turn_left(&r);
    assert_rover_status(&r, 1, 1, S);

    r = (Rover) {1, 1, S, p};
    turn_left(&r);
    assert_rover_status(&r, 1, 1, E);

    r = (Rover) {1, 1, E, p};
    turn_left(&r);
    assert_rover_status(&r, 1, 1, N);
}

void rover_execute_R_command()
{
    Plateau p = {5, 10};
    Rover r;

    r = (Rover) {1, 1, W, p};
    turn_right(&r);
    assert_rover_status(&r, 1, 1, N);

    r = (Rover) {1, 1, N, p};
    turn_right(&r);
    assert_rover_status(&r, 1, 1, E);

    r = (Rover) {1, 1, E, p};
    turn_right(&r);
    assert_rover_status(&r, 1, 1, S);

    r = (Rover) {1, 1, S, p};
    turn_right(&r);
    assert_rover_status(&r, 1, 1, W);
}

void execute_batch_commands()
{
    Plateau p = {5, 10};
    Rover r;

    r = (Rover) {0, 0, N, p};
    execute(&r, "MMRMMR");
    assert_rover_status(&r, 2, 2, S);

    r = (Rover) {0, 0, N, p};
    execute(&r, "LMMMMMMM");
    assert_rover_status(&r, 0, 0, W);
}

void ignore_unknown_command_when_execute_batch_command()
{
    Plateau p = {5, 10};
    Rover r;

    r = (Rover) {0, 0, N, p};
    execute(&r, "MxMyRasfasfMABDMadfsRssdf123");
    assert_rover_status(&r, 2, 2, S);
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(setup_plateau_and_init_position),
        cmocka_unit_test(rover_execute_M_command),
        cmocka_unit_test(rover_execute_L_command),
        cmocka_unit_test(rover_execute_R_command),
        cmocka_unit_test(rover_ignore_M_if_overstep_bounary),
        cmocka_unit_test(execute_batch_commands),
        cmocka_unit_test(ignore_unknown_command_when_execute_batch_command),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}


