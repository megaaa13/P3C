#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

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