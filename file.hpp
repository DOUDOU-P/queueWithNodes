#ifndef FILE_HPP_INCLUDED
    #define FILE_HPP_INCLUDED

    #include<iostream>
    #include<fstream>
    #include "noeud.hpp"

    struct point
    {
        int x;
        int y;
    };

    template<typename unType>
    class queue
    {
        private:
            node<unType>* first;
            size_t size;
        
        public:
            queue(const queue&) = delete;
            queue& operator=(const queue&) = delete;

            queue()
            {
                first = nullptr;
                size = 0;
            }

            queue(queue&& other)
            {
                this->first = other.first;
                this->size = other.size;
                other.first = nullptr;
                other.size = 0;
            }

            queue& operator=(queue&& other)
            {
                clear();
                this->first = other.first;
                this->size = other.size;
                other.first = nullptr;
                other.size = 0;
                return *this;
            }
            ~queue()
            {
                clear();
            }

            bool isEmpty() const
            {
                return first == nullptr;
            }

            bool isFull() const
            {
                return false;
            }

            size_t getSize() const
            {
                return this->size;
            }

            void enqueue(unType data)
            {
                node<unType>* newNode = new node<unType>(data);
                if(isEmpty())
                {
                    first = newNode;
                    size++;
                    return;
                }

                node<unType>* cursor = first;
                while(cursor->getNext() != nullptr)
                    cursor = cursor->getNext();
                
                cursor->setNext(newNode);
                size++;
            }

            bool dequeue(unType& data)
            {   
                if(!isEmpty())
                {
                    data = first->getValue();
                    node<unType>* element = first;
                    first = first->getNext();
                    size--;
                    delete element;
                    return true;
                }

                return false;
            }

            void display() const
            {
                node<unType>* cursor = first;
                while(cursor != nullptr)
                {
                    std::cout<<cursor->getValue()<<" -> ";
                    cursor = cursor->getNext();
                }

                std::cout<<"NULL\n";
            }

            bool getTop(unType& data) const
            {
                if(!isEmpty())
                {
                    data = first->getValue();
                    return true;
                }
                return false;
            }

            void clear()
            {
                unType data;
                while(!isEmpty())
                    dequeue(data);
            }
    };

    std::istream& operator>>(std::istream& input, point& data)
    {
        input >> data.x >> data.y;
        return input;
    }

    std::ostream& operator<<(std::ostream& output, point data)
    {
        output <<"("<< data.x <<","<< data.y <<")"<<"";
        return output;
    }


#endif