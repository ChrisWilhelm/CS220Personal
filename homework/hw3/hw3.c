//Chris Wilhelm
//cwilhel8
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

int main(int argc, char* argv[]) {
  int restriction = DEFAULT_RESTRICTION;
  int num;
  FILE *fptr;
  if(argc == 1) {//if there are no arguments, returns an error
    printf("Error: No input file\n");
    return 1;
  }
  if((fptr = fopen(argv[1], "r"))== NULL) { //if there is not a valid file, returns
    printf("Error: Invalid Input file\n");// an error
    return 2;
  }
  if( argc == 3) { //converts number argument to its resitriction value
    restriction = *argv[2] - '0';
  }
  if(restriction <= 0) {//returns 4 if restriction is invalid
    return 4;
  }
  fscanf(fptr, "%d\n", &num); //scans number at top of file into num
  if(num <= 0) { //returns 3 if num is invalid
    return 3;
  }
  char word[MAX_INPUT_SIZE];
  char filewords[num][MAX_WORD_SIZE + 1];
  int read = read_file(fptr, filewords, num);
  if( read != 0) {
    return 3;//return for failure to read file
  }
  while(fscanf(stdin, "%s", word) == 1) {
    int numMatch = 0;
    for(int i = 0; i < num; i++) {//loops through all words in array
      int match_val = match(word, filewords[i], restriction);
      if( match_val == 1) {
	printf("%s\n", filewords[i]);
	numMatch++;
      }  
    }
    if(numMatch == 0) {
      printf("No match found for regex \'%s\'\n", word);
    }
  }
  fclose(fptr);
  return 0;
}
