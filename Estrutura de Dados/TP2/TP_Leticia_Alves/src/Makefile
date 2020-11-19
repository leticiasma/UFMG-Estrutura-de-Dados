CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp2
TMPOUT=tp2.testresult

$(EXEC): main.o planeta.o ordenacao.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o planeta.o ordenacao.o

main.o: main.cpp includes/planeta.hpp includes/ordenacao.hpp
	$(CC) $(CFLAGS) -c main.cpp

celula.o: ordenacao.cpp includes/ordenacao.hpp includes/planeta.hpp
	$(CC) $(CFLAGS) -c ordenacao.cpp
	
lista.o: planeta.cpp includes/planeta.hpp
	$(CC) $(CFLAGS) -c planeta.cpp
	
test: $(EXEC)
	@bash ../run_tests.sh $(EXEC) $(TMPOUT)

.PHONY: clean

clean:
	rm -f *.o