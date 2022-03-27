#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};

/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result)
{
    if (head == NULL || *head == NULL) return 1;
    struct node *oldHead = *head;
    strcpy(result, oldHead -> name);
    *head = oldHead -> next;
    free(oldHead -> name);
    free(oldHead);
    return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
    if (head == NULL || *head == NULL || value == NULL) return 1;
    struct node *newHead = (struct node *)malloc(sizeof(struct node));
    char *val = (char *) malloc(sizeof(char) * (strlen(value) + 1));
    if (val == NULL || newHead == NULL) return 1;
    strcpy(val, value);
    newHead -> name = val;
    newHead -> next = (*head);
    *head = newHead;
    return 0;
}