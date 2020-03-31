#include <iostream>
#include "GenQueue.h"
using namespace std;

int main(int argc, char **argv){
  GenStack *myStack = new GenStack(10); // creating a pointer because of 'new' so use ->
  myStack->push('R');
  myStack->push('e');
  myStack->push('n');
  myStack->push('e');


  cout << "popping :" << myStack->pop() << endl;
  cout << "peek-a-boo :" << myStack->peek() << endl;

  myStack->push('F');
  cout << "peek-a-boo :"  << myStack->peek() << endl;

  while(!myStack->isEmpty()){
    cout << "Popping :" << myStack->pop() << endl;
  }

  cout << "is stack empty? " << myStack->isEmpty() << endl;

  delete myStack;
  return 0;

}
