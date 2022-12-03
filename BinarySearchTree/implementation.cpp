#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    //constructor 
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* insertIntoBST(Node* root,int data){
    //base case
    if(root == NULL){
        root = new Node(data);
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
void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
}
void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // separator

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}
bool searchInBST(Node* root,int x){
    //base cases
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }


    if(root -> data > x){
        return searchInBST(root->left,x);
    }
    else{
        return searchInBST(root->right,x);
    }
}
int main(){

    Node* root = NULL;
    

    cout<<"enter input data "<<endl;

    takeInput(root);
    cout<<"printing the tree "<<endl;
    levelOrderTraversal(root);
    cout<<endl;


    cout<<searchInBST(root,21)<<endl;


    return 0;
}