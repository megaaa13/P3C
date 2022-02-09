#include <stdio.h>

char *strcate(char *dest, const char *src)
{
    int i = 0;
    while (*(dest + i) != '\0')
    {
        i++;
    }
    int j = 0;
    while (*(src + j) != '\0')
    {
        *(dest + i + j) = *(src + j);
        j++;
    }
    *(dest + i + j) = '\0';
    return dest;
}

int main(int argc, char const *argv[])
{
    char s1[10] = "Hello ";
    char s2[10] = "World\n";
    char *s3 = strcate(s1,s2);
    printf("%s", s3);
    return 0;
}

