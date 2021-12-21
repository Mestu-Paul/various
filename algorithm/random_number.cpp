#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int main(){
	srand(time(0));
	cout<<"50 randoms number (50-100):"<<endl;
	vector<int>v;
	for(int i=0; i<50; i++){
		int tmp = rand()%101;
		if(tmp<50)tmp+=50;
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	for(auto it:v)cout<<it<<" ";
	cout<<endl;
}