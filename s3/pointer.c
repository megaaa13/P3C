int first(void *ptr) {
    return *((int *)ptr + 3);
}

int second(void *ptr) {
    return *((char *)ptr + 3);
}

int third(void *ptr) {
    return *((int *)(ptr + 45))
}