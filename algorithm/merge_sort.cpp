#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
void merge(vector<int>&v, int l, int mid, int r){
    int i=l,j=mid+1;
    vector<int>tmp;
    while(i<=mid and j<=r){
        if(v[i]<=v[j]){
            tmp.push_back(v[i]);
            i++;
        }
        else{
            tmp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid)tmp.push_back(v[i]),i++;
    while(j<=r)tmp.push_back(v[j]),j++;
    for(i=l,j=0; i<=r; i++,j++){
        v[i]=tmp[j];
    }
}
void merge_sort(vector<int>&v, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        merge_sort(v,l,mid);
        merge_sort(v,mid+1,r);
        merge(v,l,mid,r);
    }
}
int main(){
    vector<int>v={5,4,3,2,1};
    int n = v.size();
    merge_sort(v,0,n-1);
    for(int i=0; i<n; i++)cout<<v[i]<<" ";
    cout<<endl;
}