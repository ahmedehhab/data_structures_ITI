#include <iostream>
using namespace std;
#include "../../LinkedList/LinkedList/LinkedList.hpp"
#include "./InsertionSort.hpp"
int main(){
  LinkedList<int> l;
for(int i=10;~i;i--)l.add(i);
insertionSort(l);
l.display();
    return  0;
}