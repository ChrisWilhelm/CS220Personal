//Chris Wilhelm
//cwilhel8
#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__
#include <stdio.h>
#include <ctype.h>
#define MAX_INPUT_SIZE 128
#define MAX_WORD_SIZE 32
#define DEFAULT_RESTRICTION 10

/** Function to read data from file pointer into words array.
 *  @param fp the filepointer to search words file.
 *  @param words is the 2D character array of words
 *  @param size is the expected number of words in the file.
 *  @return 0 if no issues, 1 if there are issues.
 */
int read_file(FILE *fp, char words[][MAX_WORD_SIZE + 1], int size);

/** Match function to check whether regex matches a word.
 * @param regex, is a null terminated char array of the regex
 * @param word is the null terminated char array of word to match to
 * @param restriction is the restriction size for the tilde operator
 * @return 1 if it is a match, else 0 if it's not a match.
 */
int match(char *regex, char *word, int restriction);

/** Function to match for the tilde operator.
 * @param wordIndex is the index at which match called the function
 * @param regexIndex is the regex Index at which the ~ is located
 * @param regex, is a null terminated char array of the regex
 * @param word is the null terminated char array of word to match to
 * @param restriction is the restriction size for the tilde operator
 * @return 0 if it is a finalized math, if a match but not final
 * it will return the index of word to match else -1 if it is not a
 * match.
 */
int match_tilde(int wordIndex, int regexIndex, char *regex, char *word, int restriction);

/** Function to match for the kleene star operator.
 * @param wordIndex is the index at which match called the function
 * @param regexIndex is the regex Index at which the * is located
 * @param regex, is a null terminated char array of the regex
 * @param word is the null terminated char array of word to match to
 * @return word Index for where to begin checking again.
 */
int match_kleene_star(int wordIndex, int regexIndex, char *regex, char *word);

/** Function to match for the tilde operator.
 * @param wordIndex is the index at which match called the function
 * @param regexIndex is the regex Index at which the ~ is located
 * @param regex, is a null terminated char array of the regex
 * @param word is the null terminated char array of word to match to
 * @param restriction is the restriction size for the tilde operator
 * @return 0 if it is a finalized match and returns the index of 
 * word for where to resume checking, else returns -1 for not a 
 * match.
 */
int match_question_mark(int wordIndex, int regexIndex, char *regex, char *word, int restriction);

#endif
