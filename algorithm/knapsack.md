<h3>1. Knapsack without vector solution</br>
2. Knapsack with vector solution</h3>

1.

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
int knapSack(vector<int>&weight, vector<int>&val, int w, int n){
    int profit[n+1][w+1];
    int i,j,k;
    for(i=0; i<=n; i++){
        for(j=0; j<=w; j++){
            if(i==0 or j==0){
                profit[i][j]=0;
            }
            else if(weight[i-1]<=j){
                profit[i][j] = max(profit[i-1][j],val[i-1]+profit[i-1][j-weight[i-1]]);
            }
            else{
                profit[i][j]=profit[i-1][j];
            }
        }
    }
    return profit[n][w];
}
int main(){
    vector<int>val= { 100, 90, 120 };
    vector<int>weight={ 10, 20, 30 };
    int w = 50,n=val.size();
    cout<<knapSack(weight,val,w,n)<<endl;
}
```

2.

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
void knapSack(vector<int>&weight, vector<int>&val, int w, int n){
    int profit[n+1][w+1],b[n+1][w+1];
    memset(b,-1,sizeof b);
    int i,j,k,upleft=1,up=3;
    for(i=0; i<=n; i++){
        for(j=0; j<=w; j++){
            if(i==0 or j==0){
                profit[i][j]=0;
            }
            else if(weight[i-1]<=j){
                if(profit[i-1][j]>val[i-1]+profit[i-1][j-weight[i-1]]){
                    profit[i][j]=profit[i-1][j];
                    b[i][j]=up;
                }
                else{
                    profit[i][j]=val[i-1]+profit[i-1][j-weight[i-1]];
                    b[i][j]=upleft;
                }
            }
            else{
                profit[i][j]=profit[i-1][j];
                b[i][j]=up;
            }
        }
    }
    cout<<profit[n][w]<<endl;
    vector<int>solution;
    i=n,j=w;
    while(i>0 and j>0){
        if(b[i][j]==upleft){
            solution.push_back(i);
            j=j-weight[i-1];i--;
        }
        else{
            i--;
        }
    }
    print(solution);
}
int main(){
    vector<int>val= { 100, 90, 120 };
    vector<int>weight={ 10, 20, 30 };
    int w = 50,n=val.size();
    knapSack(weight,val,w,n);
}
```