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
    node* newNode = malloc(sizeof(*newNode));
    assert(myQueue != NULL && newNode != NULL);
    newNode->val = data;
    newNode->next = NULL;
    
    if(myQueue->first == NULL)
    {
        myQueue->first = newNode;
        (myQueue->size)++;
        return;
    }

    node* lastNode = findLastNode(myQueue);
    lastNode->next = newNode;
    (myQueue->size)++;
}

int dequeue(queue* myQueue)
{
    assert(myQueue != NULL);

    if(myQueue->first != NULL)
    {
        node* temp = myQueue->first;
        myQueue->first = temp->next;
        (myQueue->size)--;
        free(temp);
        return 1;
    }

    return 0;
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

    while(myQueue->first != NULL)
        dequeue(myQueue);
}