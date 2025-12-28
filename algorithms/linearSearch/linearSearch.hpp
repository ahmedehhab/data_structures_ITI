#ifndef LINEAR_SEARCH_HPP
#define INEAR_SEARCH_HPP
#include "../../LinkedList/LinkedList/LinkedList.hpp"

template <typename T>
int linearSearch(LinkedList<T> &list,T target){
    int index =0;
    Node<T>* temp=list.getHead();
    while(temp){
        if(temp->val ==target) return index;
        index++;
        temp=temp->next;
    }
    return -1;
}
#endif