#include <stdlib.h>

typedef struct node{
  struct node* next;
  int value;
} node_t;

typedef struct queue{
  struct node* tail;
  int size;
} queue_t  ;

/*
* Add @val value at the head of the @q queue
*
* @val     : the value to enqueue
* @q     : the queue
*
* @return 0 if no error, -1 otherwise
*
* pre : The queue q will always be valid, you don't need to handle the NULL case.
*/
int enqueue(queue_t* q, int val){
    if (q == NULL) return -1;
    node_t* newTail = (node_t *) malloc(sizeof(node_t));
    if (newTail == NULL) return -1;
    newTail -> value = val;
    if (q -> tail == NULL) {
        q -> tail = newTail;
    } else {
        newTail -> next = q -> tail -> next;
    }
    q -> tail -> next = newTail;
    q -> size++;
    return 0;
}

/*
* Remove the node at the tail of the @q queue and return the value of this node
* @q         : the queue
* @return     : the value at the tail
*
* pre         : The given queue will always be valid, you do not need to handle the NULL case.
*/
int dequeue(queue_t* q){
    int value;
    if (q -> size > 1) {
        node_t *n = q -> tail;
        for (int i = 1; i < q -> size; i++) {
            n = n-> next;
        }
        n -> next = n -> next -> next;
        free(q -> tail);
        q -> tail = n;
    } else {
        value = q -> tail -> value;
        free(q -> tail);
        q -> size--;
        q -> tail = NULL;
    }
    return value;
}