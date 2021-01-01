#include <stdexcept>
#include <exception>
#include <iostream>
#include "stack.h"

using std::istream;  using std::ostream;


//UNCOMMENT AND FILL IN DURING PART 2

double Stack::pop() {
  return data[size - 1];
}

double Stack::top() const {
  if(size == 0) {
    throw std::out_of_range("Stack Underflow");
  }
  else {
    return data[size - 1];
  }
}

void Stack::push(double d) {
  if(size == cap) {
    throw std::out_of_range("Stack overflow");
  }
  else {
    data[size] = d;
    size++;
  }
}

*/



/****** UNCOMMENT AND FILL IN DURING PART 3


std::ostream& operator<<(std::ostream& os, const Stack& s) {

}

std::istream& operator>>(std::istream& is, Stack& s) {

}


*/
