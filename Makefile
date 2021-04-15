# Makefile
# Riesenie IJC-DU2, priklad a), 20. 4. 2021
# Autor: Tomas Valent
# Prekaldac: gcc 9.3
# Makefile pre druhu ulohu v IJC

C=gcc
CFLAGS= -std=c99 -pedantic -Wall -Wextra -g

all: tail libhtab.a libhtab.so wordcount wordcount-dynamic

tail: tail.o
	$(C) $(CFLAGS) tail.o -o tail

tail.o: tail.c
	$(C) $(CFLAGS) -c tail.c -o tail.o

#wordcount program
wordcount: wordcount.o io.o libhtab.a
	$(C) $^ -o $@

wordcount-dynamic: wordcount.o io.o libhtab.so
	$(C) $^ -o $@

wordcount.o: wordcount.c
	$(C) -c $<

io.o: io.c io.h
	$(C) -c $<

libhtab.a: htab.h htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_move.c htab_size.c htab_struct.h
	ar rcs $@ $^

libhtab.so: htab.h htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_move.c htab_size.c htab_struct.h
	$(C) -fPIC -shared $^ -o $@

wordcount.o:  io.c io.h
	$(C) $(CFLAGS) -c htab.h htab_bucket_count.c htab_clear.c htab_erase.c htab_find.c htab_for_each.c htab_free.c htab_hash_function.c htab_init.c htab_lookup_add.c htab_move.c htab_size.c htab_struct.h io.c io.h -o wordcount.o

%.o: %.c
	$(C) -fPIC -c $< htab.h htab_struct.h

clean:
	rm *.o tail libhtab.a libhtab.so wordcount wordcount-dynamic -f

zip:
	zip xvalen27.zip *.c *.h Makefile