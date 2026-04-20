#include "hash_table.h"

int simple_hash_func (char* word)
{
    return 0;
}

int first_letter_hash_func (char* word)
{
    if (word != NULL)
        return word[0];
    return 0;
}