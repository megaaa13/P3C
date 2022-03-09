#include <stdlib.h>

typedef struct data
{
    int longitude;
    int latitude;
    float avg_temp;
} data_t;

int put(data_t **buf, int len, int *first, int *last, int *in, data_t *d)
{
    if (len == *in)
        return -1;
    if (first == NULL)
    {
        *buf = d;
        *first = 0;
        *last = 1;
    }
    else
    {
        *(buf + *last) = d;
        *last = (*last + 1) % len;
    }
    *in = *in + 1;
    return 0;
}

data_t *get(data_t **buf, int len, int *first, int *last, int *in)
{
    if (*in == 0)
        return NULL;
    if (first == NULL)
        return NULL;
    data_t *d = buf[*first];
    *first = (*first + 1) % len;
    *in = *in - 1;
    return d;
}