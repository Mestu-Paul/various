<h3>Kruskal algorithm</h3>

```c++
#include<bits/stdc++.h>
using namespace std;
#define Max 100
struct tp{
    int source,dest;
    int weight;
};
int parent[Max];
int Size[Max];
bool cmp(tp a, tp b){
    return a.weight<=b.weight;
}
void Set(int n){
    for(int i=1; i<=n; i++){
        parent[i]=i;
        Size[i]=1;
    }
}
int find(int a){
    if(a==parent[a])return a;
    return parent[a]=find(parent[a]);
}
void Union(int a, int b){
    if(Size[a]<=Size[b]){
        parent[b]=a;
        Size[a]+=Size[b];
    }
    else{
        parent[a]=b;
        Size[b]+=Size[a];
    }
}
void kruskal(vector<tp>&edge){
    sort(edge.begin(),edge.end(),cmp);
    int total=0;
    for(auto to:edge){
        int u = to.source,v=to.dest,w=to.weight;
        int par_u = find(u);
        int par_v = find(v);
        if(par_u!=par_v){
            total+=w;
            cout<<u<<" "<<v<<" with cost "<<w<<endl;
            Union(par_u,par_v);
        }
    }
    cout<<"total "<<total<<endl;
}
int main(){
    int n,e;
    cin>>n>>e;
    vector<tp>edge(e);
    int u,v,w;
    for(int i=0; i<e; i++){
        cin>>u>>v>>w;
        edge[i].source=u;
        edge[i].dest=v;
        edge[i].weight=w;
    }
    Set(n);
    kruskal(edge);
}
```


<b>sample input:</b></br>
7 9</br>
1 2 28</br>
2 3 16</br>
3 4 12</br>
4 5 22</br>
5 6 25</br>
1 6 10</br>
5 7 24</br>
7 2 14</br>
4 7 18</br>
</br>
<b>sample output:</b></br>
1 6 with cost 10</br>
3 4 with cost 12</br>
7 2 with cost 14</br>
2 3 with cost 16</br>
4 5 with cost 22</br>
5 6 with cost 25</br>
total 99