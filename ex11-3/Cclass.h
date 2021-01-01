#ifndef _CCLASS_H
#define _CCLASS_H

#include <iostream>
#include <string>
#include "Aclass.h"
using std::string;
class C : public A {

private:
  int e;

public:
  C(int val = 0): e(val) { };  // automatically sets a & d to 0 w/ A()
  C(int bval, int aval, double dval): A(aval, dval), e(bval) {
     d = 17; 
  };
  void sete(int val) { e = val; };
  string toString() const override {
    int aVal = getA();
    //char bVal = b;
    //char dVal = d;
    int size = sizeof(C);
    string ret = "Bclass: a = " + std::to_string(aVal) + ", e = " + std::to_string(e) + ", d = " + std::to_string(d) + ", size = " + std::to_string(size);
    return ret;
  }
  virtual int fun() const override {
    int aVal = getA();
    return d*aVal*e;
  }
};


#endif
