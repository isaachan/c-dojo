#!/bin/bash

gcc --std=c99 argparser.c argparser_test.c -lcmocka
./a.out

