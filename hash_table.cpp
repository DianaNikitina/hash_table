#include "hash_table.h"

int main()
{
    Data array_data = {.text = NULL, .count_str = 0};
    Hash_node *hash_table[TABLE_SIZE] = { NULL }; 

    FILE *data = runfile("data.txt", "r");
    if (!data)  return 1;

    size_t text_size = size_data(data);

    array_data.text = (char*) calloc(text_size + 1, sizeof(char));
    if (!array_data.text)
    {
        printf("ERORR ALLOCATED BUFFER FOR TEXT\n");
        return 1;
    }
    printf("CORRECT ALLOCATED BUFFER FOR TEXT\n");
    
    char **words = (char**) calloc(4001, sizeof(char*));
    if (!words)
    {
        printf("ERORR ALLOCATED BUFFER FOR WORDS\n");
        return 1;
    }
    printf("CORRECT ALLOCATED BUFFER FOR WORDS\n");

    size_t nread = fread(array_data.text, 1, text_size, data);
    array_data.text[nread] = '\0';

    tokenize_array_data(array_data.text, words);

    add_hash_table(words, hash_table);

    write_to_result_file(hash_table, "data_result_first_letter.csv");

    fclose(data);
    free(array_data.text);
    free(words);
    return 0;
}

