#include<bits/stdc++.h>
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
int countNodes(Node *root){
    //base case 
    if(root == NULL){
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node *root,int index,int totalNodes){
    if(root == NULL){
        return true;
    }
    if(index >= totalNodes){
        return false;
    }

    else{
        bool left = isCBT(root->left,2*index+1,totalNodes);
        bool right = isCBT(root->right,2*index+2,totalNodes);
        return left && right;
    }
}

bool isMaxOrder(Node *root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    if(root->right == NULL){
        return (root->data > root->left->data);
    }
    else{
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);
        return ((left)&&(right)&&(root->data > root->left->data && root->data > root->right->data));
    }
}

int main(){

    Node* root = NULL;
    //building tree
    root = buildTree(root);
    levelOrderTraversal(root);


   int totalNodes = countNodes(root);
   cout<<"total Nodes are "<<totalNodes<<endl;

   if(isCBT(root,0,totalNodes) && isMaxOrder(root)){
        cout<<"this binary tree is a Heap "<<endl;
   }
   else{
        cout<<"this binary tree is not a heap "<<endl;
   }

    return 0;
}