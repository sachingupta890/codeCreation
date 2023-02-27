#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }


    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for "<<value<<endl;
    }
};

void insertAtTail(Node*&head, Node*&tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtHead(Node*&head,Node*&tail,int data){
    Node* newNode = new Node(data);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertAtPos(Node*&head,Node*&tail,int data,int pos){
    Node* newNode = new Node(data);
    if(pos == 1){
        insertAtHead(head,tail,data);
        return;
    }

    Node* curr = head;
    int count = 1;
    while(count < pos-1){
        curr = curr->next;
        count++;
    }
    if(curr->next == NULL){
        insertAtTail(head,tail,data);
        return;
    }
    Node* curr_next = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
    newNode->next = curr_next;
    curr_next->prev = newNode;
}

void deletion(Node*&head,Node*&tail,int pos){
   if(head == NULL){
    cout<<"no  node to delete "<<endl;
    return;
   }

   if(head->next == NULL){
    head = NULL;
    tail = NULL;
    return;
   }

   if(pos == 1){
      Node* head_next = head->next;
      head->next = NULL;
      head_next->prev = NULL;
      delete head;
      head = head_next;
      return;
   }

   int count = 1;
   Node* temp = head;
   while(temp->next!=NULL && count < pos-1){
        temp = temp->next;
        count ++;
   }

   Node* temp_next = temp->next;
   temp->next = temp_next->next;
   if(temp_next->next!=NULL){
    temp_next->next->prev = temp;
   }
   else{
    tail = temp;
   }
   temp_next->prev = NULL;
   temp_next->next = NULL;
   delete temp_next;

}

void print(Node*&head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){


    Node* head = NULL;
    Node* tail = NULL;


    insertAtHead(head,tail,23);

    insertAtTail(head,tail,24);


    insertAtTail(head,tail,26);



    insertAtPos(head,tail,27,4);
    print(head);

    deletion(head,tail,4);
    print(head);
    cout<<"head is: "<<head->data<<endl;
    cout<<"tail is: "<<tail->data<<endl;

    return 0;
}