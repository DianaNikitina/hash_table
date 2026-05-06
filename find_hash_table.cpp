#include "hash_table.h"

__attribute__((noinline)) void find(char **found_words, Hash_node **hash_table)
{

    for (int i = 0; i < COUNT_FOUNDED_WORDS; i++)
    {
        find_hash_table(found_words[i], hash_table);
    }
}

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