#ifndef NOEUD_HPP_INCLUDED
    #define NOEUD_HPP_INCLUDED

    template<typename unType>
    class node
    {
        private:
            unType value;
            node<unType>* next;
        
        public:
            node(unType v) : value(v), next(nullptr) {};
            node(unType v, node<unType>* n) : value(v), next(n) {};
            unType getValue()
            {
                return this->value;
            }
            node<unType>* getNext()
            {
                return this->next;
            }
            void setNext(node<unType>* newLastNode)
            {
                next = newLastNode;
            }
    };

#endif