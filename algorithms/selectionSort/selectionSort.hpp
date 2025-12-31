#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP
#include "../../LinkedList/LinkedList/LinkedList.hpp"

template <typename T>
 void selectionSort(LinkedList<T> &list){
    Node<T> * curr=list.getHead(); 
        while(curr){
            Node<T> * minNode =curr;
            Node<T>* temp= curr->next;
            while(temp){
                if(temp->val<minNode->val){
                    minNode=temp;
                }
                temp=temp->next;

            }
            swap(curr->val,minNode->val);
            curr=curr->next;
        }
 }

#endif