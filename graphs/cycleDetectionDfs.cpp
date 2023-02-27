#include<bits/stdc++.h>
using namespace std;

unordered_map<int,list<int> > adj;
class graph{
    public:
    

    void addEdge(int u,int v,bool direction){
        
    // direction 0 -- undirected 
    //direction 1 -- directed 
      
      adj[u].push_back(v);

      if(direction == 0){
         adj[v].push_back(u);
      }
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

void bfs(unordered_map<int,bool>&visited,int node){

    queue<int> q;
    //step 1 push the node into queue mark the  visited of thee node as true
    q.push(node);
    visited[node] = 1;

    //traverse for the neighbour of the node
    while(!q.empty()){
        int frontNode = q.front();
        cout<<frontNode<<" ";
        q.pop();
        for(auto neighbor:adj[frontNode]){
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
   



}
bool detectCycleDFS(int node,int parent,unordered_map<int,bool> &visited){
    visited[node] = true;

    //traverse for the neigbours of node
    for(auto neighbour:adj[node]){
        //conditions
        if(!visited[neighbour]){
            bool ans=  detectCycleDFS(neighbour,node,visited);
            if(ans){
                return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

int main(){


    int n;
    cout<<"enter number of nodes "<<endl;
    cin>>n;

    int m;
    cout<<"enter number of edges "<<endl;
    cin>>m;

    graph g;

    cout<<"enter connection between nodes "<<endl;
    for(int i = 0; i<m; i++){
        int u,v;
        cin>>u>>v;
        
        g.addEdge(u,v,0);
    

    }

    g.print();

    
    unordered_map<int,bool> visited;
    bool flag = 0;  
     for(int i = 0; i<n; i++){
        if(!visited[i]){
            bool ans = detectCycleDFS(i,-1,visited);
            if(ans){
                cout<<"cycle is present "<<endl;
                flag = 1;
            }
        }
    }

    if(flag == 0){
        cout<<"cycle is not present "<<endl;
    }
   
 
    return 0;
}
