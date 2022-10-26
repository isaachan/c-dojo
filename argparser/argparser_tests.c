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
    parameters p = { true, 80, "" }; 

    enum PARSE_RESULT result = parse_args(&p, args, argv);
    
    assert_true(strcmp(p.dir, "") == 0);
    assert_true(p.port == 80);
    assert_true(p.logging);
    assert_true(OK == result);
}

void test_parse_port()
{
    int args = 3;
    char *argv[] = { "bin_name", "-p", "8080" };
    parameters p = { true, 80, "" };
    
    enum PARSE_RESULT result = parse_args(&p, args, argv);
    
    assert_true(strcmp(p.dir, "") == 0);
    assert_true(p.port == 8080);
    assert_true(p.logging);
    assert_true(OK == result);
}

void test_parse_invalid_port()
{
    int args = 3;
    char *argv[] = { "bin_name", "-p", "INVALID_PORT" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, args, argv);
    assert_true(result == INVALID_PORT);
}

void test_parse_dir()
{
    int args = 3;
    char *argv[] = { "bin_name", "-d", "/path/to/somewhere" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, args, argv);
    assert_true(0 == strcmp("/path/to/somewhere", p.dir));
    assert_true(p.port == 80);
    assert_true(p.logging);
    assert_true(OK == result);
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_parse_port),
        cmocka_unit_test(test_no_input_then_return_default_config),
        cmocka_unit_test(test_parse_invalid_port),
        cmocka_unit_test(test_parse_dir),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
