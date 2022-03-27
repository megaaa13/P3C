#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

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
