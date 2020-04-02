
#include <string>

#include <iostream>
#include <fstream>

using namespace std;

class CheckSyntax {
  const char* delimiters = "(){}[]";
  const char* startDelimeters = "({[";
  ifstream inputFile;

public:
  CheckSyntax(string fileName);
  ~CheckSyntax();

  void checkDelimeters();
  bool is_a_delimiter(char c);
  bool is_a_start_delimiter(char c);
};
