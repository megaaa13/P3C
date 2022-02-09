#include <stdio.h>

void format_str(char *buffer, unsigned int d, char *name, char initial) {
    sprintf(buffer, "Mister %s %c. has %d eggs", name, initial, d);
}

int main(int argc, char const *argv[])
{
    char arr[80];
    format_str(arr, 42, "Jacky", 'B');
    printf("%s\n", arr);
    return 0;
}