#ifndef LIST_H
#define LIST_H

#include "node.h"
using namespace std;
template <typename T>
class List {
//    protected:
public:
        Node<T>* head;
        Node<T>* tail;
        int nodes;

//    public:
        List() : head(nullptr), tail(nullptr), nodes(0) {};

        virtual T front() = 0;
        virtual T back() = 0;
        virtual void push_front(T) = 0;
        virtual void push_back(T) = 0;
        virtual void pop_front() = 0;
        virtual void pop_back() = 0;
        virtual T operator[](int) = 0;
        virtual bool empty() = 0;
        virtual int size() = 0;
        virtual void clear() = 0;
        virtual void sort() = 0;
        virtual void reverse() = 0;
        virtual string name() = 0;

        ~List() {
                for(int i = 0; i < this->nodes; i++)
                {
                    auto temp = this->head;
                    this->head = this->head->next;
                    delete temp;
                }
                delete head;
        }
};

#endif