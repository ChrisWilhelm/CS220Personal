#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// put char into a newly created node
Node * create_node(char ch) {
  Node * node = (Node *) malloc(sizeof(Node));
  assert(node); //confirm malloc didn't fail

  node->data = ch;
  node->next = NULL;
  return node;
}

// output the list iteratively
void print(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

int length(Node * n) {
  int length = 0;
  while(n != NULL) {
    n = n->next;
    length++;
  }
  return length;
}

void add_after(Node * n, char ch) {
  Node * nnew = create_node(ch);
  nnew->next = n->next;
  n->next = nnew;
}

void reverse_print(Node * n) {
  int l = length(n);
  int templength = l - 1;
  for(int i = 1; i < l; i++) {
    Node * n2  = n;
    for(int j = 1; j <= templength; j++) {
      n2 = n2->next;
      if(j == templength) {
	templength--;
	printf("%c ", n2->data);
      }
    }
  }
  printf("%c ", n->data);
}
    
  

