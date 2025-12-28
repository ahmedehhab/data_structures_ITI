#include <iostream>
#include "./binarySearch/binarySearch.hpp"
#include "../LinkedList/LinkedList/LinkedList.hpp"
using namespace std;
 int main(){
    LinkedList<int> l;
    for(int i=1;i<=10;i++) l.add(i);
    
    cout<<binarySearch(l,100)<<'\n';

    return 0;
 }