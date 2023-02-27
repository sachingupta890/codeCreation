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

vector<int> ShortestPathBFS(unordered_map<int,bool> &visited,int src,int dest){
    //step 1 Do BFS and store parent of each node 
    queue<int> q;
    unordered_map<int,int> parent;
    parent[src]  = -1;
    q.push(src);
    visited[src] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //traverse for the neighbour 
        for(auto neighbour: adj[frontNode]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }

    // travrese from destination to source through parents and storing in ans vector
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest);

    while(currNode != src){
        currNode = parent[currNode];
        ans.push_back(currNode);

    }

    //reverse the ans
    reverse(ans.begin(),ans.end());
    return ans;


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

    cout<<"printing the adjacency list "<<endl;
    g.print();

    unordered_map<int,bool> visited;

    vector<int> ans = ShortestPathBFS(visited,1,8);
    
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;


    
  

    

    return 0;
}