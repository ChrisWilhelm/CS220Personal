#ifndef _BCLASS_H
#define _BCLASS_H

#include <iostream>
#include <string>
#include "Aclass.h"
using std::string;
class B : public A {

private:
  int b;

public:
  B(int val = 0): b(val) { };  // automatically sets a & d to 0 w/ A()
  B(int bval, int aval, double dval): A(aval, dval), b(bval) {
     d = 17; 
  };
  void setb(int val) { b = val; };
  string toString() const override {
    int aVal = getA();
    //char bVal = b;
    //char dVal = d;
    int size = sizeof(B);
    string ret = "Bclass: a = " + std::to_string(aVal) + ", b = " + std::to_string(b) + ", d = " + std::to_string(d) + ", size = " + std::to_string(size);
    return ret;
  }
  virtual int fun() const override {
    int aVal = getA();
    return d*aVal*b;
  }
};


#endif
