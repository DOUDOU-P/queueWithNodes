#include<iostream>
#include<fstream>
#include "file.hpp"

int main()
{
    queue<point> myQueue;
    char c;
    point data;

    while(true)
    {
        std::cout<<"i = inserer donnee"<<"\n";
        std::cout<<"e = enlever donnee"<<"\n";
        std::cout<<"a = afficher file"<<"\n";
        std::cout<<"t = obtenir la taille de la file"<<"\n";
        std::cout<<"v = vider la file"<<"\n";
        std::cout<<"f = fin du processus"<<"\n";
        std::cout<<"Quelle operation souhaitez vous effectuer?: ";
        std::cin>>c;

        switch (c)
        {
        case 'i':
        case 'I':
            if(!myQueue.isFull())
            {
                std::cout<<"Entrez la donnee a inserer: ";
                std::cin>>data;
                myQueue.enqueue(data);
            }
            else
                std::cout<<"La file est pleine"<<"\n";
            break;
        
        case 'e':
        case 'E':
            if(!myQueue.isEmpty())
            {
                myQueue.dequeue(data);
                std::cout<<data<<" a ete enlevee de la file"<<"\n";
            }
            else
                std::cout<<"La file est vide"<<"\n";
            break;
        
        case 'a':
        case 'A':
            myQueue.display();
            break;
        
        case 't':
        case 'T':
            std::cout<<"Taille actuelle de la file: "<<myQueue.getSize()<<"\n";
            break;
        
        case 'v':
        case 'V':
            myQueue.clear();
            break;
        
        case 'f':
        case 'F':
            std::cout<<"Fin du processus"<<"\n";
            return 0;

        default:
            std::cout<<"Commande eronnee"<<"\n";
        }
    }
   
    return 0;
}