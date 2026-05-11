#include "hash_table.h"

void HashTableDestroy (HashTable *hash_table)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        ListDestroy(&hash_table->Buckets[i]);
    free(hash_table->Buckets);
    hash_table->Buckets = NULL;
    hash_table->HashTableCapacity = 0;
    hash_table->Size = 0;
    hash_table->HashFunction = NULL;
}

void DataDestroy(Data *DataArrays, Files *Files)
{
    fclose(Files->data);
    fclose(Files->founded_words);
    free(DataArrays->text);
    free(DataArrays->words_data);
    free(DataArrays->founded_words_data);
    free(DataArrays->text_founded);
    DataArrays->text = NULL;
    DataArrays->words_data = NULL;

}