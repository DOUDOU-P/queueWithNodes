#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "file.h"

void initialize(queue* myQueue)
{
    assert(myQueue != NULL);
    myQueue->first = NULL;
    myQueue->size = 0;
}
node* findLastNode(queue* myQueue)
{
    node* actual = myQueue->first;
    while(actual->next != NULL)
        actual = actual->next;

    return actual;
}
void enqueue(queue* myQueue, const int data)
{
    node* new = malloc(sizeof(*new));
    assert(myQueue != NULL && new != NULL);
    new->val = data;
    new->next = NULL;
    
    if(myQueue->first == NULL)
    {
        myQueue->first = new;
        (myQueue->size)++;
        return;
    }

    node* lastNode = findLastNode(myQueue);
    lastNode->next = new;
    (myQueue->size)++;
}

int dequeue(queue* myQueue)
{
    assert(myQueue != NULL);

    int dValue = EOF;
    if(myQueue->first != NULL)
    {
        node* temp = myQueue->first;
        dValue = temp->val;
        myQueue->first = temp->next;
        (myQueue->size)--;
        free(temp);
    }

    return dValue;
}

void displayQueue(queue* myQueue)
{
    assert(myQueue != NULL);
    node* actual = myQueue->first;

    while(actual != NULL)
    {
       printf("%d -> ", actual->val);
       actual = actual->next;
    }

    printf("NULL\n");
}

size_t getSize(queue* myQueue)
{
    assert(myQueue != NULL);
    return myQueue->size;
}

void clear(queue* myQueue)
{
    assert(myQueue != NULL);

    if(myQueue->first != NULL)
    {
        dequeue(myQueue);
        clear(myQueue);
    }
}