#include "hash_table.h"

void add_hash_table(char **words, Hash_node **hash_table)
{
    int i = 0;

    while (words[i] != NULL)
    {
        int value = simple_hash_func (words[i]) % TABLE_SIZE;
        if (value < 0) value += TABLE_SIZE;


        Hash_node *current = hash_table[value];
        int found = 0;

        while (current != NULL)
        {
            if (strcmp(current->word, words[i]) == 0)
            {
                current->counter++;
                found = 1;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            Hash_node *new_node = (Hash_node*)calloc(1, sizeof(Hash_node));
            if (new_node == NULL) return;

            new_node->word = (char*)calloc(strlen(words[i]) + 1, sizeof(char));
            if (new_node->word == NULL)
            {
                free(new_node);
                return;
            }

            strcpy(new_node->word, words[i]);
            new_node->counter = 1;
            new_node->next = hash_table[value];
            hash_table[value] = new_node;
        }

        i++;
    }
}