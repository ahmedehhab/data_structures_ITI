#include <iostream>
#include "queue.hpp"
using namespace std;

int main(){
    Queue<int> q;
    q.push(10);
    cout<<q.front()<<'\n';
    cout<<q.pop()<<'\n';
    q.push(100);
    q.push(200);
    q.push(4000);
    q.display();
    return 0;
}
