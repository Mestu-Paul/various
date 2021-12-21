#include<bits/stdc++.h>
using namespace std;
int n,done=0,mod;
vector<vector<int>>solution;
vector<int>l_dim,r_dim,row,col;
bool nQn(int c){
    if(c>n){
        
        for(int i=1; i<=n; i++)
        {for(int j=1; j<=n; j++)cout<<solution[i][j]<<" ";cout<<endl;}
        cout<<endl;
        return true;
    }
    for(int i=1; i<=n; i++){
        int left_dim = (i-c+mod)%mod;
        int right_dim = (i+c);
        if(l_dim[left_dim] or r_dim[right_dim] or row[i] or col[c])continue;
        l_dim[left_dim]=r_dim[right_dim]=row[i]=col[c]=1;
        solution[i][c]=1;
        if(nQn(c+1)){
            return true;
        }
        l_dim[left_dim]=r_dim[right_dim]=row[i]=col[c]=0;
        solution[i][c]=0;
    }
    return false;

}
int main(){
    int i,j;
    cin>>n;
    mod=n*2;
    solution.resize(n+1,vector<int>(n+1));
    l_dim.resize(3*n);
    r_dim.resize(3*n);
    row.resize(n+1);
    col.resize(n+1);
    nQn(1);
    for(i=1; i<=n; i++)
        {for(j=1; j<=n; j++)cout<<solution[i][j]<<" ";cout<<endl;}
}

