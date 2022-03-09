#include <pthread.h>

int protect(void inc(void), int nb, pthread_mutex_t* mutex){
    for (int i = 0; i < nb; i++) {
    if (pthread_mutex_lock(mutex)!=0) return -1;
    inc();
    if (pthread_mutex_unlock(mutex)!=0) return -1;
}
return 0;
}