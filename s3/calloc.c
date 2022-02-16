#include <stdlib.h>

void *calloc2(size_t nmemb, size_t size)
{
    if (nmemb == 0 || size == 0)
        return NULL;
    void *ptdr = malloc(size * nmemb);
    if (ptdr == NULL)
        return NULL;
    for (int i = 0; i < nmemb; i++)
    {
        *(char *)(ptdr + i * size) = 0;
    }
    return ptdr;
}