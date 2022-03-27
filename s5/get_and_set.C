#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

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