#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct data
{
    int longitude;
    int latitude;
    float avg_temp;
} data_t;

/*
 * Function used to put a new value in the shared buffer.
 *
 * @buf : the shared buffer to fill in with the adresses pointing to the data_t's
 * @len : the length of the shared buffer
 * @first : the pointer to the array index where you can find the first inserted element that's still in the buffer
 *         (or more exactly the pointer to the first element, **if any**)
 * @last : the pointer to the array index where you can find the first empty space in the buffer
 *         (or more exactly the first NULL pointer in the array, **if any**)
 * @in : the number of data_t* pointers in the buffer
 * @d : the data_t* that has to be inserted in the buffer
 *
 * @return 0 if no error, -1 otherwise
 */
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

/*
 * Function used to get a value from the shared buffer.
 *
 * @buf : the shared buffer to fill out
 * @len : the length of the shared buffer
 * @first : the pointer to the array index where you can find the first element inserted that's still in the buffer
 *         (or more exactly the pointer to the first element, **if any**)
 * @last : the pointer to the array index where you can find the first empty space in the buffer
 *         (or more exactly the first NULL pointer in the array, **if any**)
 * @in : the number of data_t* pointers in the buffer
 *
 * @return the pointer to the element that you get if no error, NULL otherwise
 */
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
