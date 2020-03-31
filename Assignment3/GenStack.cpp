#include <iostream>
#include "GenStack.h"

using namespace std;

// constructor
template <class T>
GenStack<T>::GenStack(int size){
  arr = new T[size];
  capacity = size;
  top = -1;
  tempArray = new T[capacity];
}

// destructor
template <class T>
GenStack<T>::~GenStack(){
  delete []arr;
  delete []tempArray;
}

template <class T>
void GenStack<T>::push(T x){
  if(isFulL()){
    increaseSize();
    push(x);
  }
  arr[++top] = x;
}

template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    throw underflow_error("Stack is underflowed.");
    exit(1);
  }
  return arr[top--];
}

template<class T>
T GenStack<T>::peek(){
  if(!isEmpty()){
    return arr[top];
  }
  else{
    exit(1);
  }
}


template<class T>
int GenStack<T>::isFull(){
  return top == capacity - 1;
}

template <class T>
int GenStack<T>::isEmpty(){
  return (top == -1);
}

//allocates more room to Stack
template <class T>
void GenStack<T>::increaseSize(){
  tempArray = new T[capacity];
  for(int i = top; i > -1; --i){
    tempArray[i] = arr[i];
  }
  ++capacity;
  arr = new T[capacity];
  for(int i = top; i > -1; --i){
    arr[i] = tempArray[i];
  }
}
