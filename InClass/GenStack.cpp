z#include "GenStack.h"
#include <iostream>
// default constructor
GenStack::GenStack(){
  myArray = new char[128]; //on the heap because you are using new
  mSize = 128;
  top = -1;
}

//overloaded constructor
GenStack::GenStack(int maxSize){
  myArray = new char[maxSize]; //on the heap because you are using new
  mSize = maxSize;
  top = -1;
}

GenStack::GenStack(){
  delete myArray;
}

void GenStack::push(char data){
  //check if full before atempting to push/insert
  myArray[++top] = data;
}
char GenStack::pop(){
  //check if empty before attempting to remove
  return myArray[top--];
}

char GenStack:: peek(){
  return myArray[top];
}

bool GenStack::isFull(){
  return(top == mSize-1);
}
bool GenStack::isEmpty(){
  return(top == -1);
}

char GenQueue::peek(){
  return myQueue[front];
}
bool GenQueue::isFull(){
  return(numElements == mSize);
}
bool GenQueue::isEmpty(){
  return(numElements == 0);
}
int GenQueue::getSize(){
  return numElements;
}
