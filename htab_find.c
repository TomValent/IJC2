// htab_find.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vyhladavanie v hash table

#include "htab.h"
#include "htab_struct.h"

htab_pair_t* htab_find(htab_t *table, htab_key_t key)
{
    size_t hash = htab_hash_function(key);
    size_t index = hash % table->arr_size;
    htab_pair_t *item = table->arr[index];

    if (strlen(key) == strlen(item->key))                   //prvy prvok
    {
        if (strncmp(key, item->key, strlen(key)) == 0)      //spravny kluc
        {
            return &(htab_item_t->pair);
        }
    }

    while(item->next != NULL)                               //vsetky prvky medzi
    {
        if (strlen(key) == strlen(item->key)) {
            if (strncmp(key, item->key, strlen(key)) == 0) {
                return &(htab_item_t->pair);
            }
        }

        item = item->next;
    }
    if (strlen(key) == strlen(item->key))                   //posledny prvok
    {
        if (strncmp(key, item->key, strlen(key)) == 0)
        {
            return &(htab_item_t->pair);
        }
    }
    return NULL;
}