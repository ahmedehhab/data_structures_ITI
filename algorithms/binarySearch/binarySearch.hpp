#ifndef BINARY_SEARCH_HPP
#define BINARY_SEARCH_HPP
#include "../../LinkedList/LinkedList/LinkedList.hpp"
template <typename T>
int binarySearch(LinkedList<T> &list,T target){
    int l=0 ,r=list.getCount()-1;
    while(r>=l){
        int mid= (l+r)/2;
        T val= list[mid];
        if(val==target) return mid;
        if(val>target)r=mid-1;
        else l=mid+1;
    }
    return -1;
}
#endif