//Chris Wilhelm cwilhel8
#include "CQueue.h"
#include <ostream>

CQueue::CQueue() {
  _head = nullptr; //default constructor
}

CQueue::CQueue(const char& ch) { //constructor
  _Node* n = new _Node({ch, nullptr});
  _head = n;
}

CQueue::CQueue(const CQueue& rhs) { //copy constructor
  if(rhs._head == nullptr) {//checks if the queue to be copied is null
    return;
  }
  _Node* orig = rhs._head; 
  _head = new _Node({orig->data, orig->next}); //creates head for the copy
  _Node* curr = _head; //sets variable current equal to head
  orig = orig->next; //moves orig to next _Node
  while(orig != nullptr) { //while orig still has more _Node 's
    curr->next = new _Node; //allocates new memory for the copy
    curr = curr->next; //iterates over curr(ie the copy)
    curr->data = orig->data; //ititializes data in the copy
    curr->next = nullptr; //sets next to null(won't be null if it isn't the end
    orig = orig->next; //iterates over the original
  }
}

void CQueue::operator=(const CQueue& rhs){ //equal override
  if(rhs._head == nullptr) { //checks that the right Queue isn't null
    return;
  }
  _Node* orig = rhs._head; //pointer to the head
  if(_head == nullptr) { //checks if the current equals null, and assigns memory for head
    _Node* n = new _Node({orig->data, nullptr});
    _head = n;
  }
  _Node* curr = _head; //pointer to _head
  curr->data = orig->data; //first data initilialized
  curr->next = nullptr; //next is set to null
  orig = orig->next; //progresses in original(ie rhs)
  while(orig != nullptr) { //continues to copy data while original has it.
    curr->next = new _Node;
    curr = curr->next;
    curr->data = orig->data;
    curr->next = nullptr;
    orig = orig->next;
  }
}

CQueue::~CQueue() {//destructor
  _Node* temp;
  while(_head != nullptr) { //while the _head is not null
    temp = _head->next;
    delete _head; //deletes head and sets head to old next
    _head = temp;
  }
}

void CQueue::Enqueue(const char& ch) { //adds character to Queue
  _Node* temp = new _Node; //creates temporary node for the new data
  temp->data = ch; 
  temp->next = nullptr;
  if(_head == nullptr) {//checks if _head is null
    _head = temp;
    return;
  }
  _Node* curr = _head;
  while(curr->next != nullptr) { //loops through until gets to the end of curr
    curr = curr->next;
  }
  curr->next = temp; //adds new data
}

char CQueue::Dequeue() { //remove first in Queue
  if(_head == nullptr) { //checks if _head is null
    //throws exception if trying to remove a character from a queue without one
    throw std::runtime_error("Nothing to Dequeue"); 
  }
  char var = _head->data; //variable for return of letter removed
  _Node* temp = _head->next; 
  delete _head; //deletes head
  _head = temp; //reassigns _head to next data _Node
  return var;
}

CQueue& CQueue::operator<<(const char& ch) { //performs enqueue for << operator
  this->Enqueue(ch); //call to enqueue
  return *this; //returns reference to the Queue
}

CQueue& CQueue::operator>>(char& ch) { //performs Dequeue for  >> operator
  ch = this->Dequeue(); //sets refence variable equal to the one Dequeue'd
  return *this; //returns reference to the Queue
}

bool CQueue::operator==(const CQueue &rhs) const{ //comparison operator
  _Node* lhs = _head;
  _Node* check = rhs._head;
  while(lhs != nullptr || check != nullptr) { //continues while either are not null
    if(lhs->data != check->data) { //if data does not match returns false
      return false;
    }
    lhs = lhs->next;
    check = check->next;
  }
  if(lhs != nullptr && check == nullptr) { //if check if null and the other is not
    return false;
  }
  if(lhs == nullptr && check != nullptr) { //if lhs is null and check is not
    return false;
  }
  return true;
}

CQueue CQueue::operator+(const CQueue& rhs) const { //operator overload for +
  _Node* curr = _head;
  _Node* currRhs =  rhs._head;
  if(curr == nullptr) { //checks if _head is nullptr, if so, a
    _Node* n = new _Node; //allocates space for first data and initilializes
    curr = n;
    //currRhs = currRhs->next;
  }
  else { //loops through current until the end
    while(curr->next != nullptr) {
      curr = curr->next;
    }
  }
  while(currRhs != nullptr) { //adds rhs to the end of the curr
    _Node* add = new _Node;
    add->data = currRhs->data;
    add->next = nullptr;
    curr->next = add;
    curr = curr->next;
    currRhs = currRhs->next;
  } 
  return *this; //returns pointer to the head
}

std::ostream& operator<<(std::ostream& os, const CQueue& q) { //overloads the print operator
  CQueue::_Node* curr;
  for(curr = q._head; curr != NULL; curr = curr->next) { //loops through and adds arrow after each node
    os << curr->data << " -> ";
  }
  os << "NULL\n"; //adds null and a new line at the end
  return os; //returns the stream
}

