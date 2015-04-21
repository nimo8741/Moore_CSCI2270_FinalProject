#makefile for CSCI 2270 Final Project

OBJS = SenderFunctions.o 
CC = g++
CPPFLAGS = -Wall -Wextra -std=c++11
PROG = msgSend


$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS) MessageSender.cpp

SenderFunctions.o: SenderFunctions.h SenderFunctions.cpp
	$(CC) $(CPPFLAGS) -c SenderFunctions.cpp

clean:
	$(RM)  $(PROG) $(OBJS)