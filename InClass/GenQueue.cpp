#include "GenQueue.h"
#include <iostream>
GenQueue::GenQueue(){
  //default constructor
  //
}
//overloaded constructor
GenQueue::GenQueue(int maxSize){
  myQueue = new char[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

genQueue::~GenQueue(){
  delete myQueue;
}

void GenQueue::insert(char d){
  //add error checking
  myQueue[++rear] = d;
  ++numElements;
}

char GenQueue::remove(){
  //error checking
  char c = '\0';
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}
