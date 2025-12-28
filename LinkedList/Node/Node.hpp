#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node{
public:
    T val;
    Node<T> *next;
    Node<T> *prev;
    Node(T val);
};
template <typename T>
Node<T> ::Node(T val){
        this->val=val;
        next=nullptr;
        prev=nullptr;
    };

#endif 