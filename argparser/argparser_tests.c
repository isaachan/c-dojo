#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "argparser.h"

void test_dummy()
{
    char *args[] = {"bin_name", "-p", "8080"};
    parameters p = parse_args(args);
    assert_true(strcmp(p.path, "") == 0);
    assert_true(p.port == 0);
    assert_true(p.logging);
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_dummy),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
