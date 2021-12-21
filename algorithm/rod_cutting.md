<h3>1. Rod cutting only for getting total profit</h3>
<h3>2. Rod cutting with vector solution</h3>

1.

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
int cutRod(vector<int>&price, int n){
    vector<int>profit(n+1);
    profit[0]=0;
    int i,j;
    for(i=1; i<=n; i++){
        int max_val=INT_MIN;
        for(j=0; j<i; j++){
            max_val = max(max_val,price[j]+profit[i-j-1]);
        }
        profit[i]=max_val;
    }
    return profit[n];
}
int main(){
    vector<int>price={2, 5, 3, 9, 19, 17, 17, 20};
    int n = price.size();
    cout<<cutRod(price,n)<<endl;
}
```

2.

```c++
#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
int cutRod(vector<int>&price, int n){
    vector<int>profit(n+1),parent(n+1);
    profit[0]=0;
    int i,j;
    for(i=1; i<=n; i++){
        int max_val=INT_MIN;
        int par=0;
        for(j=0; j<i; j++){
            if(max_val<price[j]+profit[i-j-1]){
                max_val=price[j]+profit[i-j-1];
                par=i-j-1;
            }
        }
        profit[i]=max_val;
        parent[i]=par;
    }
    i=n;
    vector<int>solution;
    while(i>0){
        solution.push_back(i-parent[i]);
        i=parent[i];
    }
    cout<<"vector solution(index 1 based): ";
    for(auto it:solution)cout<<it<<" ";cout<<endl;
    return profit[n];
}
int main(){
    vector<int>price={2, 5, 3, 9, 19, 17, 17, 20};
    int n = price.size();
    cout<<cutRod(price,n);
}
```