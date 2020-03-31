class ListNode{
  public:
    int data;
    ListNode *next;
    ListNode *prev;


    ListNode(); //constructor
    ListNode(int d); //overloaded constructor
    ~ListNode();



};

//ListNode implementation file(.cpp)
ListNode::ListNode(){
  data = 0;
  next = NULL;
  prev = NULL;

}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
  prev = NULL;
}

ListNode::~ListNode(int d){

}
//header file for SingleLinkedList
class DoublyLinkedList{
  private:
    ListNode *front;
    ListNode *back;
    usigned int size;

  public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insertFront(int data);
    void insertBack(int data);
    int removeFront();
    int removeBack();
    int search(int val); // will return position of ListNode
    int removeAtPos(int pos);

    unsigned int getSize();
    bool isEmpty();
    void printList();
};

//implementation file(.cpp) for my DoublyLinkedList
DoublyLinkedList::DoublyLinkedList(){
  size = 0;
  front = NULL;

}

DoublyLinkedList::~DoublyLinkedList(){

}
unsigned int DoublyLinkedList::getSize(){
  return size;
}
bool DoublyLinkedList::isEmpty(){
  return (size == 0);
}

void DoublyLinkedList::printList(){
  ListNode *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void DoublyLinkedList::insertFront(int d){
  ListNode *node = new ListNode(d);

  if(isEmpty()){
    back = node;
  }
  else{
    //not isEmpty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}
void DoublyLinkedList::inser4Back(int d){
  ListNode *node = new ListNode(d);

  if(isEmpty()){
    front = node;
  }
  else{
    //not isEmpty
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

void DoublyLinkedList::removeFront(){

}
