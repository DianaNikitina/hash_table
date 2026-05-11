#include "list.h"

int ListInit(list* list, const size_t capacity)
{
    listErr_t error = LIST_CORRECT;

    if (!list || capacity == 0) {
        printf("FROM LIST:       ERROR: invalid argument\n");
        return 1;
    }

    list->capacity = capacity;

    list->data = (list_elem_t*)calloc(capacity, sizeof(list_elem_t));
    if (list->data == NULL) {
        printf("FROM LIST:       ERROR allocated data\n");
        return 1;
    }
    printf("FROM LIST:       CORRECT allocated data\n");
    printf("======================================\n\n");

    // 2. Массив next
    list->next = (int*)calloc(capacity, sizeof(int));
    if (list->next == NULL) {
        free(list->data);
        list->data = NULL;
        printf("FROM LIST:       ERROR allocated next\n");
        return 1;
    }
    printf("FROM LIST:       CORRECT allocated next\n");
    printf("======================================\n\n");


    list->prev = (int*)calloc(capacity, sizeof(int));
    if (list->prev == NULL) {
        free(list->data);
        free(list->next);
        list->data = NULL;
        list->next = NULL;
        printf("FROM LIST:       ERROR allocated prev\n");
        return 1;
    }
    printf("FROM LIST:       CORRECT allocated prev\n");
    printf("======================================\n\n");


    for (size_t i = 0; i < capacity; i++) 
    {
        list->data[i] = NULL;             
        list->prev[i] = -1;               
        list->next[i] = (i == capacity - 1) ? -1 : (int)(i + 1); 
    }

    list->free = 0;              
    list->cur_index = -1;       
    list->size = 0;

    LIST_OK(list, error);        
    return 0;
}