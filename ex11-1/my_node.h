//int_node.h

#ifndef MY_NODE_H
#define MY_NODE_H

template< typename T >
class my_node {

 private:

  T         data;  //the payload stored in this node
  my_node* next;  //the pointer to node after this one

 public:

  //constructors
  my_node(T value): data(value), next(nullptr) { }
  my_node(T value, my_node* ptr): data(value), next(ptr) { }

  //getters
  T get_data() const         { return data; }
  my_node* get_next() const   { return next; }

  //setters
  void set_data(T value)     { data = value; }
  void set_next(my_node* ptr) { next = ptr; }

};

#endif
