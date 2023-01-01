#include<bits/stdc++.h>
using namespace std;
unordered_map<int,list<int> > adj;
class Graph{
    public:
    
   

    void addEdge(int u,int v){
        
        adj[u].push_back(v);
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

bool DirectedCycleDetection(int node,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited){

    visited[node] = true;
    dfsVisited[node] = true;

    //traverse the neighbours recursively
    for(auto neighbour:adj[node]){
        //conditions 
        if(!visited[neighbour]){
            bool isCyclePresent = DirectedCycleDetection(neighbour,visited,dfsVisited);
            if(isCyclePresent){
                return true;
            }
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int main(){


    int n ;
    cout<<"enter the no. of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"enter the no. of edges"<<endl;
    cin>>m;

    Graph g;
    cout<<"enter the connection between nodes "<<endl;

    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }


    g.print();

    //creating needed Data structures 
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsVisited;
    bool flag = 0;
    for(int i = 1; i<=n; i++){
    
        if(!visited[i]){
            bool ans = DirectedCycleDetection(i,visited,dfsVisited);
            if(ans == true){
                cout<<"cycle is Present "<<endl;
                flag = 1;
            }
        }

    }
    if(flag == 0){
        cout<<"cycle is not present "<<endl;
    }


    return 0;
}