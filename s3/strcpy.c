#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
    if (src == NULL) return NULL;

    char *r = (char*) malloc((strlen(src) + 1) * sizeof(char));
    if (r == NULL) return NULL;
    int i = 0;
    while (*(src+i) != '\0') {
        *(r+i) = *(src + i);
        i++;
    }
    *(r + i) = '\0';
    return r;
}

int main(int argc, char const *argv[])
{
    char *s = buf_strcpy("zoiueouiheoiuyyhuh");
    printf("|%s|\n", s);
    free(s);
    printf("|%s|\n", s);
    return 0;
}
