#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int doMyWork(void *long_computing(void *), void *backup_computing(void *), char *string, int ret_value)
{
    pthread_t t;
    int i = pthread_create(&t, NULL, long_computing, ((void *)string));
    if (i != 0)
        return -1;
    void *j;
    i = pthread_join(t, &j);
    if (i != 0)
        return -2;
    if (*((int *)j) != ret_value)
    {
        i = pthread_create(&t, NULL, backup_computing, ((void *)string));
        if (i != 0)
            return -3;
        void *k;
        i = pthread_join(t, &k);
        if (i != 0)
            return -4;
    }
    return *((int *)j);
}