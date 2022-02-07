EXE = a1
SOBJ = a1.o
CC = g++

all:	$(EXE)

a1: $(SOBJ)
	$(CC) -o a1 $(SOBJ)

a1.o: a1.cpp  Date.h library.h reservation.h room.h
	$(CC) -c a1.cpp

clean:
	rm -f $(EXE) $(SOBJ)

