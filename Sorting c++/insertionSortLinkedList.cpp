#include<bits/stdc++.h>
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
};

void insert(Node*& head,int data){

  //step 1 create the node
  Node* newNode = new Node(data);

  //step 2 check if list is empty or not
  //if yes
  if(head == NULL){
    head = newNode;
    return;
  }

  Node* curr = head;
  Node* prev = NULL;
  while(curr!= NULL && curr->data < data){
    prev = curr;
    curr = curr->next;
  }
  //curr is at first node which is head and bigger than 
  if(prev == NULL){
    newNode -> next = head;
    head = newNode;
  }
  else{
    newNode->next = prev->next;
    prev->next = newNode;
  }
  
}
void print(Node* head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL";
  cout<<endl;
}
int main(){

  Node* head = NULL;
  insert(head,12);
  insert(head,13);
  insert(head,11);
  insert(head,19);
  insert(head,1);
  insert(head,14);
  insert(head,10);
  print(head);
}