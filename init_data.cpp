#include "hash_table.h"

int init_data(Data *arrays_of_data)
{
    arrays_of_data->data = runfile("data.txt", "r");
    if (!arrays_of_data->data)  return 1;

    arrays_of_data->founded_words = runfile("founded_words.txt", "r");
    if (!arrays_of_data->founded_words)  return 1;

    arrays_of_data->data_size = size_data(arrays_of_data->data);

    arrays_of_data->text = (char*) calloc(arrays_of_data->data_size + 1, sizeof(char));
    if (!arrays_of_data->text)
    {
        printf("ERORR ALLOCATED BUFFER FOR TEXT\n");
        return 1;
    }
    printf("CORRECT ALLOCATED BUFFER FOR TEXT\n");
    
    arrays_of_data->words_data = (char**) calloc(TABLE_SIZE * 20 + 1, sizeof(char*));
    if (!arrays_of_data->words_data)
    {
        printf("ERORR ALLOCATED BUFFER FOR WORDS\n");
        return 1;
    }
    printf("CORRECT ALLOCATED BUFFER FOR WORDS\n");

    return 0;
}