<h2>Orbitax on campus recruitment at CoU</h2>
<hr>
<details>
<summary>Orbitax Feature</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 1e6+5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
class DSU{
    public:
    vi par,sz;
    int n;
    DSU(int _n){
        n=_n;
        par.resize(2*n+1);
        sz.resize(2*n+1);
        for(int i=1; i<=n; i++)par[i]=i+n,par[i+n]=i+n,sz[i+n]=1;
        // cout<<par[1]<<" "<<sz[6]<<endl;
        // print(par);
        // print(sz);
    }
    int Find(int a){
        if(a==par[a])return par[a];
        return par[a] = Find(par[a]);
    }
    void Union(int a, int b){
        a = Find(a);b = Find(b);
        if(a==b)return;
        if(sz[a]>=sz[b]){
            sz[a]+=sz[b];
            par[b]=a;
        }
        else{
            par[a]=b;
            sz[b]+=sz[a];
        }
    }
    void ReUnion(int a, int b){
        b = Find(b);
        sz[Find(a)]--;
        par[a]=b;
        sz[b]++;
    }
    int getSize(int a){
        a = Find(a);
        return sz[a];
    }
};
int main(){
    FIO;
    // file();
    int n,q,i,j; cin>>n>>q;
    DSU obj(n);
    while(q--){
        int tp; cin>>tp;
        if(tp==1){
            int a,b; cin>>a>>b;
            obj.Union(a,b);
        }
        else if(tp==2){
            int a,b; cin>>a>>b;
            obj.ReUnion(a,b);
        }
        else{
            int a; cin>>a;
            cout<<obj.getSize(a)<<endl;
        }
    }
}
hello

```
</details>

<details>
<summary>Prime Mysteries</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 1e6+5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
ll prime_size=1e5;
vi primes;
vector<bool> mark(prime_size+5);
void sieve(){
    ll i,j;
    mark[0]=mark[1]=1;
    for(i=4; i<prime_size; i+=2)mark[i]=1;
    for(i=3; i*i<=prime_size; i+=2){
        if(!mark[i]){
            for(j=i*i; j<=prime_size; j+=i*2)mark[j]=1;
        }
    }
    primes.pb(2);
    for(i=3; i<=prime_size; i+=2)if(!mark[i])primes.pb(i);
}
map<int,ll>cnt_primes;
class g{
    int n;
    vector<pair<ll,set<int>>>nums;
    vi val; vll ans;
    vvi adj;
public:
    g(int n):n(n){
        nums.resize(n+1);
        val.resize(n+1);
        ans.resize(n+1);
        adj.resize(n+1);
    }
    void rd(){
        for(int i=1; i<n; i++){
            int a,b; cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        for(int i=1; i<=n; i++){
            cin>>val[i];
            if(cnt_primes.find(val[i])==cnt_primes.end()){
                int tmp = val[i]; ll ct=0;
                for(auto it:primes){
                    if(it*it>tmp)break;
                    while(tmp%it==0){
                        tmp/=it; ct+=it;
                    }
                }
                if(tmp>1)ct+=tmp;
                cnt_primes[val[i]]=ct;
            }
            nums[i].second.insert(val[i]);
            nums[i].first=cnt_primes[val[i]];
        }
        dfs(1,1);
        for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    int merge(int a, int b){
        if(nums[a].second.size()<nums[b].second.size())swap(a,b);
        for(auto x:nums[b].second){
            if(nums[a].second.count(x))continue;
            nums[a].second.insert(x);
            nums[a].first+=cnt_primes[x];
        }
        nums[b].second.clear();
        nums[b].first=0;
        return a;
    }
    int dfs(int nd, int p){
        int cur = nd;
        for(auto to:adj[nd]){
            if(to!=p){
                int ret = dfs(to,nd);
                cur =  merge(ret,cur);
            }
        }
        ans[nd] = nums[cur].first;
        return cur;
    }

};
int main(){
    FIO;
    // file();
    sieve();
    t_c{
        int n; cin>>n;
        g obj(n);
        obj.rd();
    }
}
```
</details>

<details>
<summary>Alice's journey in Wonderland</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 1e6+5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
int X[]={0,0,1,-1};
int Y[]={-1,1,0,0};
const ll inf = 1e12;
struct dt{
    int x,y,tm,dlr;
    dt(){x=y=tm=dlr=0;}
    dt(int xx, int yy, int tmm, int dlrr){
        x=xx; y=yy; tm=tmm; dlr = dlrr;
    }
    bool operator<(const dt& o)const{
        return tm>o.tm;
    }
};
int main(){
    FIO;
    ll n,m,i,j; cin>>n>>m;
    vvll tm(n+2,vll(m+2)), dlr(n+2,vll(m+2));
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)cin>>tm[i][j];
    }
    // cout<<"=-=--------------------------------"<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=m; j++)cin>>dlr[i][j];
    }
    
    ll d; cin>>d;

    vector<vvll> ans(n+2,vvll(m+2,vll(d+1,inf)));
    for(i=dlr[1][1]; i<=d; i++)
        ans[1][1][i]=tm[1][1];

    queue<pair<pll,pll>>q;
    q.push({{1,1},{dlr[1][1],tm[1][1]}});
    while(!q.empty()){
        pll p = q.front().first;
        pll a = q.front().second;
        // cout<<p.first<<" "<<p.second<<" "<<a.first<<" "<<a.second<<endl;
        q.pop();
        for(i=0; i<4; i++){
            ll x = X[i]+p.first, y = Y[i]+p.second;
            if(0<x and x<=n and 0<y and y<=m){
                if(a.first+dlr[x][y]<=d and ans[x][y][a.first+dlr[x][y]]>a.second+tm[x][y]){
                    ans[x][y][a.first+dlr[x][y]] = a.second+tm[x][y];
                    // cout<<">> "<<x<<" "<<y<<" "<<a.first+dlr[x][y]<<" "<<ans[x][y]<<endl;
                    q.push({{x,y},{a.first+dlr[x][y],ans[x][y][a.first+dlr[x][y]]}});
                }
            }
        }
    }
    ll res=inf;
    for(i=0; i<=d; i++)res = min(res,ans[n][m][i]);
    if(res==inf)res=-1;
    cout<<res<<endl;
    
}

