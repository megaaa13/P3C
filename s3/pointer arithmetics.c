int first(void *ptr) {
    return *((int *)ptr + 3);
}

int second(void *ptr) {
    return *((char *)ptr + 6);
}

int third(void *ptr) {
    return *((int *)(ptr + 45));
}