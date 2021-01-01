//Ex2-1: gpa_simple.c

/* The purpose of this program is to compute GPAs for simple letter
   grades - no +/-, only A, B, C, D, F. Credits may be rational
   numbers.  Also determine and display notices for Dean's List
   (>=3.5) and Academic Probation (< 2.0).

SAMPLE RUN:

Welcome to the GPA calculator!
Enter grade and credits for each course below (ctrl-d to end):
course 1: A 4.0
course 2: b 2.7
course 3: B 3.5
course 4: c 3.0
course 5: f 1
course 6: a 3
course 7: 
Your GPA is 3.06

-----
PSEUDOCODE:

point_sum gets 0
credit_sum gets 0
points gets 0
gpa gets 0

display “Welcome to GPA calculator!”
prompt for list of grade/credits pairs

count gets 1
display "course #", count

repeat while there is a grade and credits to read
    convert grade to points
    add points * credits to point_sum
    add credits to credit_sum
    add 1 to count
    display "course #", count

if credit_sum > 0
   set gpa to point_sum / credit_sum
   display "GPA is ", gpa
   if gpa >= 3.5
      display "Dean's List"
   otherwise if gpa <= 2.0
      display "Uh-oh, Academic Probation..."
otherwise
   display "No credits attempted; no GPA to report"

*/


#include <stdio.h>

int main() {
  printf("Welcome to GPA calculator!\n");
  printf("Enter grade and credits for each course below (ctrl-d to end):\n");
  double point_sum = 0;
  double point = 0;
  double credit_sum = 0;
  double gpa = 0;
  double credits;
  char letter;
  int count = 1;
  printf("Course %d", count);
  printf(": ");
  while(scanf(" %c %lf", &letter, &credits) == 2) {
    switch(letter) {
    case 'A' :
    case 'a' :
      point = 4.0;
      break;
    case 'B' :
    case 'b' :
      point = 3.0;
      break;
    case 'C' :
    case 'c' :
      point = 2.0;
      break;
    case 'D' :
    case 'd' :
      point = 1.0;
      break;
    case 'F' :
    case 'f' :
      point = 0.0;
      break;
    default :
      printf("Invalid grade\n");
    }
    credit_sum = credit_sum +  credits;
    point_sum = point_sum + (point * credits);
    count++;
    printf("Course %d", count);
    printf(": ");
  }
  if (credit_sum > 0) {
    gpa = point_sum / credit_sum;
    printf("Your GPA is: %f", gpa);
    printf("\n");
    if(gpa >= 3.5) {
      printf("Dean's List");
    }
    if(gpa <= 2.0) {
      printf("Uh-oh, academic probation...");
    }
    printf("\n");
  }
  else {
    printf("No credits presented, nothing to report");
  }
  return 0;
}
