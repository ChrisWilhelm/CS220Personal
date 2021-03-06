#include "complex.h"
#include <iostream>
// You will add function definitons to this file
// See TODOs in complex.h

//// things to be added for part 2 ////
// TODO: operator<<
std::ostream& operator<<(std::ostream& os, const Complex& c) {
  os << c.getRel() << " + " << c.getImg() << "i";
  return os;
}

//// things to be added for part 3 ////
// TODO: copy constructor
Complex::Complex(const Complex& rhs) {
  rel = rhs.rel;
  img = rhs.img;
}

// TODO: assignment operator
void Complex::operator=(const Complex& rhs) {
  rel = rhs.rel;
  img = rhs.img;
}

// TODO: add operator
Complex Complex::operator+(const Complex& rhs) {
  Complex temp =  Complex();
  temp.rel = rhs.rel + rel;
  temp.img = rhs.img + img;
  return temp;
}
// TODO: minus operator
Complex Complex::operator-(const Complex& rhs) {
  Complex temp =  Complex();
  temp.rel = rel - rhs.rel;
  temp.img = img - rhs.img;
  return temp;
}
// TODO: times operator
Complex Complex::operator*(const Complex& rhs) {
  Complex temp =  Complex();
  temp.rel = rel*rhs.rel - img*rhs.img;
  temp.img = rel*rhs.img + img*rhs.rel;
  return temp;
}
// TODO: times operator (float)
Complex Complex::operator*(const float& rhs) {
  Complex temp =  Complex();
  temp.rel = rhs*rel;
  temp.img = rhs*img;
  return temp;
}
// TODO: divide operator
Complex Complex::operator/(const Complex& rhs) {
  Complex temp2 =  Complex();
  Complex temp = Complex(rhs.rel, -rhs.img);
  temp2.rel = (rel*rhs.rel - img*rhs.img)/(temp.rel*temp.rel + temp.img*temp.img);
  temp2.img = (rel*rhs.img + img*rhs.rel)/(temp.rel*temp.rel + temp.img*temp.img);
  return temp2;
}

//// things to be added for part 4 ////
// TODO: times operator for float times complex
Complex operator*(float lhs, const Complex& rhs) {
  float temp  = lhs;
  Complex c = Complex();
  c.rel = rhs.rel * temp;
  c.img = rhs.img * temp;
  return c;
}

