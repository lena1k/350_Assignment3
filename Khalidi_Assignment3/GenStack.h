
#include <stack>
#include <string>


#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class GenStack{
public:

  GenStack(int size);
  ~GenStack();
  // int *arr;
  int top;
  int capacity;

  void push(T x);
  T pop();
  T peek();
  int isFull();
  int isEmpty();
  //int size();
  void resizeArray();



  T *tempArray;
  T *arr;

};

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
  if(this->isFull() == 1){
    this->resizeArray();
    push(x);
  }
  arr[++top] = x;
}

template <class T>
T GenStack<T>::pop(){
  cout << "here now" << endl;
  if(isEmpty() == 1){
    throw underflow_error("Stack is underflowed.");
    //exit(1);
  }
  return arr[top--];
}

template<class T>
T GenStack<T>::peek(){
  if(!isEmpty() == 1){
    return arr[top];
  }
  else{
    return ' ';
  }
}


template<class T>
int GenStack<T>::isFull(){

  return top == (capacity - 1);
}

template <class T>
int GenStack<T>::isEmpty(){

  --top;
  return top;
}

//allocates more room to Stack
template <class T>
void GenStack<T>::resizeArray(){
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
