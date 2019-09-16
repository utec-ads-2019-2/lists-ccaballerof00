#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current=other.current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            // Podría ser una línea
            if(this->current!=other.current)
                return true;
            else
                return false;
        }

        BidirectionalIterator<T> operator++() {
            // Controlar caso que no se pueda avanzar
            this->current=this->current->next;
            return *this;
        }

        BidirectionalIterator<T> operator--() {
            // Controlar caso que no se pueda retroceder
            this->current=this->current->prev;
            return *this;
        }

        T operator*() {
            // Si está vacía?
            return this->current->data;
        }
};

#endif