class ListNode{
  public:
    int data;
    ListNode *next;

    ListNode(); //constructor
    ListNode(int d); //overloaded constructor
    ~ListNode();


};

//ListNode implementation file(.cpp)
ListNode::ListNode(){
  data = 0;
  next = NULL;

}

ListNode::ListNode(int d){
  data = d;
  next = NULL;
}

ListNode::~ListNode(int d){

}
//header file for SingleLinkedList
class NaiveList{
  private:
    ListNode *front;
    usigned int size;

  public:
    NaiveList();
    ~NaiveList();

    void insertFront(int data);
    int removeFront();
    int search(int val); // will return position of ListNode
    int removeAtPos(int pos);

    unsigned int getSize();
    bool isEmpty();
    void printList();
};

//implementation file(.cpp) for my NaiveList
NaiveList::NaiveList(){
  size = 0;
  front = NULL;

}

NaiveList::~NaiveList(){

}
unsigned int NaiveList::getSize(){
  return size;
}
bool NaiveList::isEmpty(){
  return (size == 0);
}

void NaiveList::printList(){
  ListNode *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

void NaiveList::insertFront(int d){
  ListNode *node = new ListNode(d);
  node->next = frontl
  front = node;
  size++;
}

void NaiveList::removeFront(){
  //check if empty before removing
  int temp = front->data;
  ListNode *ft = front;
  front = front->next;
  ft->next=NULL;
  delete ft;
  return temp;
  size--;
}
