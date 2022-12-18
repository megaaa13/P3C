#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * @pre str, prefix, res !=NULL, res pointe vers une zone mémoire
 * @ret place dans res le suffixe de str dont on a retiré le préfix prefix
 */
void removeprefix(char *str, char *prefix, char *res)
{
    int i = 0;
    int prefixed = 1;
    while (*(prefix + i) != '\0')
    {
        if (*(prefix + i) != *(str + i))
        {
            prefixed = 0;
        }
        i++;
    }
    if (prefixed) {
        strcpy(res, str + i);
        return;
    }
    strcpy(res, str);
    return;
}

int main(int argc, char const *argv[])
{
    char *res = (char *)malloc(sizeof(char *));
    char *str = "UCLouvain <3";
    char *prefix = "UCL";
    removeprefix(str, prefix, res);
    printf("%s\n", res);
    char *prefix1 = "KUL";
    removeprefix(str, prefix1, res);
    printf("%s\n", res);
    return 0;
}
