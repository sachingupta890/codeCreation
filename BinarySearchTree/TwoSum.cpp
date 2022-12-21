#include<iostream>
#include<vector>
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


void solve(Node* root,vector<int>&ans){
    //base case
    if(root == NULL){
        return;
    }

    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

bool TwoSum(Node* root,int target){
    vector<int> inorder;
    solve(root,inorder);

    int i = 0;
    int j = inorder.size()-1;
    while(i<j){
        int sum = inorder[i] + inorder[j];
        if(sum == target){
            return true;
        }

        else if(sum < target){
            i++;
        }
        else{
            j--;
        }

    }
    return false;
}

int main(){

    Node* root = NULL;
    

    cout<<"enter input data "<<endl;

    takeInput(root);
    cout<<"printing the tree "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    int target = 20;
    cout<<"hey its me "<<endl;
    if(TwoSum(root,target)){
        cout<<"it is  a Two sum tree "<<endl;
    }
    else{
        cout<<"it is not a Two sum tree"<<endl;
    }
    cout<<endl;




    return 0;
}