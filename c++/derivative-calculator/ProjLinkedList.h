#ifndef PROJLINKEDLIST_H
#define PROJLINKEDLIST_H

#include <iostream>
#include "ProjNode.h"

template<class T> 
class ProjLinkedList
{
  public:
  ProjNode<T>* head;
  ProjLinkedList() {
    head = NULL;
  }
  ~ProjLinkedList() {
    ProjNode<T> *next;
    while (head) {
      next = head->next;
      delete head;
      head = next;
    }
  }
  void add(T data) {
    ProjNode<T> *temp = new ProjNode<T>();
    temp->data = data;
    
    if(head == NULL) {
      head = temp;
    }
    else {
      temp->next = head;
      head = temp;
    }
  }
  T getAt(int num) {
    ProjNode<T> *curNode = head;
    int i = 0;
    while(i != num) {
        curNode = curNode->next;
        i++;
    }
    return curNode->data;
  }
};

#endif
