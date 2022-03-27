#include <stdio.h>

void swap(int *i, int *j) {
    int k = *i;
    *i = *j;
    *j = k;
}