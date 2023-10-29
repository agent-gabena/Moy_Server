TARGET =  Server
SOURCES = *.cpp
CC = g++
CCFlags = -Wall
LIBS = -lcrypto++ -l boost_program_options
all:build
build:
	$(CC) $(CCFlags) $(SOURCES) -o $(TARGET) $(LIBS)
dbg:
	$(CC) -g $(SOURCES) -o $(TARGET)DBG
