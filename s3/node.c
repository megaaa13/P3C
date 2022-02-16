#include <unistd.h>
#include <stdlib.h>

/**
 * Structure node
 *
 * @next: pointer to the next node in the list, NULL if last node_t
 * @value: value stored in the node
 */
typedef struct node
{
    struct node *next;
    int value;
} node_t;

/**
 * Structure list
 *
 * @first: first node of the list, NULL if list is empty
 * @size: number of nodes in the list
 */
typedef struct list
{
    struct node *first;
    int size;
} list_t;

node_t *init_node(int value)
{
    node_t *result = (node_t *)malloc(sizeof(node_t));
    if (result == NULL)
        return NULL;
    result->next = NULL;
    result->value = value;
    return result;
}

int add_node(list_t *list, int value)
{
    node_t *node = init_node(value);
    if (list == NULL)
        return 1;
    if (node == NULL)
        return 1;
    if (list->first == NULL)
    {
        list->first = node;
    }
    else
    {
        node->next = list->first;
        list->first = node;
    }
    list->size++;
    return 0;
}