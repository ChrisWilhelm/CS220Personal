//Chris Wilhelm
//cwilhel8
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_file(FILE *fp, char words[][MAX_WORD_SIZE + 1], int size) {
  for(int i = 0; i < size; i++) {//loops through the words array
    for(int j = 0; j < MAX_WORD_SIZE + 1; j++) {
      words[i][j] = '\0';//initializes all entries to \0 to ensure to additional chars
    }
    fscanf(fp, "%s\n", words[i]);//after a row is set to \0, the word is scanned into it
  }
  for(int i = 0; i < size; i++) {
    if(words[i][0] == '\0') {//ensures that a word is not missing and thus the input file is accurate
      return 1;
    }
  }
  return 0;    
}

int match(char *regex, char *word, int restriction) {
  int i  = 0;
  for(int j = 0; j < MAX_INPUT_SIZE + 1; j++) {
    int val;
    if(regex[j] == '\0' && word[i] == '\0') {//checks to see if the end of both has been reached
      break;
    }
    if(regex[j+1] == '*') { //checks if star is in next position
      i = match_kleene_star(i, j, regex, word);
      j++;
    }
    else {
      if(regex[j] == word[i] && regex[j+1] != '?') {//match but no ? after
	i++;
      }
      else {
	if(regex[j] != word[i] && regex[j+1] != '?' && regex[j] != '~') { //checks if words don't match and there is no ? after or a tilde in current position
	  return 0;//returns zero bc they don't match
	}
	else {
	  if(regex[j+1] == '?') { //question mark one position after
	    int val =  match_question_mark(i, j, regex, word, restriction);
	    if (val == 1) {
	      return 1;
	    }
	    if (val == 0) {
	      j++;
	    }
	    if (val == -1) {
	      return 0;
	    }
	  }
	  else {
	    if(regex[j] == '~') { //~ at position
	      val = match_tilde(i, j, regex, word, restriction);
	      if(val == 0) {
		return 1;
	      }
	      if(val == -1) {
		return 0;
	      }
	      else {
		i = val;
	      }
	    }
	  }
	}
      }
    }
  }
  return 1;
}

int match_tilde(int wordIndex, int regexIndex, char *regex, char *word, int restriction) {
  int r;
  int i;
  for(r = 0; r <= restriction; r++) {
    for(i = 0; i < MAX_INPUT_SIZE - regexIndex; i++) {
      if(regex[regexIndex + 1 + i] == word[wordIndex + r + i]) {//chekcs if the word matches the regex with current restriction and given index
	if(word[wordIndex +r + i] == '\0') {//checks if the word and regex ended
	  return 0;
	}
	else {
	  int indexTemp = wordIndex + r + i;
	  return indexTemp;//returns word index
	}
      }
      else {
	break;
      }
    }
  }
  if(regex[regexIndex + 1 + i] == '~') {//checks for second tilde
    int tempIndexWord = wordIndex + r + i;
    int tempIndexRegex = regexIndex + i + 1;
    return match_tilde(tempIndexWord, tempIndexRegex, regex, word, restriction);
  }
  return -1;//if it reaches here, the tilde does not cause a match
}


int match_kleene_star(int wordIndex, int regexIndex, char *regex, char *word) {
  while(regex[regexIndex] == word[wordIndex]) {//checks for how long the words match
    wordIndex++;//word index is incramented each time
  }
  return wordIndex;//returns new val of word index
}

int match_question_mark(int wordIndex, int regexIndex, char *regex, char *word, int restriction) {
  if(regex[regexIndex] != word[wordIndex]) {//checks if the chars do not match
    return 0;
  }
  if(word[wordIndex + 1] == '\0') {//checks for end of word
    if(regex[regexIndex+2] == '\0') {//checks for end of regex
      return 1;
    }
    else {
      return -1;
    }
  }
  else {
    char tempInput[MAX_INPUT_SIZE];//creates temp regex, with everything after question
    for(int i = 0; i < MAX_INPUT_SIZE - regexIndex - 2; i++) {
      tempInput[i] = regex[regexIndex + 2 + i];
    }
    char tempWord[MAX_WORD_SIZE];//creates temp word after current index
    if( wordIndex > 0) {
      for(int i = 0; i < MAX_WORD_SIZE - wordIndex; i++) {
	tempWord[i] = word[wordIndex + i + 1];
      }
    }
    else {
      for(int i = 0; i < MAX_WORD_SIZE - wordIndex; i++) {
	tempWord[i] = word[wordIndex + i];
      }
    }
    int val = match(tempInput, tempWord, restriction);//this function is called to match the rest of the word in the case that the question mark does not delete the letter
    if(val == 1) {
      return 1;
    }
    else {
      return -1;
    }
  }
  return -1;
}
