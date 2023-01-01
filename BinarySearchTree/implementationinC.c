#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*left;
    struct Node* right;

};
struct Node* newNode(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* insertIntoBST(struct Node* root,int data){
    //base case
    if(root == NULL){
        root = newNode(data);
        return root;
    }

    if(data < root->data){
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}
void takeInput(struct Node* root){
    int data;
    scanf("%d",&data);

    while(data != -1){
        root = insertIntoBST(root,data);
        scanf("&d",&data);
    }
}

int main(){

    struct Node* root = NULL;
    printf("enter data to insert\n");
    takeInput(root);



}