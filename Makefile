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

htab_bucket_count.o: htab_bucket_count.c
	$(C) $(CFLAGS) -c htab_bucket_count.c -o htab_bucket_count.o

htab_clear.o: htab_clear.c
	$(C) $(CLFAGS) -c htab_clear.c -o htab_clear.o

htab_erase.o: htab_erase.c
	$(C) $(CFLAGS) -c htab_erase.c -o htab_erase.o

htab_find.o: htab_find.c
	$(C) $(CFLAGS) -c htab_find.c -o htab_find.o

htab_for_each.o: htab_for_each.c
	$(C) $(CFLAGS) -c htab_for_each.c -o htab_for_each.o

htab_free.o: htab_free.c
	$(C) $(CGLAGS) -c htab_free.c -o htab_free.o

htab_hash_function.o: htab_hash_function.c
	$(C) $(CFLAGS) -c htab_hash_function.c -o htab_hash_function.o

htab_init.o: htab_init.c
	$(C) $(CFLAGS) -c htab_init.c -o htab_init.o

htab_lookup_add.o: htab_lookup_add.c
	$(C) $(CFLAGS) -c htab_lookup_add.c -o htab_lookup_add.o

htab_move.o: htab_move.c
	$(C) $(CFLAGS) -c htab_move.c -o htab_move.o

htab_size.o: htab_size.c
	$(C) $(CFLAGS) -c htab_size.c -o htab_size.o

libhtab.a: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o
	ar rcs libhtab.a $^

libhtab.so: htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_for_each.o htab_free.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_move.o htab_size.o
	$(C) -fPIC -shared $^ -o $@

%.o: %.c
	$(C) -fPIC -c $< htab.h htab_struct.h

clean:
	rm *.o tail libhtab.a libhtab.so wordcount wordcount-dynamic -f

zip:
	zip xvalen27.zip *.c *.h Makefile