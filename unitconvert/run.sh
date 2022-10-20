#!/bin/bash

gcc --std=c99 unitconvert.c unitconvert_tests.c -lcmocka
./a.out

