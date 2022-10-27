#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "argparser.h"

void valid_parse_logging(char*, bool);

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

void test_parse_logging_true()
{
    valid_parse_logging("false", false);
    valid_parse_logging("FALSE", false);
    valid_parse_logging("fAlSe", false);
    valid_parse_logging("FalSE", false);

    valid_parse_logging("true", true);
    valid_parse_logging("TRUE", true);
    valid_parse_logging("tRuE", true);
    valid_parse_logging("truE", true);
}


void test_parse_logging_false()
{

}

void valid_parse_logging(char* input, bool expected)
{
    int args = 3;
    char *argv[] = { "bin_name", "-l", input };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, args, argv);
    assert_true(p.logging == expected);
    assert_true(OK == result);    
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_parse_port),
        cmocka_unit_test(test_no_input_then_return_default_config),
        cmocka_unit_test(test_parse_invalid_port),
        cmocka_unit_test(test_parse_dir),
        cmocka_unit_test(test_parse_logging_true),
        cmocka_unit_test(test_parse_logging_false),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
