#include <stdio.h>
#include <stdlib.h>

struct set
{
    struct node *first; // pointeur vers le premier node
    int n;              // nombre total d'éléments (pas nécessairement distincts) dans l'ensemble
};

struct node
{
    double real;       // partie réelle
    double img;        // partie imaginaire
    int count;         // nombre d'éléments ayant cette valeur
    struct node *next; // pointeur vers le noeud suivant
};

/*
 * @pre set!=NULL
 * @post le nombre complexe (real,img) a été correctement
 *       ajouté à l'ensemble set. La variable n de cet
 *       ensemble contient à tout moment la quantité de
 *       nombres complexes dans l'ensemble (qui est équivalente à
 *       la somme des count de tous les éléments de la liste chainée).
 *       La fonction retourne la quantité de nombres complexes dans
 *       l'ensemble . En cas d'erreur, retourne -1.
 */
int add(double real, double img, struct set *set)
{
    if (set -> first == NULL) {
        struct node* newNode = (struct node *) malloc(sizeof(struct node));
        newNode -> real = real;
        newNode -> img = img;
        newNode -> count = 1;
        newNode -> next = NULL;
        set -> first = newNode;
        set -> n++;
        return set-> n;
        }
    struct node *noeud = set->first;
    while (noeud->next != NULL) {
        if (noeud->real == real && noeud->img == img)
        {
            noeud->count++;
            set -> n++;
            return set->n;
        }
        noeud = noeud->next;
    }
    if (noeud->real == real && noeud->img == img)
    {
        noeud->count++;
        set -> n++;
        return set->n;
    }
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    if (newNode == NULL) {
        return -1;
    }
    newNode -> real = real;
    newNode -> img = img;
    newNode -> count = 1;
    newNode -> next = NULL;
    noeud -> next = newNode;
    set -> n++;
    return set -> n;
}

int main(int argc, char const *argv[])
{
    struct set set; set.n = 0; set.first = NULL;
    printf("1 %d\n", add(2.3,2.2,&set));
    printf("2 %d\n", add(2.3,2.2,&set));
    printf("3 %d\n", add(2.3,2.3,&set));
    printf("4 %d\n", add(2.3,2.3,&set));
    return 0;
}
