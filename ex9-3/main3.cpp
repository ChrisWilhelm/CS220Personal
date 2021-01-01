/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: Write a program that declares a GradeList
 *       variable and adds to it all the even
 *       numbers 0-100:
 *       
 *       {0, 2, 4, ..., 98, 100}
 * 
 *       then prints out the minimum, maximum,
 *       median, mean and 75th percentile, all
 *       nicely labelled.
 */
#include "grade_list.h"
#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

int main(void) {

  GradeList gl;

  for(double i = 0.0; i < 101.0; i = i + 2.0) {
    gl.add(i);
  }
  cout << "Minimum grade is: " << gl.min() << endl;
  cout << "Maximum grade is: " << gl.max() << endl;
  cout << "Median grade is: " << gl.median() << endl;
  cout << "Mean grade is: " << gl.mean() << endl;
  cout << "75th percentile is: " << gl.percentile(75.0) << endl;
}
