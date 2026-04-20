#include "hash_table.h"

size_t size_data(FILE *file)
{
    long int size = 0;
    
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);

    return (size_t) size;
}