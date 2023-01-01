#include <bits/stdc++.h> 
using namespace std;
class node{
    public:
    int data;
    int i;
    int j;
    
    //constructor
    node(int data,int row,int col){
        this->data = data;
        i = row;
        j = col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
   //step 1 create  a min heap of node type
    priority_queue<node* ,vector<node*>, compare> minHeap;
    vector<int> ans;
    
    //step 2 push first element of k arrays
    for(int i = 0; i<k; i++){
        node* temp = new node(kArrays[i][0],i,0);
        minHeap.push(temp);
    }
    
    //step3 store the top in ans and push the next element of the same if present

    while(minHeap.size()>0){
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();
        
        int i = tmp->i;
        int j = tmp->j;
        
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1] ,i, j+1);
            minHeap.push(next);
            
        }
    }
    
    return ans;
}
