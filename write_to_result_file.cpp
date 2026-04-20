#include "hash_table.h"

int list_len(Hash_node *node)
{
    int len = 0;
    while(node != NULL)
    {
        node = node->next;
        len++;
    }
    return len;
}

int write_to_result_file(Hash_node **hash_table, const char *head_file)
{
    FILE *data_result = runfile(head_file, "w");
    if (!data_result)  return 1;

    for (int value = 0; value < TABLE_SIZE; value++)
    {
        int len = list_len(hash_table[value]);
        fprintf(data_result, "%d %d\n", value, len);
        fputc(' ', data_result);
       

    }
    return 0;
}