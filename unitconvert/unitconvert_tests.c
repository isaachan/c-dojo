#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include "unitconvert.h"

bool is_equal(length, length);



void test_length_convert()
{
    length target = convert((length) {1, FOOT}, FOOT);
    assert_true(is_equal((length) {1, FOOT}, target));
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




