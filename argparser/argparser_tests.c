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
    char *argv[] = { "bin_name" };
    parameters p = { true, 80, "" }; 

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    
    assert_true(strcmp(p.dir, "") == 0);
    assert_true(p.port == 80);
    assert_true(p.logging);
    assert_true(OK == result);
}

void test_parse_port()
{
    char *argv[] = { "bin_name", "-p", "8080" };
    parameters p = { true, 80, "" };
    
    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    
    assert_true(strcmp(p.dir, "") == 0);
    assert_true(p.port == 8080);
    assert_true(p.logging);
    assert_true(OK == result);
}

void test_parse_invalid_port()
{
    char *invalid_ports[] = { "invalid_port", "-12", "0" };    
    for (int i = 0; i < sizeof invalid_ports/sizeof invalid_ports[0]; i++)
    {
        char *argv[] = { "bin_name", "-p", invalid_ports[i] };
        parameters p = { true, 80, "" };

        enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
        assert_true(result == INVALID_PORT);
    }
}

void test_parse_dir()
{
    char *argv[] = { "bin_name", "-d", "/path/to/somewhere" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(0 == strcmp("/path/to/somewhere", p.dir));
    assert_true(p.port == 80);
    assert_true(p.logging);
    assert_true(OK == result);
}

void test_parse_logging()
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

void test_parse_invliad_logging()
{
    char *argv[] = { "bin_name", "-l", "NOT_A_BOOL" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(result == INVALID_LOGGING);

}

void test_parse_multiple_parameters()
{
    char *argv[] = { "bin_name", "-l", "true", "-d", "/path", "-p", "8000" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(p.logging == true);
    assert_true(p.port == 8000);
    assert_true(0 == strcmp(p.dir, "/path"));
}

void test_unknown_label()
{
    char *argv[] = { "bin_name", "-l", "true", "-x", "/path" };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(result == UNKNOWN_LABEL);
}

void test_missing_label()
{
    char *argv[] = { "bin_name", "-l", "true", "/path"  };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(result == MISSING_LABEL);
}

void valid_parse_logging(char* input, bool expected)
{
    char *argv[] = { "bin_name", "-l", input };
    parameters p = { true, 80, "" };

    enum PARSE_RESULT result = parse_args(&p, sizeof argv/sizeof argv[0], argv);
    assert_true(p.logging == expected);
    assert_true(OK == result);
}

int main()
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_no_input_then_return_default_config),
        cmocka_unit_test(test_parse_port),
        cmocka_unit_test(test_parse_invalid_port),
        cmocka_unit_test(test_parse_dir),
        cmocka_unit_test(test_parse_logging),
        cmocka_unit_test(test_parse_invliad_logging),
        cmocka_unit_test(test_parse_multiple_parameters),
        cmocka_unit_test(test_unknown_label),
        cmocka_unit_test(test_missing_label),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
