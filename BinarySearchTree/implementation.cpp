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
Node* minVal(Node* root){
  

    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}
Node* maxVal(Node* root){

    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

Node* deletion(Node* root,int val){
    
    if(root == NULL){
        return root;
    }

    if(root->data==val){


        //1 No child 
        if(root -> left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child 

        //only left child 
        if(root ->left != NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root -> left == NULL && root->right !=NULL){
            Node* temp = root -> right ;
            delete root;
            return temp;
        }

        //2 child 
        if(root->left != NULL && root->right !=NULL){
            //taking minimum from right
            int mini;

            mini  = minVal(root->right) -> data;
            root->data = mini;
            root->right = deletion(root->right,mini);
            return root;
        }

    }
    else if(root->data > val){
        root->left = deletion(root->left,val);
        return root;
    }
    else{
        root->right = deletion(root->right,val);
        return root;
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

    cout<<"minimum val in the BST is "<<minVal(root)->data<<endl;
    cout<<"maximum val in the BST is "<<maxVal(root)->data<<endl;

    cout<<endl;


    //deletion 

    deletion(root,90);
    
    cout<<"printing the tree "<<endl;
    levelOrderTraversal(root);
    cout<<endl;




    return 0;
}