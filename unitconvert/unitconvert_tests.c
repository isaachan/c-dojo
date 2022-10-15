#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include "unitconvert.h"

bool is_equal(length, length);

void test_length_convert()
{
    length source = {1, FOOT};
    length target = convert(source, FOOT);
    assert_true(is_equal(source, target));
} 

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_length_convert),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

bool is_equal(length l1, length l2)
{
    return l1.value = l2.value && l1.unit == l2.unit;
}




