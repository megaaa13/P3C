#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;
/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename)
{
    int fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR);
    if (fd == -1) return -1;
    if (ftruncate(fd, size*sizeof(point_t)) == -1) {
        close(fd);
        return -6;
    }
    point_t* adrr = (point_t*) mmap(NULL, size*sizeof(point_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED) {
        close(fd);
        return -2;
    }
    memcpy((void*) adrr, (const void *) pt, size*sizeof(point_t));
    int ret = msync(adrr, size*sizeof(point_t), MS_SYNC);
    if (ret == -1) {
        close(fd);
        munmap(adrr, size*sizeof(point_t));
        return -5;
    }
    ret = munmap(adrr, size*sizeof(point_t));
    if (ret == -1) {
        close(fd);
        return -4;
    }
    if (close(fd) == -1) {
        return -2;
    }
    return 0;
}

int sum_file(char *filename) {
    
}
