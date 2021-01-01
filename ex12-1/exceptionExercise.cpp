#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

/* Collect integers from a file; store them in a vector */
std::vector<int> readFile(char* filename) {
  std::vector<int> numbers(10);
  std::ifstream fin(filename);
  try {
    if(fin.is_open() == false) {
      throw std::ios_base::failure("File does not exist");
    }
  } catch(const std::ios_base::failure& e) {
    std::cout << "Invalid file" << e.what() << std::endl;
    numbers.resize(0);
    return numbers;
    //std::cout << "Input new file name: ";
    //std::cin >> filename;
    // std::ifstream fin(filename);
  }

  int n = 0;
  size_t index = 0;
  while(true) {
    fin >> n;
    if (fin.eof()) { // if we're out of file, return
      return numbers;
    }

    try {
      if (fin.fail()) { // if we failed to read an int, throw an exception
	throw std::invalid_argument("Error: wrong type of argument");
      }
    } catch(const std::invalid_argument& e) {
      std::cout << "Invalid argument, skipping it: " << e.what() << std::endl;
      fin.clear();
      std::string a;
      fin >> a;
      continue;
    }
    // otherwise, just add it into the vector
    try {
      numbers.at(index) = n;
    } catch(const std::out_of_range& e) {
      std::cout << "Too many integers in file: " << e.what() << "\n";
      numbers.resize(index, n);
    } 
    index++;
  }

  throw std::logic_error("ERROR: should never get here!");
  //numbers.resize(index);
  return numbers;
}


int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: program requires a filename as an argument\n";
    return 0;
  }

  std::vector<int> numbers;
  numbers = readFile(argv[1]);

  std::cout << "Read numbers: ";
  for(int &i : numbers) {
      std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}
