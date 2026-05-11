#include "hash_table.h"

int WriteToFile(HashTable *hash_table, const char *head_file)
{
    FILE *data_result = Runfile(head_file, "w");
    if (!data_result)  return 1;

    for (int value = 0; value < TABLE_SIZE; value++)
    {
        size_t len = hash_table->Buckets->size;
        fprintf(data_result, "%d\n", (int)len);
        // fprintf(data_result, "%d %d\n", value, len);
        // fputc(' ', data_result);

    }
    return 0;
}