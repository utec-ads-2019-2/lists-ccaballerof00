#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        void imprimir() {
            if (!empty()) {
                auto temp = this->head;
                while (temp->next != this->head) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << temp->data;
            } else
                throw exception();
        }

        T front() {
            // Y si está vacía?
            return this->head->data;
        }

        T back() {
            // Y si está vacía?
            return this->tail->data;
        }

        void push_front(T value) {
            auto temp = new Node<T>;
            temp->data = value;
            if(empty())
            {
                this->head = temp;
                this->tail = temp;
                this->head->next = this->tail;
                this->head->prev = this->tail;
                this->tail->next = this->head;
                this->tail->prev = this->head;
            }
            else
            {
                temp->next = this->head;
                this->head->prev = temp;
                temp->prev = this->tail;
                this->tail->next = temp;
                this->head = temp;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto temp = new Node<T>;
            temp->data = value;
            if(empty())
            {
                this->head = temp;
                this->tail = temp;
                this->head->next = this->tail;
                this->head->prev = this->tail;
                this->tail->next = this->head;
                this->tail->prev = this->head;
            } else
            {
                this->tail->next = temp;
                temp->prev = this->tail;
                temp->next = this->head;
                this->head->prev = temp;
                this->tail = temp;
            }
            this->nodes++;
        }

        void pop_front() {
            if(empty())
            {
                throw exception();
            }
            else
            {
                auto temp = this->head;
                if(size()==1)
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                }
                else {
                    this->head = this->head->next;
                    this->head->prev = this->tail;
                    this->tail->next = this->head;
                    delete temp;
                }
                this->nodes--;
            }
        }

        void pop_back() {
            // No es necesario, pero no está mal
            if(empty())
            {
                throw exception();
            }
            else
            {
                auto temp = this->tail;
                if(size()==1)
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete temp;
                }
                if(size()==2)
                {
                    this->tail = this->head;
                    delete temp;
                }
                if(size()>2)
                {
                    this->tail = this->tail->prev;
                    this->tail->next = this->head;
                    this->head->next = this->tail;
                    delete temp;
                }
                this->nodes--;
            }
        }

        T operator[](int index) {
                // Sería mejor sacar el módulo para no dar tantas iteraciones
                auto temp = this->head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp->data;
        }

        bool empty() {
            // Mismo caso que forward
            if(size()==0)
                return true;
            else
                return false;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            auto temp = this->head;
            while(temp->next!=this->head)
            {
                temp = temp->next;
                pop_front();
            }
            pop_back();
        }

        void sort() {
            bool not_ordered = true;
            while (not_ordered) {
                not_ordered = false;
                auto temp = this->head;
                while(temp->next!=this->head){

                    if (temp->data > temp->next->data) {
                        int t = temp->data;
                        temp->data = temp->next->data;
                        temp->next->data = t;
                        not_ordered=true;
                    }
                    temp = temp->next;
                }
            }
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // Mismo caso que forward
             auto it = BidirectionalIterator<T>(this->head);
             return it;
        }

	    BidirectionalIterator<T> end() {
             auto it = BidirectionalIterator<T>(this->tail->next);
             return it;
        }

        void merge(CircularLinkedList<T> list) {
            for(int i = 0; i < list.size();i++)
            {
                this->push_back(list[i]);
            }
        }
};

#endif