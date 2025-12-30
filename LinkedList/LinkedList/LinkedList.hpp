#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP
#include <iostream>
#include <stdexcept>
#include "../Node/Node.hpp"
using namespace std;
template <typename T>
class LinkedList{
    private:
  Node<T> * head;
  Node<T> * tail;
  int count;
  Node<T>* getNode(T val);
  public:
  LinkedList();
  void add(T val);
  void push_front(T val);
  void pop_front();
  void pop_back();
  void display();
  void insertAfter(T data,T afterData);
  void InsertBefore(T data, T beforeData);
  int getCount();
  void removeNode(T data);
  void removeAll(T data);
  void setHead(Node<T> * n);
  bool isEmpty();
  Node<T> * getHead();
  T operator[](int index);
  ~LinkedList();


};
template <typename T>
void  LinkedList<T>::setHead(Node<T> * n){
   head=n;
}

template<typename T>
Node<T>* LinkedList<T>::getHead(){
  return head;
}

template<typename T>
bool LinkedList<T>::isEmpty(){
  if(head==nullptr)return true;
  return false;
}

template <typename T>
void LinkedList<T>::pop_front() {
    if (isEmpty()) return;
    Node<T>* temp = head;

    if (head == tail) { 
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }

    delete temp;
    count--;
}

template <typename T>
void LinkedList<T>::pop_back() {
    if (isEmpty()) return;

    Node<T>* temp = tail;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    delete temp;
    count--;
}

template<typename T>
T LinkedList<T>::operator[](int index){
    if (index < 0 || index >= count)
        throw std::out_of_range("Index out of range");

    Node<T>* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->next;
    }
    return temp->val;
}

template <typename T>
void LinkedList<T>::push_front(T val){
  Node<T> * newNode=new Node<T>(val);
  if(head==nullptr){
    head=newNode;
    tail=newNode;
  }else{
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
  }
  count++;
}

template <typename T>
LinkedList<T>::LinkedList(){
    this->head=nullptr;
    this->tail=nullptr;
    this->count =0;
}

template <typename T>
void LinkedList<T>::add(T val){
    Node<T> * newNode=new Node<T>(val);
  if(head==nullptr){
     head=newNode;
     tail=newNode;
  }else{
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
  }
  count++;
}
 
  template <typename T>
void LinkedList<T>::display(){
    Node<T> *temp=head;
    while(temp!=nullptr){
        cout<<temp->val<<' ';
        temp=temp->next;
    }
}
template<typename T>
Node<T> * LinkedList<T>::getNode(T val){
    Node<T> * temp=head;
    while (temp!=nullptr)
    {
        if(temp->val==val)return temp;
      temp=temp->next;
    }
    return nullptr;

} 
template <typename T>
void LinkedList<T>::insertAfter(T data ,T afterData){
  Node<T> * afterNode=getNode(afterData);
  if(afterNode==nullptr)return;
   if(afterNode->next==nullptr){
    add(data);
   }else{
    Node<T>* newNode=new Node<T>(data);
    newNode->prev=afterNode;
    newNode->next=afterNode->next;
    afterNode->next=newNode;
    newNode->next->prev=newNode;
    count++;
   }
}

template<typename T>
int LinkedList<T>::getCount(){
    return count;
}
template<typename T>
void LinkedList<T>::InsertBefore(T data, T beforeData){
   Node<T> *beforeNode=getNode(beforeData);
   if(beforeNode==nullptr)return;
   Node<T>* newNode=new Node<T>(data);

    newNode->next = beforeNode;
    newNode->prev = beforeNode->prev;

    if(beforeNode->prev==nullptr){
    head = newNode;
   }else{
    beforeNode->prev->next = newNode;
   }
   beforeNode->prev = newNode;
 count++;
}

template <typename T>
void LinkedList<T>::removeNode(T data){
  Node<T> * targetNode=getNode(data);
  if(targetNode==nullptr)return ;
  
  if(targetNode==head &&targetNode==tail){
    head=nullptr; tail=nullptr;

  }else if(head==targetNode){
    head=targetNode->next;
    head->prev=nullptr;
  }else if(tail==targetNode){
    tail=targetNode->prev;
    tail->next=nullptr;
  }else{
    targetNode->prev->next=targetNode->next;
    targetNode->next->prev=targetNode->prev;
  }
  delete targetNode;
  count--;

}
// to improve make the removeNode take Node 
template <typename T>
void LinkedList<T>::removeAll(T data){
  // Node<T> * targetNode;
  // while((targetNode=getNode(data))!=nullptr){
  //   removeNode(data);
  // }

    Node<T>* temp=head;
    while(temp!=nullptr){
      Node<T>* nextNode=temp->next;
      if(temp->val==data){
        removeNode(data);
      }
      temp=nextNode;
    }
}

template<typename T>
LinkedList<T>::~LinkedList(){
  
  while(head!=nullptr){
    Node<T> * temp=head->next;
    delete head;
    head=temp;
  }
  tail=nullptr;
  count=0;
}
#endif