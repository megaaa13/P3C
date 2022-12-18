#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/*
 * @pre str!=NULL, chars!=NULL
 * @ret retourne un pointeur vers un chaîne contenant str dont
 *  on a supprimé en fin tous les caractères se trouvant dans chars.
 *      Supprime les espaces si chars="" ou chars=NULL
 */
char *rstrip(char *str, char *chars){
    char* strip = (char *) malloc((strlen(str) + 1) * sizeof(char));
    if (strip == NULL) return NULL;
    int i = 0;
    int notsuffix = 0;
    while(*(str + i) != '\0') {
        int inchars = 0;
        int j = 0;
        while(*(chars + j) != '\0') {
            if (*(str + i) == *(chars + j)) {
                inchars = 1;
            }
            j++;
        }
        i++;
        if (!inchars) {
            notsuffix = i;
        }
    }
    for (int k = 0; k <= i; k++) {
        if (k >= notsuffix) {
            *(strip + k) = '\0';
        } else {
            *(strip + k) = *(str + k);
        }
    }
    return strip;
}

int main(int argc, char const *argv[])
{
    char* str = "www.helloworld.com";
    char* chars = "cmoa.";
    printf("%s<anti-espace>\n", rstrip(str, chars));

    char* chars1 = "ldcmor.";
    printf("%s<anti-espace>\n", rstrip(str, chars1));

    char* str2 = "www.mozilla.org    ";
    char* chars2 = " ";
    printf("%s<anti-espace>\n", rstrip(str2, chars2));
    char* str3 = "abccc";
    char* chars3 = "c";
    printf("%s<anti-espace>\n", rstrip(str3, chars3));
    return 0;
}
