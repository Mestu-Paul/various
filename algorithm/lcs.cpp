#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
void lcs(string a, string b){
    int n=a.size(),m=b.size(),i,j;
    int dp[n+1][m+1],parent[n+1][m+1];
    memset(dp,0,sizeof dp);
    memset(parent,0,sizeof parent);
    int up=1,left=2,upleft=3;
    for(i=0; i<n; i++){
        for(j=0 ; j<m; j++){
            if(a[i]==b[j]){
                dp[i+1][j+1]=dp[i][j]+1;
                parent[i+1][j+1]=upleft;
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                    dp[i+1][j+1]=dp[i][j+1];
                    parent[i+1][j+1]=up;
            }
            else{
                dp[i+1][j+1]=dp[i+1][j];
                parent[i+1][j+1]=left;
            }
        }
    }
    string s;
    i=n,j=m;
    while(i>0 and j>0){
        if(parent[i][j]==upleft){
            s+=b[j-1];i--,j--;
        }
        else if(parent[i][j]==up){
            i--;
        }
        else j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main(){
    lcs("strong","strenstrong");
}