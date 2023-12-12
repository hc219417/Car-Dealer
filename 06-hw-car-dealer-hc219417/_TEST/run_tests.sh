#!/bin/bash

echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produce 6 errors" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'
_TEST/a.out
echo
_TEST/a.out -A
echo
_TEST/a.out -X  1 3
echo
_TEST/a.out -X data.txt output.txt
echo
_TEST/a.out -a doesnotexist.txt output.txt
echo
_TEST/a.out -b data.txt
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo '\033[0;33m' "The following should produce the correct output" '\033[m'
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "Test: ./a.out -a 2000 data.txt _TEST/output.txt" '\033[m'
echo '\033[0;33m' "Should produce 8 customer data" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -a 2000 _TEST/data.txt _TEST/output.txt
echo
cat _TEST/output.txt
echo
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "Test: ./a.out -b 2000 data.txt _TEST/output.txt" '\033[m'
echo '\033[0;33m' "Should produce 5 customer data" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -b 2000 _TEST/data.txt _TEST/output.txt
echo
cat _TEST/output.txt
echo
echo '\033[0;33m' "###################################################################" '\033[m'
echo
echo '\033[0;33m' "Test: ./a.out -d 6 data.txt output.txt" '\033[m'
echo '\033[0;33m' "Should produce 5 customer data." '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -d 6 _TEST/data.txt _TEST/output.txt
echo
cat _TEST/output.txt
echo
echo '\033[0;33m' "###################################################################" '\033[m'

echo '\033[0;33m' "Test: ./a.out -A data.txt output.txt" '\033[m'
echo '\033[0;33m' "Should produce all 12 customer data. Total: 34269.36, Avg: 2855.78" '\033[m'
echo '\033[0;33m' "-------------------------------------------------------------------" '\033[m'
_TEST/a.out -A _TEST/data.txt _TEST/output.txt
echo
cat _TEST/output.txt
echo
echo '\033[0;33m' "###################################################################" '\033[m'

