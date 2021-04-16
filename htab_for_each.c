// htab_for_each.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Prevedenie funkcie pre kazdy zaznam

#include "htab.h"
#include "htab_struct.h"

htab_t htab_for_each(const htab_t *table, void (*f)(htab_pair_t *data))
{
    for(unsigned int i; i < table->arr_size; i++)
    {
        struct htab_item *tmp = table->arr[i];
        if(table->arr[i] != NULL)
        {
            while(tmp)
            {
                f(tmp);
                if(tmp->next != NULL)
                    tmp=tmp->next;
                else
                    break;
            }
        }
    }
    return *table;
}
