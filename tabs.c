#include <limits.h>
#include <stdio.h>

struct s {
    float f;
    int id;
};

/**
* @pre tab est un pointeur vers un tableau,
* @pre elem une structure de type s et
* @pre size est la taille du tableau
* @post: retourne le nombre d'éléments du tableau qui sont égaux à elem
**/
int fTab(struct s *tab, struct s elem, unsigned int size){
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (tab[i].f == elem.f && tab[i].id == elem.id) {
            count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    struct s tab[]={
    {1.23, 12},
    {1.23, 94},
    {4.56, 12},
    {1.23, 12}
    };
    struct s e = {4.56,12};
    int a = fTab(tab, e, 4);
    printf("%d\n", a);
    return 0;
}
