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
    if (head == NULL)
        return NULL;
    struct node *newHead = (struct node *)memcpy((struct node *)malloc(sizeof(struct node)), head, sizeof(struct node));
    if (newHead == NULL)
        return NULL;
    struct node *tail = newHead;

    head = head->next;
    if (head == NULL)
        return newHead;
    head = head->next;

    while (head != NULL)
    {
        tail->next = (struct node *)memcpy((struct node *)malloc(sizeof(struct node)), head, sizeof(struct node));
        tail = tail->next;

        head = head->next;
        if (head == NULL)
            return newHead;
        head = head->next;
    }
    tail -> next = NULL;
    return newHead;
}