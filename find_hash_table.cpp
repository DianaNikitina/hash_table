#include "hash_table.h"

int find_hash_table(char *word, Hash_node **hash_table)
{
    int value = crc32_hash_func_intrinsic_optimized((char*)word) % TABLE_SIZE;

    Hash_node *current = hash_table[value];

    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            return current->counter;
        }
        current = current->next;
    }

    return 0; 
}