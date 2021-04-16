// htab_find.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vyhladavanie v hash table

#include "htab.h"
#include "htab_struct.h"

struct htab_pair_t* htab_find(htab_t *table, htab_key_t key)
{
    size_t hash = htab_hash_function(key);
    size_t index = hash % table->arr_size;
    struct htab_item *item = table->arr[index];

    if (strlen(key) == strlen(item->pair->key))                   //prvy prvok
    {
        if (strncmp(key, item->pair->key, strlen(key)) == 0)      //spravny kluc
        {
            return (item->pair);
        }
    }

    while(item->next != NULL)                               //vsetky prvky medzi
    {
        if (strlen(key) == strlen(item->pair->key)) {
            if (strncmp(key, item->pair->key, strlen(key)) == 0) {
                return (item->pair);
            }
        }

        item = item->next;
    }
    if (strlen(key) == strlen(item->pair->key))                   //posledny prvok
    {
        if (strncmp(key, item->pair->key, strlen(key)) == 0)
        {
            return (item->pair);
        }
    }
    return NULL;
}