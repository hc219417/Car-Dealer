#!/bin/bash
# Created by: Nasseef Abukamail
#       Date: January 5, 2019
#
# Description:
#     Find the file that has a main function and replace 'main' with 'NO_MAIN'.
#     This will allow us to import the program into the testing suite "TEST_cases.cc"
#     in order to test other functions in the source code.
#

file_name=`egrep -il ' main[ ]*\(' *.cc *.cpp *.cxx 2>/dev/null`
sed 's/ main[ ]*(/ IGNORE(/' $file_name >_TEST/NO_MAIN.cc
# show the first 10 lines in the program (author, date, etc.)
echo '\033[1;33m' '######################################################################'
head _TEST/NO_MAIN.cc
echo '\033[1;33m' '######################################################################'
echo '\033[1;m'
exit 0
