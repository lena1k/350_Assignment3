#include "CheckSyntax.h"
#include "GenStack.h"
#include <stack>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
// constructor
CheckSyntax::CheckSyntax(string fileName){
  inputFile.open(fileName);
}

//destructor
CheckSyntax::~CheckSyntax(){

}

void CheckSyntax::checkDelimeters(){

  GenStack<char> s(50);
  string line;
  int lineCount = 0;

    while(getline(inputFile, line)) {
      cout << "here" << endl;
      for(int i = 0; i < line.length(); ++i){
        if (!is_a_delimiter(line[i])) {
            continue;
        }
        if (is_a_start_delimiter(line[i])) {
            s.push(line[i]);
        } else {
            if (s.peek()=='(' && line[i] != ')') {
              cout << "Line " << lineCount << "expected ')' and found" << line[i] << endl;
              return;
            } else {
                s.pop();
                continue;
            }
            if(s.peek() == '[' && line[i] != ']'){
              cout << "Line " << lineCount << "expected ']' and found" << line[i] << endl;
              return;
            } else{
              s.pop();
              continue;
            }
            if(s.peek() == '{' && line[i] != '}'){
              cout << "Line " << lineCount << "expected '}' and found" << line[i] << endl;
              return;
            } else{
              s.pop();
              continue;
            }
        }
      ++lineCount;
    }
    if(s.isEmpty() == 0){
      cout << "Reached end of file: Missing the opposite of " << s.peek() << endl;
    }
}
}

bool CheckSyntax::is_a_delimiter(char c){
  return (strchr(delimiters, c) != NULL);
}

bool CheckSyntax::is_a_start_delimiter(char c){
  return(strchr(startDelimeters, c) != NULL);
}
