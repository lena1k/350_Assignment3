#include "Quiz1.h"
using namespace std;

Quiz1::Quiz1(){
  myArray = new int[20];
}
Quiz1::~Quiz1(){
  delete myArray;
  cout << "Object deleted" << endl;
}
int Quiz1:: countVowels(string input){
  int count = 0;
  for(int i = 0; i < input.size(); ++i)
  {
    char strInput = tolower(input[i]);
    if(strInput == 'a'){
      count++;
    }
    else if(strInput == 'e'){
      count++;
    }
    else if(strInput == 'i'){
      count++;
    }
    else if(strInput == 'o'){
      count++;
    }
    else if(strInput == 'u'){
      count++;
    }
    return count;
  }
}
