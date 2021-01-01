//Chris Wilhelm cwilhel8
#include "language_model.h"
#include <string>
#include <iostream>

using std::string;
using std::cerr;
using std::endl;

//returns 0 if everything works as expected
int main(int argc, char *argv[]) {
  int val;
  if (argc >= 3) { //checks that at least a file name, operation are included
    if(argc >= 5) { //checks that the two word parameters are included and will be used if needed, any extras will be ignored
      return val = read(argv[1], argv[2], argv[3], argv[4]);
    }
    else {
      return val = read(argv[1], argv[2], "\0", "\0");
    }
  }
  else { //if missing filename or operation
    cerr << "Missing one or more essential arguments: file name, operation or both." << endl;
    return 1;
  }
}
