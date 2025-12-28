#include "../LinkedList/LinkedList.hpp"
#include <iostream>
using namespace std;
int main(){
 LinkedList<int> l;
 l.add(10);
 l.add(11);
 l.add(10);
 l.add(12);
 l.add(10);l.add(10);l.add(10);l.add(10);l.add(10);
 l.insertAfter(15,1);l.add(10);
  l.InsertBefore(9,10);
  l.add(10);
  l.InsertBefore(8,12);
  l.add(10);
//   l.removeNode(12);
 cout<<l.getCount()<<'\n';
 l.display();
cout<<"\n";
 l.removeAll(10);
 l.display();

    return 0; 
}