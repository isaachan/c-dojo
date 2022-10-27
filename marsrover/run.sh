#!/bin/bash

gcc --std=c99 marsrover.c marsrover_tests.c -lcmocka && ./a.out
