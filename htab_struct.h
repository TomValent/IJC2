// htab.h
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Struktura pre funkcie hash tabulky

#ifndef IJC2_HTAB_STRUCT_H
#define IJC2_HTAB_STRUCT_H

#include "htab.h"

struct htab_item
{
    char *key;
    int data;
    struct htab_item *next;
};

struct htab
{
    size_t size;
    size_t arr_size;
    struct htab_item *arr[];
};

#endif //IJC2_HTAB_STRUCT_H