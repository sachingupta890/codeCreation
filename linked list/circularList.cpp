#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  //constructor
  Node(int data){
    this->data = data;
    this->next = NULL;
  }


  //destructor
  ~Node(){
    int val = this->data;
    if(this->next != NULL){
      delete next;
      this->next = NULL;
    }

    cout<<"memory is free for "<<val<<endl;
  }
};

void insertValue(Node*&tail,int element ,int data){
  // empty list
  if(tail == NULL){
    Node* newNode = new Node(data);
    tail = newNode;
    newNode->next = newNode;
    return;
  }
  else{
    //assuming element is present in linked list 
    Node* curr = tail;
    while(curr->data != element){
      curr = curr->next;
    }

    // now we are standing at curr positioning element 
    Node* newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
   
    
  }
  
}
void print(Node* tail){
  Node* temp = tail;
  do{
    cout<<tail->data<<"-> ";
    tail = tail->next;
  }while(tail != temp);
  cout<<"NULL"<<endl;
}
int main() {

  Node* tail = NULL;
  insertValue(tail,2,5);
  print(tail);

  insertValue(tail,5,6);
  print(tail);
  
}