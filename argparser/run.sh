#!/bin/bash

gcc --std=c99 argparser.c argparser_tests.c -lcmocka && ./a.out

