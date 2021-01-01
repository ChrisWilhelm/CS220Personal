#include "grade_list.h"
#include <cassert>

// You will add function definitions to this file.
// See TODOs in grade_list.h.

double GradeList::min() {
  assert(count > 0);   // no values otherwise
  double minval = grades[0];
  for (int i = 1; i < count; i++) {
    if (grades[i] < minval)
      minval = grades[i];
  }
  return minval;
}

//////////// things to be added for part 2  /////////////////

// TODO: write a constructor (in grade_list.cpp) that has a 
// parameter indicating the starting length of the array. 
GradeList::GradeList(int capacity) {
  count = 0;
  grades = new double[capacity];
  this->capacity = capacity;
}

GradeList::~GradeList() {
  delete [] grades;
}

double* GradeList::begin() {
  return grades;
}

double* GradeList::end() {
  //double* temp = grades[count - 1];
  return grades + count;
}

// TODO: Add the given grade to the grades list. If the array is full,
// resize it by doubling its length. Do not use realloc!
void GradeList::add(double grade) {
  if(count == capacity) {
    double* temp = new double[2*capacity];
    std::copy(grades, grades + capacity, temp);
    capacity = 2*capacity;
    delete [] grades;
    grades = temp;
  }
  grades[count] = grade;
  count++;
}



// TODO: Add the specified number of values from an array of 
// grades to this object.
void GradeList::add(int howmany, double * grades) {
  capacity = howmany + capacity;
  /*if(capacity == 0) {
    grades = new double[howmany];
    this->capacity = howmany;
    }*/
  for(int i = 0; i < howmany; i++) {
    double grade = grades[i];
    add(grade);
  }
  //capacity = capacity + howmany;
}

// TODO: write a function (in grade_list.cpp) to clear the list
// of all values, making the array as small as possible
void GradeList::clear() {
  delete [] grades;
  capacity = 0;
  count = 0;
}


