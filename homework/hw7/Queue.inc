//ChrisWilhelm cwilhel8
#include "Queue.h"
#include <ostream>
template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>::Queue() {
  _head = nullptr; //sets head to nullptr
}

template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>::Queue(const DataType& ch) {
  _Node* n = new _Node({ch, nullptr}); //creates a new _Node and sets head to point to it
  _head = n;
}

template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>::Queue(const Queue& rhs) {
  if(rhs._head == nullptr) { //chekcs if the Queue to be copied is null
    return;
  }
  _Node* orig = rhs._head;
  _head = new _Node({orig->data, orig->next}); //creates a new head for the copy
  _Node* curr = _head;
  orig = orig->next;
  while(orig != nullptr) { //loops through the original and creates a copy
    curr->next = new _Node;
    curr = curr->next;
    curr->data = orig->data;
    curr->next = nullptr;
    orig = orig->next;
  }
}

template < typename DataType, bool useDataAsPriority >
void Queue<DataType, useDataAsPriority>::operator=(const Queue& rhs){
  if(rhs._head == nullptr) { //checks if the right is null
    return;
  }
  _Node* orig = rhs._head;
  if(_head == nullptr) { //checks if the head to be assigned is null
    _Node* n = new _Node({orig->data, nullptr}); //if it is, allocates memory for it
    _head = n;
  }
  _Node* curr = _head;
  curr->data = orig->data;
  curr->next = nullptr;
  orig = orig->next;
  while(orig != nullptr) { //loops through and assigns data
    curr->next = new _Node;
    curr = curr->next;
    curr->data = orig->data;
    curr->next = nullptr;
    orig = orig->next;
  }
}
template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>::~Queue<DataType, useDataAsPriority>() {
  while(_head != nullptr) { //loops through and deletes each node from the beginning
    _Node* temp = _head->next;
    delete _head;
    _head = temp;
  }
}

template < typename DataType, bool useDataAsPriority >
void Queue<DataType, useDataAsPriority>::Enqueue(const DataType& ch) {
  if(_head == nullptr) { //chekcs if the head is null
    _Node* temp = new _Node;
    temp->data = ch;
    temp->next = nullptr;
    _head = temp; //if it is, allocates memory for it
    return;
  }
  _Node* curr = _head;
  //checks if it is sorted and if the curr data is supposed to be after the new data
  if(useDataAsPriority == true && curr->data > ch) { 
      _Node* dummy = new _Node; //if it is, shifts current down one and adds the new data
      dummy->data = curr->data;
      dummy->next = curr->next;
      curr->data = ch;
      curr->next = dummy;
      return;
  }
  while(curr->next != nullptr) { //loops through it, and if it is sorted and should be placed in position, places it
    if(useDataAsPriority == true && curr->data > ch) {
      _Node* dummy = new _Node;
      dummy->data = curr->data;
      dummy->next = curr->next;
      curr->data = ch;
      curr->next = dummy;
      return;
    }
    curr = curr->next;
  }
  _Node* temp = new _Node; //adds to the end if it is unsort/should be the last of the sorted
  temp->data = ch;
  temp->next = nullptr;
  curr->next = temp;
}

template < typename DataType, bool useDataAsPriority >
DataType Queue<DataType, useDataAsPriority>::Dequeue() {
  if(_head == nullptr) { //checks that head it not null and throws exception if it is
    throw std::runtime_error("Nothing to Dequeue");
  }
  DataType var = _head->data; //removes first data and returns that a variable of it
  _Node* temp = _head->next;
  delete _head;
  _head = temp;
  return var;
}

template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>& Queue<DataType, useDataAsPriority>::operator<<(const DataType& ch) {
  this->Enqueue(ch); //adds data through Enqueue
  return *this;
}

template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority>& Queue<DataType, useDataAsPriority>::operator>>(DataType& ch) {
  ch = this->Dequeue(); //removes data through Dequeue
  return *this;
}

template < typename DataType, bool useDataAsPriority >
bool Queue<DataType, useDataAsPriority>::operator==(const Queue &rhs) const{
  _Node* lhs = _head;
  _Node* check = rhs._head;
  while(lhs != nullptr || check != nullptr) {
    if(lhs->data != check->data) {
      return false;
    }
    lhs = lhs->next;
    check = check->next;
  }
  if(lhs != nullptr && check == nullptr) {
    return false;
  }
  if(lhs == nullptr && check != nullptr) {
    return false;
  }
  return true;
}

template < typename DataType, bool useDataAsPriority >
Queue<DataType, useDataAsPriority> Queue<DataType, useDataAsPriority>::operator+(const Queue& rhs) const {
  _Node* curr = _head;
  _Node* currRhs = rhs._head;
  if(useDataAsPriority == true) { //concatenation for if it is a sorted queue
  //for priority organization
    if(currRhs == nullptr) { //checms if the to be added is null
      return *this;
    }
    while(currRhs != nullptr) { //loops through the to be added queue and compares it to the current data
      if(curr == nullptr) {
        _Node* add = new _Node;
	add->data = currRhs->data;
	add->next = nullptr;
	curr = add;
	curr = curr->next;
	currRhs = currRhs->next;
      }
      if(curr->data > currRhs->data) {
        _Node* dummy = new _Node;
	dummy->data  = curr->data;
	dummy->next = curr->next;
	curr->data = currRhs->data;
	curr->next = dummy;
	curr=curr->next;
	currRhs = currRhs->next;
      }
      else {
        curr = curr->next;
      }
    }
  }
  //non priority
  else { //adds to the end if not sorted
    if(curr != nullptr) {
      while(curr->next != nullptr) {
        curr = curr->next;
      }
    }
    while(currRhs != nullptr) {
      _Node* add = new _Node;
      add->data = currRhs->data;
      add->next = nullptr;
      curr->next = add;
      curr = curr->next;
      currRhs = currRhs->next;
    }
  }  
  return *this;
}
