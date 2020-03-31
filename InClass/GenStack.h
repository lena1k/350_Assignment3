#include <iostream>
using namespace std;

class GenStack{
public:
  GenStack(); // default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); //destructor

  // core function
  void push(char data) // insert an item
  char pop(); //remove

  //aux/helper functions
  char peek(); // AKA top
  bool isEmpty();
  bool isFull();

  int top;
  int mSize;

  char *myArray; // represents the memory address of the first block

  
}
