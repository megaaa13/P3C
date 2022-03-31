#include <stdlib.h>
#include <string.h>

struct node
{
    struct node *next;
    int hash;
    int id;
    char name[20];
    char buffer[100];
    unsigned int timestamp;
    char acl;
    short flow;
    char *parent;
    void *fifo;
};

/* pair_filter
 * Make a copy of the linked list starting at head,
 * only taking the elements with an even index
 *
 * @head : head of a linked list, possibly NULL
 * @return: pointer to the filtered linked list, return NULL if error or if head == NULL
 */
struct node *pair_filter(struct node *head)
{
    if(head == NULL) return NULL; //We are at the end of the list

    struct node *newNode = (struct node*) malloc(sizeof(struct node)); 
    if(newNode==NULL) return NULL;
    
    memcpy(newNode, head, sizeof(struct node));

    if(head->next == NULL) newNode->next = NULL; //If the next element is NULL then it means we are at the end of the list (wich has an odd index)
    else newNode->next = pair_filter(head->next->next); //We skip a element (next->next) to only take pair indexes

    return newNode;
}