#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct point
{
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
    if (fd == -1)
        return -1;
    if (ftruncate(fd, size * sizeof(point_t)) == -1)
    {
        close(fd);
        return -6;
    }
    point_t *adrr = (point_t *)mmap(NULL, size * sizeof(point_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED)
    {
        close(fd);
        return -2;
    }
    memcpy((void *)adrr, (const void *)pt, size * sizeof(point_t));
    int ret = msync(adrr, size * sizeof(point_t), MS_SYNC);
    if (ret == -1)
    {
        close(fd);
        munmap(adrr, size * sizeof(point_t));
        return -5;
    }
    ret = munmap(adrr, size * sizeof(point_t));
    if (ret == -1)
    {
        close(fd);
        return -4;
    }
    if (close(fd) == -1)
    {
        return -2;
    }
    return 0;
}

int sum_file(char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;
    struct stat buf;
    if (fstat(fd, &buf) == -1)
    {
        close(fd);
        return -5;
    }
    int sum = 0;
    if (buf.st_size == 0)
    {
        close(fd);
        return sum;
    }
    int *adrr = (int *)mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED)
    {
        close(fd);
        return -3;
    }
    if (close(fd) < 0)
    {
        munmap((void *)adrr, buf.st_size);
        return -2;
    }
    for (int i = 0; i < (buf.st_size / sizeof(int)); i++)
    {
        sum += *(adrr + i);
    }
    if (munmap((void *)adrr, buf.st_size) == -1)
        return -4;
    return sum;
}

int get(char *filename, int index)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return -1;
    struct stat buf;
    if (fstat(fd, &buf) == -1)
    {
        close(fd);
        return -1;
    }
    if (buf.st_size / sizeof(int) < index)
    {
        close(fd);
        return -2;
    }
    int *adrr = (int *)mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED)
    {
        close(fd);
        return -1;
    }
    int res = *(adrr + index);
    if (close(fd) == -1 || munmap((void *)adrr, buf.st_size) == -1)
    {
        return -1;
    }
    return res;
}

void set(char *filename, int index, int value)
{
    int fd = open(filename, O_RDWR);
    if (fd == -1)
        return;
    struct stat buf;
    if (fstat(fd, &buf) == -1)
    {
        close(fd);
        return;
    }
    if (buf.st_size / sizeof(int) < index)
    {
        close(fd);
        return;
    }
    int *adrr = (int *)mmap(NULL, buf.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED)
    {
        close(fd);
        return;
    }
    *(adrr + index) = value;
    if (msync((void *)adrr, buf.st_size, MS_SYNC) == -1 || close(fd) == -1 || munmap((void *)adrr, buf.st_size) == -1)
    {
        return;
    }
    return;
}

int copy(char *file_name, char *new_file_name)
{
    int fd = open(file_name, O_RDONLY);
    if (fd == -1)
        return -1;
    struct stat buf;
    if (fstat(fd, &buf) == -1)
    {
        close(fd);
        return -1;
    }
    int fd1 = open(new_file_name, O_RDWR | O_TRUNC | O_CREAT, buf.st_mode);
    if (fd == -1)
        return -1;
    if (ftruncate(fd1, buf.st_size) == -1)
    {
        close(fd);
        close(fd1);
        return -1;
    }
    int *adrr = (int *)mmap(NULL, buf.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (adrr == MAP_FAILED)
    {
        close(fd);
        close(fd1);
        return -1;
    }
    void *adrr1 = mmap(NULL, buf.st_size, PROT_WRITE | PROT_READ, MAP_SHARED, fd1, 0);
    if (adrr1 == MAP_FAILED)
    {
        close(fd);
        close(fd1);
        munmap(adrr, buf.st_size);
        return -1;
    }
    if (close(fd) == -1)
    {
        close(fd1);
        munmap(adrr, buf.st_size);
        munmap(adrr1, buf.st_size);
        return -1;
    }
    if (close(fd1) == -1)
    {
        munmap(adrr, buf.st_size);
        munmap(adrr1, buf.st_size);
        return -1;
    }
    memcpy(adrr1, adrr, buf.st_size);
    if (msync(adrr1, buf.st_size, MS_SYNC) == -1)
    {
        munmap(adrr, buf.st_size);
        munmap(adrr1, buf.st_size);
        return -1;
    }
    if (munmap(adrr, buf.st_size) == -1)
    {
        munmap(adrr1, buf.st_size);
        return -1;
    }
    if (munmap(adrr1, buf.st_size) == -1)
    {
        return -1;
    }
    return 0;
}
