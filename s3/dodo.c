#include <unistd.h>
#include <stdlib.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
    void* result;
    for (size_t i = 0; i < 10; i++)
    {
        result = malloc(s);
        if (result != NULL) return result;

        sleep(5);
    }
    return NULL;
}