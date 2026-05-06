#include "hash_table.h"


int main()
{
    Hash_node **hash_table = (Hash_node**)calloc(TABLE_SIZE+1, sizeof(Hash_node*));
    Data arrays_of_data = {.text = NULL, .words_data = NULL, .data = NULL, .founded_words = NULL, .data_size = 0, .count_str = 0};

    init_data(&arrays_of_data);

    size_t nread = fread(arrays_of_data.text, 1, arrays_of_data.data_size, arrays_of_data.data);
    arrays_of_data.text[nread] = '\0';

    size_t nread_founded = fread(arrays_of_data.text_founded, 1, arrays_of_data.founded_words_size, arrays_of_data.founded_words);
    arrays_of_data.text_founded[nread_founded] = '\0';

    tokenize_array_data(arrays_of_data.text, arrays_of_data.words_data, TABLE_SIZE);
    tokenize_array_data(arrays_of_data.text_founded, arrays_of_data.founded_words_data, COUNT_FOUNDED_WORDS);
    
    add_hash_table(arrays_of_data.words_data, hash_table);

    char ** found_words = arrays_of_data.founded_words_data;
    for (int i = 0; i < 3006; i++)
    {
        find_hash_table(found_words[i], hash_table);
    }

    write_to_result_file(hash_table, "hash_data/data_result_simple.csv");

    fclose(arrays_of_data.data);
    fclose(arrays_of_data.founded_words);
    free(arrays_of_data.text);
    free(arrays_of_data.words_data);
    free(arrays_of_data.founded_words_data);
    free(arrays_of_data.text_founded);
    return 0;
}

