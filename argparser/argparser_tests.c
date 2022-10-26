#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "argparser.h"

void test_no_input_then_return_default_config()
{
    int args = 1;  
    char *argv[] = { "bin_name" };
    
    parameters p = parse_args(args, argv);
    assert_true(strcmp(p.path, "") == 0);
    assert_true(p.port == 80);
    assert_true(p.logging);
}

void test_dummy()
{
    int args = 3;
    char *argv[] = { "bin_name", "-p", "8080" };
    parameters p = parse_args(args, argv);
    assert_true(strcmp(p.path, "") == 0);
    assert_true(p.port == 8080);
    assert_true(p.logging);
}

int main()
{
    const struct CMUnitTest tests[] = {
    //    cmocka_unit_test(test_dummy),
        cmocka_unit_test(test_no_input_then_return_default_config),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
