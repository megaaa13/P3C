#include <stdio.h>

size_t strlen(const char* s) {
    int i = 0;
    while (*(s + i) != '\0') {
        i++;
    }
    return i;
}

// or int i = 0; while (*(s + i++) != '\0'); return i-1;
// c'est compact

int main(int argc, char const *argv[])
{
    printf("%ld\n", strlen("Hey salut ici la famille là"));
    return 0;
}
