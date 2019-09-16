#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
using namespace std;
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:

        void imprimir() {
            if (!empty()) {
                auto temp = this->head;
                while (temp != nullptr) {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            } else
                throw exception();
        }
        ForwardList() : List<T>() {}

        T front()
        {
            if(!empty())
                return this->head->data;
            else
                throw exception();
        }

        T back()
        {
            if(!empty())
                return this->tail->data;
            else
                throw exception();
        }

        void push_front(T value)
        {
            auto temp=new Node<T>;
            temp->data=value;
            // Es mejor usar punteros a el valor nodes
            if(empty())
            {
               this->head=temp;
               this->tail=temp;
               temp->next= nullptr;
            }
            else
                {
                temp->next=this->head;
                this->head=temp;
            }

            this->nodes++;
        }

        void push_back(T value)
        {
            auto temp=new Node<T>;
            temp->data=value;
            if(empty())
            {
                this->head=temp;
                this->tail=temp;
                temp->next= nullptr;
            }
            else
            {
                temp->next= nullptr;
                this->tail->next=temp;
                this->tail=temp;
            }

            this->nodes++;
        }

        void pop_front()
        {
            if(!empty())
            {
                auto temp = this->head;
                if(size()>1)
                {

                    this->head = this->head->next;
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
                    auto temp2 = this->head;
                    for (int i = 0; i < size() - 2; i++)
                    {
                        temp2 = temp2->next;
                    }
                    temp2->next= nullptr;
                    this->tail=temp2;
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
            // Y si es negativo?
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
            // Esto puede ser return this->nodes == 0; o return !this->head;
            if(this->nodes == 0){
                return true;
            }
            else {
                return false;
            }
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            auto temp = this->head;
            // Y si la lista está vacía? Esto dará un error; 
            // Es mejor while (temp) { ... }
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

        void swap(int a,int b){
            auto aux1=this->head;
            auto aux2=this->head;

            for(int i=0;i<a-1;i++)
            {
                aux1=aux1->next;
            }
            for(int i=0;i<b-1;i++)
            {
                aux2=aux2->next;
            }
            aux1->next = aux2;
        }
    
        void reverse() {
            // Así no funciona
            for(int i=size();i>1;i--){
                swap(i, i-1);
            }
            auto temp = this->head;
            this->head =this->tail;
            this->tail = temp;
            this->tail->next = nullptr;

        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // Esto puede ser una línea
             auto it = ForwardIterator<T>(this->head);
             return it;
        }

	    ForwardIterator<T> end() {
            // Esto puede ser en una línea
            auto it = ForwardIterator<T>(nullptr);
            return it;
        }

        void merge(ForwardList<T> list) {
            for(int i = 0; i < list.size();i++)
            {
                this->push_back(list[i]);
            }
        }
};

#endif