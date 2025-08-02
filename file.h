#ifndef FILE_H_INCLUDED
    #define FILE_H_INCLUDED

    typedef struct node node;
    struct node
    {
        int val;
        node* next;
    };

    typedef struct queue queue;
    struct queue
    {
       node* first;
       size_t size;
    };

    void initialize(queue* myQueue);
    node* findLastNode(queue*);
    void enqueue(queue*, const int);
    int dequeue(queue*);
    void displayQueue(queue*);
    size_t getSize(queue*);
    void clear(queue*);

#endif