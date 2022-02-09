#include <string.h>
#include <stdio.h>
/*
* @return: returns true (1) if str is a palindrome, -1 if str is NULL, otherwise false (0).
*/
int pal(char *str) {
    if (str == 0) {
        return -1;
    }
    int j = strlen(str) - 1;
    int i = 0;
    int size = strlen(str);
    while (i != j && size != 0) {
        if (*(str + i) != ' ' && *(str + j) != ' ') {
            if (*(str + i) != *(str + j)) {
                return 0;
            } else {
                i++;
                j--;
                size = size - 2;
            }
        } else {
            if (*(str + i) == ' ') {
                i++;
                size--;
            }
            if (*(str + j) == ' ') {
                j--;
                size--;
            }
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    printf("%d\n", pal(""));
    return 0;
}
