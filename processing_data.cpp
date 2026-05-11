#include "hash_table.h"

void DataProcessing(Data *DataArrays, Files *Files)
{
    DataInit(DataArrays, Files);

    size_t nread = fread(DataArrays->text, 1, Files->data_size, Files->data);
    DataArrays->text[nread] = '\0';

    size_t nread_founded = fread(DataArrays->text_founded, 1, Files->founded_words_size, Files->founded_words);
    DataArrays->text_founded[nread_founded] = '\0';

    DataTokenizeArray(DataArrays->text, DataArrays->words_data, COUNT_WORDS);
    DataTokenizeArray(DataArrays->text_founded, DataArrays->founded_words_data, COUNT_FOUND_WORDS);
    
}

int DataInit(Data *DataArrays, Files *Files)
{
    Files->data = Runfile("data.txt", "r");
    if (!Files->data)  return 1;

    Files->founded_words = Runfile("founded_words.txt", "r");
    if (!Files->founded_words)  return 1;

    Files->data_size = DataSize(Files->data);
    Files->founded_words_size = DataSize(Files->founded_words);
    

    DataArrays->text = (char*) calloc(Files->data_size + 1, sizeof(char));
    if (!DataArrays->text)
    {
        printf("FROM DATA: ERORR ALLOCATED BUFFER FOR TEXT\n");
        return 1;
    }
    printf("FROM DATA: CORRECT ALLOCATED BUFFER FOR TEXT\n");
    printf("======================================\n\n");
    
    DataArrays->words_data = (char**) calloc(COUNT_WORDS + 1, sizeof(char*));
    if (!DataArrays->words_data)
    {
        printf("FROM DATA: ERORR ALLOCATED BUFFER FOR WORDS\n");
        return 1;
    }
    printf("FROM DATA: CORRECT ALLOCATED BUFFER FOR WORDS\n");
    printf("======================================\n\n");

    DataArrays->text_founded = (char*) calloc(Files->founded_words_size + 1, sizeof(char));
    if (!DataArrays->text_founded)
    {
        printf("FROM DATA: ERORR ALLOCATED BUFFER FOR TEXT_FOUNDED\n");
        return 1;
    }
    printf("FROM DATA: CORRECT ALLOCATED BUFFER FOR TEXT_FOUNDED\n");
    printf("======================================\n\n");

    DataArrays->founded_words_data = (char**) calloc(COUNT_FOUND_WORDS + 1, sizeof(char*));
    if (!DataArrays->founded_words_data)
    {
        printf("FROM DATA: ERORR ALLOCATED BUFFER FOR FOUNDED WORDS\n");
        return 1;
    }
    printf("FROM DATA: CORRECT ALLOCATED BUFFER FOR FOUNDED WORDS\n");
    printf("======================================\n\n");

    return 0;
}