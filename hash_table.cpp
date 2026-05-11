#include "hash_table.h"

unsigned int time_genera;

int main()
{
    /*const char* test_words[3] = {"next", "animal", "cat"};
    for (int i = 0; i < 3; i++)
    {
        uint32_t hash_value_old = crc32_hash_func_old(test_words[i]);
        uint32_t hash_value_asm = crc32_hash_asm_no_strlen(test_words[i]);
        printf ("%u - hash_value_old\n %u - hash_value_asm\n", hash_value_old, hash_value_asm);

    }*/

    HashTable hash_table = {0};
    HashTableErr_t error = HashTableInit(&hash_table, TABLE_SIZE);

    Data DataArrays = {0};
    Files Files = {0};
    DataProcessing(&DataArrays, &Files);
    
    error = HashTableAdd(DataArrays.words_data, &hash_table);
    printf("======================================\n\n");

    int result = HashTableFind(DataArrays.founded_words_data, &hash_table);
    printf("%d - result\n", result);

    printf("cycles: %ld\n", time_general/111217000);

    WriteToFile(&hash_table, "hash_data/data_result_simple.csv");

    HashTableDestroy(&hash_table);
    DataDestroy(&DataArrays, &Files);

    return 0;
}

