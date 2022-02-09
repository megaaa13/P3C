#include <stdio.h>

int strcasecmpe(const char *s1, const char *s2) {
    int i = 0;
    while (*(s1 + i) != '\0' || *(s2 + i) != '\0') {
        if (*s1 == '\0') return -1;
        if (*s2 == '\0') return 1;
        if ((*(s1 + i) - *(s2 + i)) > 0) {
            if ((*(s1 + i) - 32 - *(s2 + i)) != 0 && (*(s1 + i) + 32 - *(s2 + i)) != 0) {
                return 1;
            }
        }
        if ((*(s1 + i) - *(s2 + i)) < 0) {
            if ((*(s1 + i) - 32 - *(s2 + i)) != 0 && (*(s1 + i) + 32 - *(s2 + i)) != 0)
                return -1;
        }
        i++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    printf("%i\n", strcasecmpe("oula", "Oula"));
    return 0;
}
