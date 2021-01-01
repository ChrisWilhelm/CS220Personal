#include "my_set.h"


//copy constructor to make a "deep copy" of the set
template <typename T>
my_set<T>::my_set(const my_set& orig){
  my_node<T>* org = orig.head;
  for(int i = 0; i < orig.get_size(); i++) {
    add(org->get_data());
    org = org->get_next();
  }
  size = orig.get_size();
}

//destructor
template <typename T>
my_set<T>::~my_set<T>(){
  my_node<T>* cur = head;
  for(int i = 0; i < size; i++) {
    my_node<T>* next = cur->get_next();
    delete cur;
    cur = next;
  }
  //delete cur;
}

//remove all existing items from set
template <typename T>
void my_set<T>::clear(){
  //deallocate all nodes in the list
  my_node<T> *cur = head;
  while (cur) {
	my_node<T>* temp = cur;
	cur = cur->get_next();
	delete temp;
  }
  //reset instance variables
  head = nullptr;
  size = 0;
}

//insert the given item into the set, provided it's not a duplicate
//return true if insertion successful, false otherwise
//RESTRICTION: use only < and == on the data within nodes (not <=, >, >=, !=)
template <typename T>
bool my_set<T>::add(T new_value) {

  //first, abort if new_value would be a duplicate when added to set
  my_node<T>* cur = head;
  while (cur) {
    if (cur->get_data() == new_value) {
      return false;
    }
    cur = cur->get_next();
  }

  //next, create new node to hold the new value
  my_node<T>* new_node = new my_node<T>(new_value);
  if (!new_node) {  //allocation failed!
	return false; 
  }

  if (!head) { //list is currently empty
	head = new_node;
	size++;
	return true;
  }
  if (new_value < head->get_data()) { //new_node is smallest
        new_node->set_next(head);
	head = new_node;
	size++;
	return true;
  }

  //new_node should go somewhere after 1st node, so let's locate
  //first node whose data larger than new_node's.  But we must
  //be careful not to fall off end of list!
  cur = head;
  //So we'll stop looping when either cur is pointing to last node
  //in the list, or cur has advanced as far into this list as it can,
  //while still pointing to a node with a value smaller than new one
  while (cur->get_next() && (cur->get_next()->get_data() < new_value)) {
    cur = cur->get_next();
  }
  new_node->set_next(cur->get_next());  //may be nullptr, but that's ok too
  cur->set_next(new_node);
  size++;
  return true;
}
 
//Overload the += operator using the add method
//return a reference to this int_set for consistency
template <typename T>
my_set<T>& my_set<T>::operator+=(T new_value) {
  my_node<T>* cur = this->head;
  for(int i = 0; i < this->size; i++) {
    cur->set_data(cur->get_data() + new_value);
    cur = cur->get_next();
  } 
  return *this;    //for consistency - assignment ops return the value assigned
}


// overload the assignment operator to make a deep copy and return
// a reference to this updated int_set
template <typename T>
my_set<T>& my_set<T>::operator=(const my_set<T>& other) {
  my_node<T>* org = other.head;
  for(int i = 0; i < other.get_size(); i++) {
    add(org->get_data());
    org = org->get_next();
  }
  size = other.get_size();
  return *this;
}


//output items in set, comma-and-space-separated within curly braces
//E.g.  {1, 2, 3}  or {}
//NOTE that the 'friend' keyword doesn't appear outside the class,
//and that we don't pre-pend the name of this method with int_set::,
//since it's not an actual member of the class
template <typename T>
std::ostream& operator<<(std::ostream& os, const my_set<T>& s){
  os << "{";
  if (s.get_size() == 0) {
    os << "}";
    //return os;
  }
  else {
    my_node<T>* cur = s.head;
    while(cur->get_next() != NULL) {
      os << cur->get_data() << ", ";
      cur = cur->get_next();
    }
    os << cur->get_data() << "}";
  }
  return os;
}
