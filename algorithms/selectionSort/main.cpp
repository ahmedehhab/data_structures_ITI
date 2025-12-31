#include <iostream>
#include "./selectionSort.hpp"
using namespace std;

int main(){
LinkedList<int> l;
for(int i=10;~i;i--)l.add(i);
selectionSort(l);
l.display();
    return 0;
}