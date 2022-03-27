#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int protect(void inc(void), int nb, pthread_mutex_t *mutex)
{
    for (int i = 0; i < nb; i++)
    {
        if (pthread_mutex_lock(mutex) != 0)
            return -1;
        inc();
        if (pthread_mutex_unlock(mutex) != 0)
            return -1;
    }
    return 0;
}