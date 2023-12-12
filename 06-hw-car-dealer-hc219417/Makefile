# Makefile for testing functions submitted with a main function
# It uses catch testing library
# Compile your program: make
# Run your program:  ./a.out
# Run tests: make run_tests
#

#Variables
FNAME = car-dealer.cc			# replace with your file name
CFLAGS = -Wall -std=c++11
CC = g++

# Replace with your own file names in the following two lines.
a.out: $(FNAME)
	sh _TEST/configure.sh
	$(CC) $(CFLAGS) $(FNAME) -o a.out


########################### DO NOT MODIFY THIS RULE ############################
#                           make and run the tests                             #
# run_tests:
# 	sh _TEST/configure.sh
# 	#$(CC) $(CFLAGS) _TEST/TEST_cases.cc -o _TEST/run_tests && ./_TEST/run_tests -s
# 	$(CC) $(CFLAGS) $(FNAME) -o _TEST/a.out

# 	sh _TEST/run_tests.sh
#	rm -rf ./_TEST/NO_MAIN.cc ./_TEST/run_tests
################################################################################


clean:
	rm -rf a.out *.o _TEST/NO_MAIN.cc _TEST/run_tests _TEST/a.out
