// Assignment 3
// Syntax Checker
//#include "GenStack.cpp"
#include "GenStack.h"
//#include "CheckSyntax.cpp"
#include "CheckSyntax.h"
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char** argv){
  bool do_continue = true;
  string fileName;
  char again;
  fstream inputStream;
  //CheckSyntax cs;

  while(do_continue){
    cout << "Enter the name of the file (with extension): ";
    cin >> fileName;

    inputStream.open(fileName);
    // if file exists
    if (inputStream) {
      // create CheckSyntax object
      CheckSyntax* cs = new CheckSyntax(fileName);
      // point to function in CheckSyntax
      cs->checkDelimeters();
      //delete object
      delete cs;

    } else { // if file does not exist
      cout << endl << ("The file does not exist. ");
    }
    inputStream.close();
    cout << "Do you want to check another file (Y/N): " << endl;
    cin >> again;
    if(tolower(again) == 'n'){
      do_continue = false;
    }
  }



  // isEmpty() == 1){
  //   char again;
  //   string nameOfFile;
  //   cout << "File complete. Would you like to check another file? (y/n) " << endl;
  //   if(tolower(again) == 'y'){
  //     cout << "Please enter the file you would like to open: ";
  //     cin >> nameOfFile;
  //     do_continue = true;
  //   }
  //   else{
  //     exit(1);
  //   }
  // }
  return 0;
}
