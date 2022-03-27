#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct product {
    char *name;
    double price;
} product_t;

double getPtrPrice(product_t *ptrProd) {
    return ptrProd->price;
}

double getPrice(product_t prod) {
    return prod.price;
}

char* getPtrName(product_t *ptrProd) {
    char* name = (char *) malloc((strlen(ptrProd -> name) + 1) * sizeof(char));
    if (name == NULL) {
        return NULL;
    }
    for (int i = 0; i < strlen(ptrProd -> name) + 1; i++) {
        *(name + i) = *(ptrProd -> name + i);
    }
    return name;
}

char* getName(product_t prod) {
    char *name = (char *) malloc((strlen(prod.name) + 1) * sizeof(char));
    if (name == NULL) {
        return NULL;
    }
    for (int i = 0; i < strlen(prod.name) + 1; i++) {
        *(name + i) = *(prod.name + i);
    }
    return name;
}

int prodEquals(product_t *ptrProd, product_t prod) {
    if (getPrice(prod) == getPtrPrice(ptrProd) && strcmp(ptrProd -> name, prod.name) == 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char *b = "aeiou";
    product_t a = {b, 10};
    printf("%s\n", getPtrName(&a));
    printf("%d\n", prodEquals(&a, a));
    return 0;
}
