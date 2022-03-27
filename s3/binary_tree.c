#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;  // to smaller values
    struct node *right; // to larger values
} node_t;

typedef struct bt
{
    struct node *root;
} bt_t;

int contains(bt_t *tree, int value)
{
    if (tree == NULL || tree->root == NULL)
        return 0;
    if (tree->root->value == value)
        return 1;
    if (tree->root->value > value && contains(&((bt_t){tree->root->left}), value))
        return 1;
    if (contains(&((bt_t){tree->root->right}), value))
        return 1;
    return 0;
}