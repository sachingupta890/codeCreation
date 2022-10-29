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


Node* buildTree(Node* root){
    cout<<"enter data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }


    //building tree recursively

    cout<<"enter data for the left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for the right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
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
void inorder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    //left call 
    inorder(root->left);
    //printing node
    cout<<root->data<<" ";
    //right call
    inorder(root->right);
}
int main(){
    Node* root = NULL;
    //building tree

   
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1  5 17 -1 -1 -1 
    cout<<"printing the binary tree "<<endl;

    levelOrderTraversal(root);


    cout<<"printing the inorder traversal"<<endl;
    inorder(root);

    return 0;
}