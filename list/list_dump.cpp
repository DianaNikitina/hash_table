#include "list.h"

int ListDump(list *lst, listErr_t error, const char *file,const char *function, int line) 
{
    printf("listDump called from %s:%d (%s)\n\n", file, line, function);

    if (error) 
    {
        printf("ERROR CODE: %d\n", error);
        if (error & LIST_BAD_POINTER_PASSED_IN_FUNC)
            printf("  - LIST_BAD_POINTER_PASSED_IN_FUNC\n");
        if (error & LIST_CRASH_IN_CALLOC_OF_NODE)
            printf("  - LIST_CRASH_IN_CALLOC_OF_NODE\n");
        if (error & LIST_DATA_CORRUPTED)
            printf("  - LIST_DATA_CORRUPTED\n");
    }

    if (!lst) 
    {
        printf("list pointer is NULL\n");
        return -1;
    }

    return 0;
}