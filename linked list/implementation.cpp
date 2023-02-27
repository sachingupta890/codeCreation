#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    //constuctor
    Node(int data){
        this->data = data;
        this->next = NULL;

    }
    ~Node(){
        int data = this->data;
        if(next!=NULL){
            this->next = NULL;
        }
        cout<<"deleted node is"<<data<<endl;
    }
};
void insertAtHead(Node*&head,Node*&tail,int data){
    //step 1 creation of node
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node*&head,Node*&tail,int data){
    //step 1 creation of node
    Node* newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}
void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-> ";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertAtPos(Node*&head,Node*&tail,int data,int pos){

    if(pos == 1){
        insertAtHead(head,tail,data);
        return;
    }
    Node* newNode = new Node(data);
    Node* temp = head;

    int count = 1;
    while(temp!=NULL && count < pos-1){
        temp = temp->next;
        count += 1;
    }

    //step 3 save the pointer of next of temp
    Node* save=temp->next;
    temp->next = newNode;
    newNode->next = save;


}

void deletion(Node*&head,Node*&tail,int pos){
    if(head == NULL){
        return;
    }

    if(pos == 1){
        Node* nodeToDelete = head;
        head = head->next;
        free(nodeToDelete);
        return;
    }

    //step 1 go to prev of node to be deleted
    Node* temp = head;
    int count = 1;
    while(temp ->next != NULL && count < pos-1){
        temp = temp->next;
        count += 1;
    }

    if(temp->next->next==NULL){
        Node* save = temp->next;
        temp->next = NULL;
        free(save);
        return;
    }

    Node* save = temp->next->next;
    temp->next->next = NULL;
     free(temp->next);
    temp->next = save;
   
    
}

Node* reverseIterative(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr!=NULL){
        next = curr->next;
        curr->next  = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* reverseRecursive(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* rest = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}


int main(){
    
    Node* head = NULL ;
    Node* tail = NULL;

    insertAtHead(head,tail,1);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);

    insertAtTail(head,tail,55);

    insertAtPos(head,tail,58,3);
    deletion(head,tail,2);
    deletion(head,tail,6);
    print(head);
    cout<<endl;
    Node* reversedList = reverseRecursive(head);
    print(reversedList);

    return  0;


    // question1 -- cycle present in linked list  floyd cycle 
    // question 2 merge sort through linked list
    // question 3 reverse the linked list reursion or two pointer approach 
    // question 4  reverse the linked list in k group 

}
