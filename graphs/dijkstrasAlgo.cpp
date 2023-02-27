#include<bits/stdc++.h>
using namespace std;
unordered_map<int,list<pair<int,int > > > adj;
class Graph{
    public:

    void addEdge(int u,int v,int w){
        
        pair<int,int> p = make_pair(v,w);
        adj[u].push_back(p);
        pair<int,int> q = make_pair(u,w);
        adj[v].push_back(q);
    
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


int main(){


    

    Graph g;

    g.addEdge(1,3,2);
    g.addEdge(1,0,5);
    g.addEdge(1,2,9);
    g.addEdge(0,2,8);
    g.addEdge(2,3,6);

    g.print();

    int src = 0;
    int vertices = 4;
    int edges = 5;

    //step 1 create a distance array and a set 

    vector<int> dist(vertices);
    for(int i = 0; i<vertices; i++){
        dist[i] = INT_MAX;
    }
            //(distance , node)
    set<pair<int,int> > s;

    dist[src] = 0;

    s.insert(make_pair(0,src));

    while(!s.empty()){
        //step 1 fetch the top node 
        auto top = *(s.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        //pop the top Node
        s.erase(s.begin());


        //iterate over the neigbour
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                //check if we already have any entry for the same in set
                auto record  = s.find(make_pair(dist[neighbour.first],neighbour.first));
                
                // if entry found
                if(record != s.end()){
                    s.erase(record);
                }

                 //update distance 
                dist[neighbour.first] = nodeDistance+neighbour.second;

                s.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }

    
    }

    //printing the distance vector

    for(auto i:dist){
        cout<<i<<" ";
    }
    cout<<endl;




    return 0;

}
