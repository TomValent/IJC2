// htab_move.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Move konstruktor hash tabulky

#include "htab.h"
#include "htab_struct.h"

htab_t htab_move(size_t number, htab_t *t2)
{
    htab_t table = htab_init(number);   //nova tabulka so zadanou velkostou
    if(table == NULL)
        return NULL;
    htab_t tmp = *t2;
    *t2 = *table;
    *table = tmp;

    t2 = init_clear(t2);                //todo vypraznidni tabulku
    return table;
}