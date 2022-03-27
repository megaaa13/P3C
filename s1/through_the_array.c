int tab_find(int tab[], int len, int elem) {
    for (int i = 0; i < len; ++i) {
        if (elem == tab[i])
            return i;
    }
    return -1;
}