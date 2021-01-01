#ifndef MY_SET_H
#define MY_SET_H

#include <iostream>
#include "my_node.h"
//#include "my_set.inc"

/* Class to represent a mathematical set of ints (like std::set<int>,
   but we're writing this one ourselves).  Recall that set objects may
   never contain duplicate values, so we must avoid adding new items
   that are equal to existing items in the set.  To facilitate checking
   for duplicates, we store the items in a SORTED linked list of
   int_nodes. The sort is in ascending order by < on ints.
*/
template <typename T>
class my_set {

 private:

  my_node<T>* head;
  int       size;

 public:

  //constructor to create an empty list
  my_set(): head(nullptr), size(0) { }

  //copy constructor to make a "deep copy" of the set
  my_set(const my_set<T>& other);

  //destructor
  ~my_set();

  //report the current size of the set (i.e. number of elements in it)
  int get_size() const { return size; }
  
  //remove all existing items from set
  void clear();

  //insert the given item into the set, provided it's not a duplicate
  //return true if insertion successful, false otherwise
  bool add(T new_value);
 

  // alternative way to call add, returning this updated int_set
  my_set& operator+=(T new_value);


  // overload the assignment operator to make a deep copy and return
  // a reference to this updated int_set
  my_set& operator=(const my_set<T>& other);


  //output items in set, comma-and-space-separated within curly braces
  //E.g.  {1, 2, 3}  or {}
  template <typename U> friend std::ostream& operator<<(std::ostream& os, const my_set<U>& s);


};

#endif
