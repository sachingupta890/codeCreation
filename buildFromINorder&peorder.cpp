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
  int findPosition(int in[],int element ,int n){
        
        for(int i = 0; i<n; i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
        //base case
        if(index >= n || inorderStart>inorderEnd){
            return NULL;
        }
        
        //step 1
        int element = pre[index++];
        Node* root = new Node(element);
        int pos = findPosition(in,element,n);
        
        root->left = solve(in,pre,index,inorderStart,pos-1,n);
        root->right = solve(in,pre,index,pos+1,inorderEnd,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex = 0;
        Node* ans = solve(in,pre,preIndex,0,n-1,n);
        return ans;
    }
   

int main(){



    return 0;
}