#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int file_exists(char *filename) {
    int nd = open(filename, O_RDONLY);
    if(nd < 0) return -1;
    close(nd);
    return 0;
}