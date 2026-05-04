#include "hash_table.h"

int simple_hash_func (char* word)
{
    return 0;
}

unsigned int first_letter_hash_func (char* word)
{
    if (word != NULL)
        return (unsigned int)word[0];
    return 0;
}

unsigned int len_word_hash_func (char* word)
{
    return (unsigned int)(strlen (word));
}

int sum_ascii_hash_func (char* word)
{
    int ascii_sum = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        ascii_sum += word[i];
        i++;
    }
    return ascii_sum;
}

static int rotl32 (int x, unsigned k)
{
    return (x << k) | (x >> (32 - k));
}

int rol_hash_func (const char *word)
{
    int h = 0;

    for (const unsigned char *p = (const unsigned char *)word; *p != '\0'; p++)
    {
        h = rotl32(h, 3);  
        h ^= *p;            
    }

    return h;
}


unsigned int crc32_hash_func_intrinsic (char *word)
{
    unsigned int crc = 0xFFFFFFFF;

    while (*word)
    {
        crc = _mm_crc32_u8 (crc, (unsigned char)*word);
        word++;
    }

    return (crc ^ 0xFFFFFFFF);
}

unsigned int crc32_hash_func_intrinsic_optimized (char *word)
{
    uint32_t crc = 0xFFFFFFFF;
    size_t len_word = strlen(word);
    size_t index = 0;
    uint32_t local_variable = 0;

    while(len_word - index >= 4)
    {
        memcpy (&local_variable, word + index, 4);
        crc = _mm_crc32_u32 (crc, local_variable);
        index += 4;
    }

    while (index < len_word)
    {
        crc = _mm_crc32_u8 ((unsigned int)crc, (unsigned char)*(word + index));
        index++;
    }


    return ((unsigned int)crc ^ 0xFFFFFFFF);
}

unsigned int crc32_hash_func_old (char *word)
{
    unsigned int crc = 0xFFFFFFFF;

    while (*word)
    {
        crc ^= (unsigned char)*word;

        for (int bit = 0; bit < 8; bit++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }

        word++;
    }

    return (crc ^ 0xFFFFFFFF);
}