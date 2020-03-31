#include <iostream>

class GenQueue{
  public:
    GenQueue(); //default constructor
    GenQueue(int maxSize); //overloaded constructor
    ~GenQueue;

    //core functions
    void insert(char d); //enqueue
    char remove();//dequeue

    //aux functions
    char peek();
    bool isFull();
    bool isEmpty();
    int getSize();

    //variables
    int front; // aka head
    int rear; //aka tail
    int mSize;
    int numElements;

    char *myQueue; //array
    
};
