#ifndef LIST_H
#define LIST_H


typedef struct node_ {
  char data;
  struct node_ * next;
} Node; // Node is a linked list node that holds char data



Node * create_node(char); // put char into a newly created node
void print(const Node *); // output the list iteratively

int length(Node * n);
void add_after(Node * n, char ch);
void reverse_print(Node * n);
#endif

