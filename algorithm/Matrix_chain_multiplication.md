<h3>Algorithm: Matrix Chain Multiplication</h1>

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
int cost[N][N];
void matrixChainMultiplication(vector<int>v){
    int n = v.size(),i,j,k;
    for(int len=1; len<n; len++){
        for(i=1; i<n-len; i++){
            j = i+len;
            cost[i][j]=INT_MAX;
            for(k=i; k<j; k++){
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k+1][j]+v[i-1]*v[k]*v[j]);
            }
        }
    }
}
int main(){
    vector<int>v={1,2,3,4};
    matrixChainMultiplication(v);
    for(int i=1; i<4; i++){
        for(int j=1; j<4; j++){
            cout<<cost[i][j]<<" ";
        }
        cout<<endl;
    }
}
```