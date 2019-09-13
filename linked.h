#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"
using namespace std;
template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        void imprimir() {
            if (!empty()) {
                auto aux = this->head;
                while (aux != nullptr) {
                    cout << aux->data << " ";
                    aux = aux->next;
                }
            }
            else
                throw exception();
        }

        T front() {
            if(this->head!= nullptr)
                return this->head->data;
            else
                throw exception();
        }

        T back() {

            if(this->tail!=nullptr)
                return this->tail->data;
            else
                throw exception();
        }

        void push_front(T value) {
            auto temp=new Node<T>;
            temp->data=value;
            if(empty())
            {
                this->head=temp;
                this->tail=temp;
                temp->next= nullptr;
                temp->prev =nullptr;
            }
            else{
                this->head->prev=temp;
                temp->prev = nullptr;
                temp->next=this->head;
                this->head=temp;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto temp=new Node<T>;
            temp->data=value;
            if(empty())
            {
                this->head=temp;
                this->tail=temp;
                temp->next= nullptr;
                temp->prev = nullptr;
            }
            else{
                temp->prev=this->tail;
                temp->next = nullptr;
                this->tail->next=temp;
                this->tail=temp;
            }
            this->nodes++;
        }

        void pop_front() {
            if(!empty())
            {
                auto temp = this->head;
                if(size()>1)
                {

                    this->head = this->head->next;
                    this->head->prev = nullptr;
                    delete temp;
                }
                else
                {
                    this->head= nullptr;
                    this->tail= nullptr;
                }

                this->nodes--;
            }
            else
                throw exception();
        }

        void pop_back() {
            if(empty())
            {
                throw exception();
            }
            else{
                auto temp = this->tail;
                if (size() > 2)
                {
                    this->tail = this->tail->prev;
                    this->tail->next = nullptr;
                    delete temp;

                }
                else if(size()==2)
                {
                    this->tail=this->head;
                    this->tail->next= nullptr;
                    delete temp;
                }
                else if (size() == 1)
                {
                    this->head= nullptr;
                    this->tail= nullptr;
                    delete temp;
                }
            }

            this->nodes--;
        }

        T operator[](int index) {
            if(index < size()) {
                auto temp = this->head;
                for (int i = 0; i < index; i++) {
                    temp = temp->next;
                }
                return temp->data;
            }
            else throw exception();
        }

        bool empty() {
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
            while(temp->next!=nullptr)
            {
                temp = temp->next;
                pop_front();
            }
            pop_front();
        }

        void sort() {
            bool not_ordered = true;
            while (not_ordered) {
                not_ordered = false;
                auto temp = this->head;
                while(temp->next!=nullptr){

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

        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            auto it = BidirectionalIterator<T>(this->head);
            return it;
        }

	    BidirectionalIterator<T> end() {
             auto it = BidirectionalIterator<T>(nullptr);
             return it;
        }

        void merge(LinkedList<T> list) {
            for(int i = 0; i < list.size();i++)
            {
                this->push_back(list[i]);
            }
        }
};

#endif