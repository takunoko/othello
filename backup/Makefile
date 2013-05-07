#Makefile

othello : othello.o reversed.o ai.o
	cc -o othello othello.o reversed.o ai.o -Wall

othello.o : othello.c
	cc -c othello.c

reversed.o : reversed.c
	cc -c reversed.c

ai.o : ai.c
	cc -c ai.c
