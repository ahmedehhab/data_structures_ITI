#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP
#include "../../LinkedList/LinkedList/LinkedList.hpp"
template <typename T>
void insertionSort(LinkedList<T> &list){

    Node<T>* curr=list.getHead()->next;
    while (curr!=nullptr)
    {  
        Node<T>*last =curr->prev;
        Node<T>*nextNode=curr->next;
        // using swap 
        // while(last!=nullptr){
        //     if(last->val >temp->val){
        //         swap(temp->val,last->val);
        //         temp=last;
        //     }
        //     last=last->prev;
        // }
        // curr=curr->next;

       if(last&& last->val>curr->val){
        while (last&&last->val>curr->val){
        last=last->prev;
       }
    
       curr->prev->next=curr->next;
       if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }

       if(last==nullptr){
        curr->prev=nullptr;
        curr->next=list.getHead();
        list.getHead()->prev = curr;
        list.setHead(curr);

       }else{
        curr->next = last->next;
                curr->prev = last;
                if (last->next != nullptr) {
                    last->next->prev = curr;
                }
                last->next = curr;

       }

       }
       
  
       curr=nextNode;
    }
    
}

#endif