/*

1 2 3 4
4 2 2 1
2 3 4 1
1 2 3 1

1 2 3 4
4 3 2 1
2 3 4 1
1 2 3 1
*/
```
</details>

<details>
<summary>Maximum Score</summary>

```c++
#include<bits/stdc++.h>
using namespace std;
#define lli   int

void solve(lli cases)
{
    lli n, ans=0,j=0;
    string str;
    cin>>n;
    vector<lli>arr(n+1);

    map<char, lli>mp;
    for(lli i=0;i<n;i++)
    {
        lli a;
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for(lli i=0;i<n;i++)
    {
        if(i+1<=arr[i])

        {
            j=i+1;
        }
    }
    cout<<j<<endl;
}
int main()
{

    lli t=1, t_c=1;
    while(t--)
        solve(t_c++);
}
```
</details>

<details>
<summary>DNA Transformation Reloaded</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

#define mod 1000000007
//........constant........///
const ll N = 100005;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
ll mem[30][N];
ll dp(int ch, int rt){
    if(rt==0)return 1;
    ll &ret = mem[ch][rt];
    if(~ret)return ret;

    ret = 0;
    if(ch==25){
        ret = (dp(0,rt-1)+dp(1,rt-1))%mod;
    }
    else ret = dp(ch+1,rt-1);
    return ret%mod;
}
int main(){
    FIO;
    memset(mem,-1,sizeof mem);
    for(int i=0; i<26; i++){
        dp(i,100000);
    }
    string s; cin>>s;
    int y; cin>>y;
    ll n = s.size(),ans=0;
    for(int i=0; i<n; i++){
        ans =(ans+ mem[s[i]-'a'][y])%mod;
    }
    if(ans<0){
        ans%=mod;
        ans=(ans+mod)%mod;
    }
    cout<<ans<<endl;
}
```
</details>

<details>
<summary>Points Table</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 100005;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
string Line(int x){
    string s= "+------+";
    for(int i=0; i<x-2; i++){
        s+="---------+";
    }
    s+="-------+";
    return s;
}
string makeS(string s, int len=4){
    reverse(all(s));
    while(s.size()<len)s+=" ";
    reverse(all(s));
    return s;
}
string makeI(int a, int len=7){
    return makeS(to_string(a),len);
}
int main(){
    FIO;
    int t,r,i,j; cin>>t>>r;
    vector<string>teams(t);
    for(i=0; i<t; i++)cin>>teams[i];
    vvi rounds(r,vi(t));
    for(i=0; i<r; i++){
        for(j=0; j<t; j++)cin>>rounds[i][j];
    }
    for(i=0; i<r; i++){
        cout<<"Point Table After Round "<<i+1<<endl;
        cout<<Line(i+3)<<endl;
        cout<<"| Team |"; for(int ir=0; ir<=i; ir++)cout<<" Round "<<ir+1<<" |";cout<<" Total |"<<endl;
        cout<<Line(i+3)<<endl;
        int mx=0,tms=0;
        for(j=0; j<t; j++){
            cout<<"| "<<makeS(teams[j])<<" |";
            int total=0;
            for(int ir=0; ir<=i; ir++){
                cout<<" "<<makeI(rounds[ir][j])<<" |";
                total += rounds[ir][j];
            }
            if(total>mx){mx=total; tms=j;}
            cout<<" "<<makeI(total,5)<<" |"<<endl;
            cout<<Line(i+3)<<endl;
        }
        cout<<"Top Scorer: "<<teams[tms]<<endl;

    }
}
```
</details>

<details>
<summary>Compression X</summary>

```c++
#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}
#define least_one_pos(x) __builtin_ffs(x)
#define leading_zeros(x) __builtin_clz(x)
#define tailing_zeros(x) __builtin_ctz(x)
#define num_of_one(x) __builtin_popcount(x)
///............x...........///
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define UNIQUE(X) (X).erase(unique(all(X)), (X).end())
#define ft cout << "for test"<<endl;
#define print(v) for (auto it : v)cout << it<<" ";cout << endl;
#define cinv(v) for(auto &it : v)cin>>it;
#define PI acos(-1.0)
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define t_c int test, cs = 1;cin>>test;while (test--)
///................function.....................///

//#define mod 1000000007
//........constant........///
const ll N = 1e6+5;
void file(){
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
}
int main(){
    FIO;
    // file();
    string s; cin>>s;
    map<char,ll>hisab;
    int n = s.size();
    char cur=s[0];
    for(int i=0; i<n; i++){
        if('a'<=s[i] and s[i]<='z'){
            cur=s[i];
        }
        else{
            int val=0;
            while(i<n and '0'<=s[i] and s[i]<='9'){
                val=val*10ll+(s[i]-'0'); i++;
            }
            hisab[cur]+=val;
            i--;
        }
    }
    for(auto x:hisab){
        cout<<x.first<<x.second;
    }
    cout<<endl;
}
```
</details>