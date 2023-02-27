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


int main(){


    int n;
    cout<<"enter number of nodes "<<endl;
    cin>>n;

    int m;
    cout<<"enter number of edges "<<endl;
    cin>>m;

    graph g;

    cout<<"enter connection between nodes "<<endl;
    for(int i = 1; i<=m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,1);

    }

    g.print();

    //step 1 find indegree of all nodes 
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    //step 2 push the all nodes with indegree 0 into queue
    queue<int> q;
    for(int i = 1; i<=n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    // step 3 do Bfs 
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //step 4 print the answer
        cout<<frontNode<<" ";

        //traverse neighbours of frontNode and update indegree
        for(auto neighbour:adj[frontNode]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    
  

    

    return 0;
}