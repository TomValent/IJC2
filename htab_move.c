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

    for(size_t i; i < table->arr_size; i++)     //presun do novej tabulky
    {
        struct htab_item *tmp = table->arr[i];
        if(table->arr[i] != NULL)
        {
            size_t hash htab_hash_function(i);
            size_t newIndex = hash % t2->arr_size;

            while(tmp)
            {
                t2->arr[newIndex] = tmp->arr[i];
                if(tmp->next != NULL)
                    tmp = tmp->next;
                else
                    break;
            }
        }
    }

    t2 = htab_clear(t2);
    return table;
}