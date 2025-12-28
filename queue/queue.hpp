#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "../LinkedList/LinkedList/LinkedList.hpp"
#include <stdexcept>

template <typename T>
class Queue{
    private:
    LinkedList<T> l;
    public:
    void push(T val);
    T pop();
    T front();
    void display();
    bool isEmpty();
};
template <typename T>
void Queue<T>::push(T val){
    l.add(val);
}
template <typename T>
T Queue<T>::pop(){
    if(l.isEmpty()) throw std::out_of_range("Queue is empty: Cannot peek front");
    T val=l[0];
    l.pop_front();
    return val;
}

template <typename T>
T Queue<T>::front(){
    if(l.isEmpty())throw std::out_of_range("Queue is empty: Cannot peek front");
   return l[0];
}

template <typename T>
bool Queue<T>::isEmpty(){
    return l.isEmpty();
}
template <typename T>
void Queue<T>::display(){
    l.display();
}
#endif