//Chris Wilhelm cwilhel8
#ifndef LANGUAGE_MODEL_H
#define LANGUAGE_MODEL_H

#include <map>
#include <string>


/**Function to create a map of trigrams, from strings to ints by opening
 * the file "fileName" and using the fileNames contained in it as the 
 * strings of the trigram. The to call the specified operations print 
 * function.
 * @param fileName the name of the file list.
 * @param operation the operation to be performed when printing
 * @param word1 to be used for f(find) operation only, else if passed as 
 * the null terminator
 * @param word2 to be used for f(find) operation only, else if passed as 
 * the null terminator
 * @return int 0 if the function is successful. 2 if fileList did not oper
 * 3 if missing arguments for find, and 4 if missing file or operation
 */
int read(std::string fileName, std::string operation, std::string word1, std::string word2);


/**Function to print the trigram of words in alphabetical order
 * @param trigram which is a map of strings to integers for frequency
 * @return void
 */
void print(std::map<std::string, int> trigram);

/**Function to print the trigram of words in reverse alphabetical order
 * @param trigram which is a map of strings to integers for frequency
 * @return void
 */
void printRev(std::map<std::string, int> trigram);

/**Function to print the trigram of words in order of frequency
 * @param trigram which is a map of strings to integers for frequency
 * @return void
 */
void printCount(std::map<std::string, int> trigram);

/**Function to print the trigram of words that match the input match.
 * This will only output one trigram, this will be the firstly the most 
 * frequent and secondly the first alphabetically.  
 * @param trigram which is a map of strings to integers for frequency
 * @param match whicb is a string of the words word1 and word2 from read
 * @return void
 */
void printFind(std::map<std::string, int> trigram, std::string match);

#endif
