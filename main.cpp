#include "Quiz1.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
  if(argc > 1){
    // string test = argv[1];
    //string test = "leanshfeaiefAAFE";
    string test = "";

    cout << "please enter a string" << endl;
    cin >> test;

    //cout << "please enter a string" << endl;

    //Quiz1 q; // stored on the stack; don't need to use delete; use . instead of ->
    Quiz1 *q = new Quiz1(); //stored on the heap

    cout << "number of ommand line arguments: " << argc << endl;
    cout << "the number of vowels in " << test << "is: " << q->countVowels(test) << endl;

    cout << "program exited successfully" << endl;
    delete q;
  }
  // else{
  //   cout << "your program crashed";
  // }
  return 0;
}
