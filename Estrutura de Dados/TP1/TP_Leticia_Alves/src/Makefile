CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g
EXEC=./tp1
TMPOUT=tp1.testresult

$(EXEC): main.o lista.o celula.o
	$(CC) $(CFLAGS) -o $(EXEC) main.o lista.o celula.o

main.o: main.cpp includes/lista.hpp includes/celula.hpp
	$(CC) $(CFLAGS) -c main.cpp

lista.o: lista.cpp includes/lista.hpp includes/celula.hpp
	$(CC) $(CFLAGS) -c lista.cpp

celula.o: celula.cpp includes/celula.hpp
	$(CC) $(CFLAGS) -c celula.cpp
	
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

.PHONY: clean

clean:
	rm -f *.o