//Chris Wilhelm cwilhel8

#include "language_model.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::map;
using std::ifstream;

int read(string fileName, string operation, string word1, string word2) {
  map<string,int> trigram; //creates map for 3 word combinations to the number of times they appear
  string file; 
  ifstream infile1(fileName); //opens fileName
  if(infile1.is_open()) { //checks that it was opened properly
    while(infile1 >> file) { //loops through file, moving each file name from the initial file into the file string  individually
      ifstream fs(file); //attempts to open file
      if(fs.is_open() != true) { //checks if file did not open
	cerr << "Invalid file: " << file << endl;
      }
      else {
	string temp; 
	string word1 = "<START_1>"; //initializes parameters
	string word2 = "<START_2>";
	string word3;
	while (fs >> word3) { //while the file of words has words, passes them into word3
	  temp = word1 + " " + word2 + " " + word3; //creates trigram of the 3 words
	  trigram[temp] = trigram[temp] + 1; //incraments the integer value of trigram for each appearence of the word combination 
	  temp.clear(); //clears temp
	  word1 = word2; //shifts word2 to word1
	  word2 = word3; //shifts word3 to word2
	  word3.clear(); //clears word3
	}//the above ensures that all possible combination that occur consecutively are stored
	word3 = "<END_1>";//at this point, word1 and word2 have the second to last and last words respectively
	for(int i = 0; i < 2; i++) { //loops through an additional two times to get the final 2 trigrams
	  temp = word1 + " " + word2 + " " + word3;
	  trigram[temp] = trigram[temp] + 1;
	  temp.clear();
	  word1 = word2;
	  word2 = word3;
	  word3 = "<END_2>";
	  temp.clear();
	}
      }
      fs.close(); //closes the file of words
    }
  }
  else {
    cerr<< "Invalide file list: " << fileName << endl;
    return 2; //if file list fails to open returns 2
  }
  infile1.close(); //closes the file list
  if(operation.compare("a") == 0) { //the below if, else if, and else checks for the operation and calls its print function accordinly.
    print(trigram);
  }
  else if(operation.compare("d") == 0) {
    printRev(trigram);
  }
  else if(operation.compare("c") == 0) {
    printCount(trigram);
  }
  else if(operation.compare("f") == 0) {
    if(word1.empty() || word2.empty()) { //checks that neither word1 or word2 are empty, ie. missing arguments from command line
      cerr << "Invalid argument list: f requires two additional command-line arguments" << endl;
      return 3; //returns 3 if missing arguments
    }
    string match = word1 + " " + word2 + "\0";
    printFind(trigram, match);
  }
  else{ //if none of the operations match, returns 4
    cerr << "Invalid command: valid options are a, d, c, and f" << endl;
    return 4; 
  }
  return 0;
}

void print(map<string, int> trigram) { //prints the map in alphabetical order
  for(map<string, int> ::const_iterator it = trigram.cbegin(); it != trigram.cend(); ++it) {
    cout << it->second << " - [" << it->first << "]\n";
  }
}

void printRev(map<string, int> trigram) { //uses a reverse iterator to print in reverse alphabetical order
  for(map<string, int> ::reverse_iterator rit = trigram.rbegin(); rit != trigram.rend(); ++rit) {
    cout << rit->second << " - [" << rit->first << "]\n";
  }
}

void printCount(map<string, int> trigram) { //prints in order of occurance
  int max = 0; //the loop below finds the maximum occurance
  for(map<string, int> ::const_iterator it = trigram.cbegin(); it != trigram.cend(); ++it) {
    if(it->second > max) {
      max = it->second;
    }
  }
  for(int i = max; i > 0; i--) { //loops through the map checking for a match to max each time
    //this is repeated for all values from max to 1
    for(map<string, int> ::const_iterator it = trigram.cbegin(); it != trigram.cend(); ++it) {
      if(i == it->second) { //checks for occurance match
	cout << it->second << " - [" << it->first << "]\n";
      }
    }
  }
}

void printFind(map<string, int> trigram, string match) { //print function for the f operation
  int num = 0; //integer for number of occurances
  string finish = " "; //variable to store the matched word, ie. third word
  for(map<string, int> ::const_iterator it = trigram.cbegin(); it != trigram.cend(); ++it) { //loops through trigram
    string temp = it->first;
    std::size_t found = temp.find_last_of(" ");//finds location of last space, ie. before the final word
    string last = temp.substr(0, found); //creates string of the first two words(second space not included)
    if(last.compare(match) == 0 && it->second > num) { //compares the first two words to the arguments
      //also checks that the occurance number is greater than the previous one.
      num = it->second;
      finish.clear();
      finish = it->first;
    }
  }
  if(num > 0) { //if a match is found, prints the occurance and trigram
    cout << num << " - [" << finish << "]\n";
  }
  else {
    cout << "No trigrams of the form [" << match << " ?]" << endl;
  }
}
