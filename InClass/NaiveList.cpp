


int MaiveList::search(int val){
  int pos = -1;
  ListNode *curr = fromt;
  //let's loop and attempt to find the value
  while(curr != NULL){
    ++pos;
    if(curr->data == val){
      // we found it (same value)
      break;
    }
    else{
      //we didn't continue iterating
      curr = curr->next;
    }
    if(curr == NULL){
      //didn't find it
      pos = -1;
    }
    return pos;
  }
}

int Naivelist::removeAtPos(int pos){
  //error to make sure pos does not exceed size of ListNode
  int idx = 0;
  ListNode *curr = front;
  ListNode *prev = front;

  while(idx != pos){
    //loop until i find the position
    prev = curr;
    curr = curr->next;
    idx++;
  }

  //now let's continue with the deletion process
  prev->next = curr->next;
  curr->next = NULL;
  int temp = curr->data;
  delete curr;
  size--;

  return temp;
}
