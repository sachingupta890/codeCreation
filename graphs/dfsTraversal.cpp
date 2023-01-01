#include<bits/stdc++.h>
using namespace std;

map<int,list<int> > adj;
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

void dfs(unordered_map<int,bool>&visited,int node){
    //step 1 mark visited of the node true
    visited[node] = true;
    //step 2 print the node
    cout<<node<<" ";

    // step 3 call Recursively for the neighbour  of the node

    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(visited,i);
        }
    }

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
 
    if(!visited[0]){
        dfs(visited,0);
    }
 
    return 0;
}
