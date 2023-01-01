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

void topoSort(int node,unordered_map<int,bool>&visited,stack<int>&s){
    visited[node] = true;

    //traverse for the neigbour recursively
    for(auto i:adj[node]){
        if(!visited[i]){
            topoSort(i,visited,s);
        }
    }
    s.push(node);
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
        g.addEdge(u,v,1);

    }

    g.print();
    

    unordered_map<int,bool> visited;
    stack<int> s;
    vector<int> ans;
    for(int i = 1; i<=n; i++){
        if(!visited[i]){
            topoSort(i,visited,s);
        }
    }

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
  

    

    return 0;
}