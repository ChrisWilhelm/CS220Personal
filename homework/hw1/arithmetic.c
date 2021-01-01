//Chris Wilhelm
//cwilhel8

#include <stdio.h>

int main() {
  float solution;
  int result = 0;
  printf("Please enter an arithmetic expression using * and / only: \n");
  float num1;
  if(scanf(" %f",&num1) == 1) {
    solution = num1;
  }
  else {
    printf("malformed expression\n");
    return result = 1;
  }
  float num2;
  char operator;
  while(scanf(" %c %f", &operator, &num2) == 2) {
    if(operator == '*') {
      solution = solution * num2;
    }
    if(operator == '/') {
      if(num2 == 0) {
	printf("division by zero\n");
	return result = 2;
	break;
      }
      else {
	solution = solution / num2;
      }
    }
    if(operator != '/' && operator != '*') {
      printf("malformed expression\n");
      return result = 1;
      break;
    }
  }
  char num2C;
  if(scanf(" %c %c", &operator, &num2C) == 2) {
    printf("malformed expression\n");
    return result = 1;
  }
  if(result == 0) {
    printf("%f\n", solution);
  }
  return result;
}
      
