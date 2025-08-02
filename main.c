#include<stdio.h>
#include "file.h"

int main(void)
{
    queue myQueue;
    initialize(&myQueue);

   for(int i = 0; i < 5; i++)
   {
        printf("On enfile %d\n", i);
        enqueue(&myQueue, i);
   }

   printf("Affichage de la pile: ");
   displayQueue(&myQueue);

   printf("On defile %d\n", dequeue(&myQueue));
   printf("On defile %d\n", dequeue(&myQueue));

   printf("Affichage de la pile: ");
   displayQueue(&myQueue);

   printf("Taille de la file: %ld\n", getSize(&myQueue));

   printf("Nettoyage de la file\n");

   clear(&myQueue);

   displayQueue(&myQueue);

   return 0;
}