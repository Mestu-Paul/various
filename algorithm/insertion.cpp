#include<bits/stdc++.h>
using namespace std; 
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
void insertion_sort(vector<int>&v){
    int i,j,n=v.size();
    for(i=1; i<n; i++){
        int key = v[i];
        j = i-1;
        while(j>=0 and v[j]>key) {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
}
int main(){
    vector<int>v={1,2,3,4,5};
    
        insertion_sort(v);
        
            print(v);
}