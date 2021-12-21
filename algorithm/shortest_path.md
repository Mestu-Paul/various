<h3>Shortest Path<h3>

1. Dijkstra 

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
int main(){
    int node_number,edge_number;
    cin>>node_number>>edge_number;
    vector<vector<pair<int,int>>>graph(node_number+1);
    int u,v,w;
    for(int i=0; i<edge_number; i++){
        cout<<i<<" "<<edge_number<<endl;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<int>dist(node_number+1,INT_MAX);
    dist[1]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        pair<int,int>top = pq.top();    pq.pop();
        int cost = -1*top.first , node = top.second;

        for(auto to:graph[node]){
            if(dist[to.first]>cost+to.second){
                dist[to.first] = cost+to.second;
                pq.push({-1*dist[to.first],to.first});
            }
        }
    }
    cout<<dist[node_number]<<endl;
}
```