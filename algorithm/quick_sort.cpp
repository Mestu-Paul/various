#include<bits/stdc++.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;

int point(vector<int>&v, int l, int r){
    int pivot = v[l];
    int i=l,j=r;
    while(i<j){
        while(v[i]<=pivot)i++;
        while(v[j]>pivot)j--;
        if(i<j)
            swap(v[i],v[j]);
    }
    swap(v[l],v[j]);
    return j;
}
void quickSort(vector<int>&v, int l, int r){
    if(l<r){
        int x = point(v,l,r);
        quickSort(v,l,x-1);
        quickSort(v,x+1,r);
    }
}
int main(){
    vector<int>v={1,2,3,4};
    int n = v.size();
    quickSort(v,0,n-1);
    for(int i=0; i<n; i++)cout<<v[i]<<" ";
    cout<<endl;
}