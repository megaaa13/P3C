struct fract_t
{
    int num;
    int denum;
};

void swap(struct fract_t *a, struct fract_t *b)
{
    int k1 = a->num;
    int k2 = a->denum;
    a->num = b->num;
    a->denum = b->denum;
    b->num = k1;
    b->denum = k2;
}