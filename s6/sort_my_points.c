#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct points
{
    int NOMA;
    float LEPL1103;
    float LEPL1203;
    float LEPL1108;
    float LEPL1302;
    float LEPL1402;
    float average;
} points_t;

int compar(const void *s1, const void *s2)
{
    float a1 = ((points_t *)s1)->average;
    float a2 = ((points_t *)s2)->average;
    if (a1 < a2)
    {
        return -1;
    }
    else if (a1 > a2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int sort(char *filename)
{
    int fd = open(filename, O_RDWR);
    if (fd == -1)
        return -1;
    struct stat stats;
    if (fstat(fd, &stats) == -1)
    {
        close(fd);
        return -5;
    }
    void *address = mmap(NULL, stats.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (address == MAP_FAILED)
    {
        close(fd);
        return -2;
    }
    points_t *students = (points_t *)address;
    for (int i = 0; i < stats.st_size / sizeof(points_t); i++)
    {
        (students + i)->average = ((students + i)->LEPL1103 + (students + i)->LEPL1203 + (students + i)->LEPL1108 + (students + i)->LEPL1302 + (students + i)->LEPL1402) / 5.0f;
    }
    qsort(address, stats.st_size / sizeof(points_t), sizeof(points_t), compar);
    if (msync(address, stats.st_size, MS_SYNC) == -1)
    {
        munmap(address, stats.st_size);
        close(fd);
        return -4;
    }
    if (munmap(address, stats.st_size) == -1)
    {
        close(fd);
        return -3;
    }
    if (close(fd) == -1)
        return -6;
    return 0;
}