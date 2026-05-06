#include "hash_table.h"

static Hash_node *hash_table[TABLE_SIZE] = { nullptr };

int main()
{
    Data arrays_of_data = {.text = NULL, .words_data = NULL, .data = NULL, .founded_words = NULL, .data_size = 0, .count_str = 0};

    init_data(&arrays_of_data);

    size_t nread = fread(arrays_of_data.text, 1, arrays_of_data.data_size, arrays_of_data.data);
    arrays_of_data.text[nread] = '\0';

    tokenize_array_data(arrays_of_data.text, arrays_of_data.words_data);

    add_hash_table(arrays_of_data.words_data, hash_table);

    /*for (int i = 0; i < 3000; i++)
    {*/
        int count_word = find_hash_table("next", hash_table);
        printf("%d - count next\n", count_word);
    /*}*/


    write_to_result_file(hash_table, "hash_data/data_result_simple.csv");

    fclose(arrays_of_data.data);
    fclose(arrays_of_data.founded_words);
    free(arrays_of_data.text);
    free(arrays_of_data.words_data);
    return 0;
}

