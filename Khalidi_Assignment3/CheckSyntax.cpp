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
  int lineCount = 1;

  // iterate through lines of file
  while(getline(inputFile, line)) {
    //cout << "here" << endl;
    try{
      for(int i = 0; i < line.length(); ++i){
        if (!is_a_delimiter(line[i])) {
            continue;
        }
        if (is_a_start_delimiter(line[i])) {
            s.push(line[i]);
        } else {
          // peek each time you encounter delimeter
            if (s.peek()=='(' && line[i] != ')') {
              cout << "Line " << lineCount << " expected ')' and found " << line[i] << endl;
              return;
            } else {
              // continue loop if no error
                s.pop();
                continue;
            }
            // peek each time you encounter delimeter
            if(s.peek() == '[' && line[i] != ']'){
              cout << "Line " << lineCount << " expected ']' and found " << line[i] << endl;
              return;
            } else{
              // continue loop if no error
              s.pop();
              continue;
            }
            // peek each time you encounter delimeter
            if(s.peek() == '{' && line[i] != '}'){
              cout << "Line " << lineCount << " expected '}' and found " << line[i] << endl;
              return;
            } else{
              // continue loop if no error
              s.pop();
              continue;
            }
          }
        }
      }
        catch(underflow_error e){ // returns error if program ends with delimeter without a match
          cout << "Line " << lineCount << " found without starting delimeter." << endl;
          return;
        }

    ++lineCount;
  }
  if(!s.isEmpty()){
    cout << "Reached end of file: Missing the opposite of " << s.peek() << " on line " << lineCount << endl;
  }
  else{
    cout << "File is complete." << endl;
  }
}

bool CheckSyntax::is_a_delimiter(char c){
  // checking for char in string
  return (strchr(delimiters, c) != NULL);
}

bool CheckSyntax::is_a_start_delimiter(char c){
  // checking for char in string
  return(strchr(startDelimeters, c) != NULL);
}
