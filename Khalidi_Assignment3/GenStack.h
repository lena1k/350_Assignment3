
#include <stack>
#include <string>


#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class GenStack{
private:

  int top;
  int capacity;
  T *arr;

public:

  GenStack(int size);
  ~GenStack();

  void push(T x);
  T pop();
  T peek();
  int isFull();
  bool isEmpty();
  void resizeArray();

};

// constructor
template <class T>
GenStack<T>::GenStack(int size){
  arr = new T[size];
  capacity = size;
  top = -1;
}

// destructor
template <class T>
GenStack<T>::~GenStack(){
  delete []arr;
}

template <class T>
void GenStack<T>::push(T x){
  if(this->isFull()){
    this->resizeArray();
  }
    arr[++top] = x;
  }


template <class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    throw underflow_error("Stack is underflowed.");
  }
  return arr[top--];
}


template<class T>
T GenStack<T>::peek(){
  if(top == -1){
    throw underflow_error("Stack is underflowed.");
  }
  return arr[top];
}


template<class T>
int GenStack<T>::isFull(){

  return top == (capacity - 1);
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

//allocates more room to Stack
template <class T>
void GenStack<T>::resizeArray(){
  int new_capacity = 2 * capacity;
  T *tempArray = new T[new_capacity];
  for(int i = 0; i < top; ++i){
    tempArray[i] = arr[i];
  }
  T *old_arr = arr;
  arr = tempArray;
  capacity = new_capacity;
  delete old_arr;

}
