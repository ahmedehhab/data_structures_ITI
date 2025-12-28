#include <iostream>
#include "./binarySearch/binarySearch.hpp"
#include "../LinkedList/LinkedList/LinkedList.hpp"
#include "./bubbleSort/bubbleSort.hpp"
#include "./linearSearch/linearSearch.hpp"
using namespace std;
 int main(){
    LinkedList<int> l;
    // for(int i=1;i<=10;i++) l.add(i);
     l.add(5);
     l.add(1);
     l.add(100);
     l.add(2);
     cout<<linearSearch(l,2)<<"\n";
       bubbleSort(l);
    cout<<binarySearch(l,2)<<'\n';


    return 0;
 }