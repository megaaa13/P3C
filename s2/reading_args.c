#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    for (i = 1 ; i< argc ; i = i + 2) {
        printf("%s", *(argv + i));
        if (i + 2 < argc) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
