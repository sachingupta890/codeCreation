#include<bits/stdc++.h>
using namespace std;
unordered_map<int,list<pair<int,int > > > adj;
class Graph{
    public:

    void addEdge(int u,int v,int w){
        
        pair<int,int> p = make_pair(v,w);
        adj[u].push_back(p);
    }

    void print(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<endl;
        }
    }
};

void topoSort(unordered_map<int,bool>&vis ,int node,stack<int>&stack){
    vis[node] = true;

    for(auto i:adj[node]){
        if(!vis[i.first]){
            topoSort(vis,i.first,stack);
        }
    }
    stack.push(node);
}
int main(){


    

    Graph g;

    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
  
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
     g.addEdge(2,3,7);
    g.addEdge(2,4,4);
   
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);
    

    g.print();

    int src = 1;

    //find toposort 
    stack<int> s;
    unordered_map<int,bool> visited;
    int n = 6;

    if(!visited[0]){
        topoSort(visited,0,s);
    }

    vector<int> distance(n);

    //step 2 create distance array and initialize all value with INT_MAX
    for(int i = 0; i<n; i++){
        distance[i] = INT_MAX;
    }

    //step 3 
    distance[src] = 0;

    // step 4 traverse through the topoSort and update distance array

    while(!s.empty()){
        int top = s.top();
        s.pop();
        if(distance[top] != INT_MAX){
        for(auto i:adj[top]){
            if(distance[top] + i.second < distance[i.first]){
                distance[i.first] = distance[top] + i.second;
            }
        }
        }
    }

    //print the distance array
    for(int i = 0; i<n; i++){
        cout<<distance[i]<<" ";
    }
    cout<<endl;
}