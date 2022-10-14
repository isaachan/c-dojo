#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "fizzbuzz.h"

void test_output_fizz_for_3_times(void **state) {
    int numbers[] = { 1, 3 };
    char * outputs[] = { "1", "fizz"};

    for (int i = 0; i < sizeof numbers/sizeof numbers[0]; i++)
    {
        char output[9];
        fizzbuzz(numbers[i], output);
        assert_string_equal(outputs[i], output);
    }

}


int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_output_fizz_for_3_times),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
