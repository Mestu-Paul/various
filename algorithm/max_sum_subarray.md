<h3>1. Maximum sum subarray without solution array</br>
2. Maximum sum subarray with solution array
</h3>

1.
```c++
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
int cross_max_sum(vector<int>&v, int l, int mid, int r){
    int left_sum=0,left_max=INT_MIN;
    int right_sum=0,right_max=INT_MIN;
    int i,j;
    for(i=mid; i>=l; i--){
        left_sum+=v[i];
        left_max = max(left_max,left_sum);
    }
    for(i=mid+1; i<=r; i++){
        right_sum+=v[i];
        right_max = max(right_max,right_sum);
    }
    return max({left_max+right_max, right_max,left_max});
}
int max_sum_subarray(vector<int>&v, int l, int r){
    if(l==r){
        return v[l];
    }
    int mid = (l+r)/2;
    int left_sum = max_sum_subarray(v,l,mid);
    int right_sum = max_sum_subarray(v,mid+1,r);
    int cross_sum = cross_max_sum(v,l,mid,r);
    return max({left_sum,right_sum,cross_sum});
}
int main(){
    vector<int>v={1,-2,2,-5,4,6-3,4,5};
    int n = v.size();
    cout<<max_sum_subarray(v,0,n-1)<<endl;
}
```

2.

```c++
#include<bits/stdc++.h>
#include<time.h>
using namespace std;
#define print(v) for(auto it:v)cout<<it<<" ";cout<<endl;
const int N=4;
struct tp{
    int l,r;
    int sum=0;
};
tp cross_max_sum(vector<int>&v, int l, int mid, int r){
    int left_sum=0,right_sum=0;
    int left_max=INT_MIN, right_max=INT_MIN;
    int i,j,lft_pos=-1,rgt_pos=-1;
    for(i=mid; i>=l; i--){
        left_sum+=v[i];
        if(left_sum>left_max){
            left_max=left_sum;
            lft_pos=i;
        }
    }
    for(i=mid+1; i<=r; i++){
        right_sum+=v[i];
        if(right_max<right_sum){
            rgt_pos=i;
            right_max=right_sum;
        }
    }
    if(right_max+left_max>right_max and right_max+left_max>left_max){
        tp tmp;tmp.l=lft_pos,tmp.r=rgt_pos,tmp.sum=right_max+left_max;
        return tmp;
    }
    else if(left_max>right_max){
        tp tmp;tmp.l=lft_pos,tmp.r=mid,tmp.sum=left_max;
        return tmp;
    }
    else{
        tp tmp;tmp.l=mid+1,tmp.r=r,tmp.sum=right_max;
        return tmp;
    }
}
tp max_sum_subarray(vector<int>&v, int l, int r){
    tp tmp;
    if(l==r){
        tmp.l=l,tmp.r=r,tmp.sum=v[l];
        return tmp;
    }
    int mid = (l+r)/2;
    tp left_sum = max_sum_subarray(v,l,mid);
    tp right_sum = max_sum_subarray(v,mid+1,r);
    tp cross_sum = cross_max_sum(v,l,mid,r);
    if(left_sum.sum>right_sum.sum and left_sum.sum>cross_sum.sum){
        return left_sum;
    }
    else if(right_sum.sum>cross_sum.sum){
        return right_sum;
    }
    else return cross_sum;
}
int main(){
    vector<int>v={1,-2,2,-5,4,6,-3,4,5};
    int n = v.size();
    tp tmp = max_sum_subarray(v,0,n-1);
    cout<<tmp.sum<<endl;
    for(int i=tmp.l; i<=tmp.r; i++)cout<<v[i]<<" ";
    cout<<endl;
}
```