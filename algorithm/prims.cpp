#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
void prims(vector<vector<pair<int,int>>>&graph, int n){
    vector<int>dist(n+1,INT_MAX),vis(n+1);
    dist[1]=0;
    priority_queue<pair<int,int>>pq;
    pq.push({0,1});
    int total=0;
    while(!pq.empty()){
        pair<int,int>p=pq.top(); pq.pop();
        int node = p.second , cost = -1*p.first;
        if(vis[node])continue;
        vis[node]=1;
        total+=cost;

        for(auto to:graph[node]){
            if(vis[to.first]==0){
                pq.push({-1*to.second,to.first});
            }
        }
    }
    cout<<total<<endl;
}
int main(){
    int n,e,i,j;
    cin>>n>>e;
    vector<vector<pair<int,int>>>graph(n+1);
    for(i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    prims(graph,n);
}