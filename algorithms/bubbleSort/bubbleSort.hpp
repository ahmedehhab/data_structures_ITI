#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP
#include "../../LinkedList/LinkedList/LinkedList.hpp"
using namespace std;
template<typename T>
void bubbleSort(LinkedList<T> &list ){
    if(list.isEmpty())return;
    bool swapped;
    do{
        swapped=false;
        Node<T> * temp=list.getHead();
        while(temp&& temp->next){
            if(temp->val>temp->next->val){
                 swap(temp->val,temp->next->val);
                 swapped=true;
            }
            temp=temp->next;
        }

    }while (swapped);
    
}
#endif