#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char val;
    struct node *next;
} node_t;

int compare(char a, char b)
{
    return a - b;
}

int insert(node_t **head, char val, int (*cmp)(char, char))
{
    if (*head == NULL)
    {
        node_t *newHead = (node_t *)malloc(sizeof(node_t));
        if (!newHead)
            return -1;
        newHead->val = val;
        newHead->next = NULL;
        *head = newHead;
        return 0;
    }
    node_t *runner = *head;
    node_t *prev = *head;
    if ((*cmp)(runner->val, val) >= 0)
    {
        if (!(*cmp)(val, runner->val))
            return 0;
        node_t *newHead = (node_t *)malloc(sizeof(node_t));
        if (newHead == NULL)
            return -1;
        newHead->val = val;
        newHead->next = runner;
        *head = newHead;
        return 0;
    }
    runner = runner->next;
    while (runner != NULL)
    {
        if ((*cmp)(runner->val, val) > 0)
        {
            node_t *newHead = (node_t *)malloc(sizeof(node_t));
            if (!newHead)
                return -1;
            newHead->val = val;
            newHead->next = runner;
            prev->next = newHead;
            return 0;
        }
        else if (!(*cmp)(runner->val, val))
            return 0;
        else
        {
            prev = runner;
            runner = runner->next;
        }
    }
    node_t *newHead = (node_t *)malloc(sizeof(node_t));
    if (!newHead)
        return -1;
    prev->next = newHead;
    newHead->val = val;
    newHead->next = runner;
    return 0;
}
