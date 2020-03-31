
#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <class T>
class GenStack{
public:

  GenStack(int size);
  ~GenStack();
  // int *arr;
  int top = 0;
  int capacity = 0;

  void push(T x);
  T pop();
  T peek();
  int isFull();
  int isEmpty();
  //int size();
  void increaseSize();



  T *tempArray;
  T *arr;

};
