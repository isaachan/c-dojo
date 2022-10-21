#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include <setjmp.h>
#include <cmocka.h>
#include "unitconvert.h"
#include <stdio.h>

bool is_equal(length, length);

length data[][2] = {
    { {1, FOOT}, {1, FOOT} },
    { {3, INCH}, {3, INCH} },
    { {0, INCH}, {0, FOOT} },
    { {1, FOOT}, {12, INCH} },
    { {12, INCH}, {1, FOOT} },
    { {1, YARD}, {3, FOOT} },
    { {3, FOOT}, {1, YARD} },
    { {1, YARD}, {36, INCH} },
    { {36, INCH}, {1, YARD} },
};

void test_length_convert()
{
    for (int i = 0; i < sizeof data/sizeof data[0]; i++) 
    {
        printf("i=%d\n", i);
        length converted = convert(data[i][0], data[i][1].unit);
        assert_true(is_equal(data[i][1], converted));
    }
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
    return l1.value == l2.value && l1.unit == l2.unit;
}




