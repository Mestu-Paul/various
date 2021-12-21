#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
void heapify(vector<int>&v, int n, int i){

    int largest=i;
    int lft = i*2+1;
    int rgt = i*2+2;

    if(lft<n and v[lft]>v[largest])
        largest=lft;
    
    if(rgt<n and v[rgt]>v[largest])
        largest=rgt;

    if(largest!=i){
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }
}
void heapsort(vector<int>&v, int n){

    for(int i=n/2-1; i>=0; i--){
        heapify(v,n,i);
    }

    for(int i=n-1; i>=0; i--){
        swap(v[0],v[i]);
        heapify(v,i,0);
    }

}
int main(){
    vector<int>v={8,7,3,4,5,6},tmp;
    int n = v.size();
    heapsort(v,n);
    print(v);
}