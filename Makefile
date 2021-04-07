# Makefile
# Riesenie IJC-DU2, priklad a), 20. 4. 2021
# Autor: Tomas Valent
# Prekaldac: gcc 9.3
# Makefile pre druhu ulohu v IJC

C=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra -g

all: tail

tail: tail.o
	$(C) $(CFLAGS) tail.o -o tail

tail.o: tail.c
	$(C) $(CFLAGS) -c tail.c -o tail.o

clean:
	rm *.o tail -f

zip:
	zip xvalen27.zip *.c *.h Makefile