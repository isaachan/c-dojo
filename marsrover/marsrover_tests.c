#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include "marsrover.h"


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


int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(setup_plateau_and_init_position),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}


