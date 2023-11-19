target =  main
sources = *.cpp
CC = g++
CCFlags = -Wall
LDLIBS = -lcrypto++ -l boost_program_options
OPT = -Ofast
all:build
build:
	$(CC) $(CCFlags) $(OPT) $(sources) -o $(target) $(LDLIBS)
dbg:
	$(CC) -g $(sources) -o $(target)DBG
