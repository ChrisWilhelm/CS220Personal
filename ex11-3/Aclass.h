#ifndef _ACLASS_H
#define _ACLASS_H

#include <iostream>
#include <string>
#include <sstream>
using std::string;
//using std::to_string();
class A { // base class
  
private: 
  int a;

protected:
  double d;
  int getA() const{ return a; }

public: 
  A(int val = 0, double num = 0): a(val), d(num) { };
  void seta(int val) { a = val; };
  void setd(double dval) { d = dval; } ;
  virtual int fun() const = 0;
  virtual string toString() const {
    string temp;
    int size = sizeof(A);
    temp = "Aclass: a = " + std::to_string(a) + ", d = " + std::to_string(d) + ", size = " + std::to_string(size);
    return temp;
  }
};

#endif
