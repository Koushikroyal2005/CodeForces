// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<bits/stdc++.h>

#define  FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define IOtext freopen("input.txt","r",stdin); freopen("output1.txt","w",stdout);
//mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

using namespace std;
using namespace __gnu_pbds;

#define mod 1000000007 //1e9+7
#define pb push_back
#define ppb pop_back
#define endl "\n"
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
#define SUM(x) accumulate(all(x), 0LL)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define YES cout<<"YES"<<"\n"
#define NO cout<<"NO"<<"\n"
#define int1(t) ll t;cin>>t
#define int2(a,b) ll a,b;cin>>a>>b
#define int3(a,b,c) ll a,b,c;cin>>a>>b>>c
#define int4(a,b,c,d) ll a,b,c,d;cin>>a>>b>>c>>d
#define int5(a,b,c,d,e) ll a,b,c,d,e;cin>>a>>b>>c>>d>>e
#define int6(a,b,c,d,e,f) ll a,b,c,d,e,f;cin>>a>>b>>c>>d>>e>>f
#define string1(a) string a;cin>>a
#define string2(a,b) string a,b;cin>>a>>b
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)), min((c),(d)))
#define f(i,n) for(ll i=0;i<n;i++)
#define f(i,a,b) for(ll i=a;i<b;i++)
#define fr(i,n)  for(ll i=n-1;i>=0;i--)
#define fr(i,b,a) for(ll i=b;i>=a;i--)

typedef long long ll;
//typedef int ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<char, int> mci;
typedef set<int> st;

// constants
const ll dx[] = {-1,0,0,1};
const ll dy[] = {0,-1,1,0};

// INPUTS
#define inarr(arr,n) ll arr[n]; for(ll i=0;i<n;i++){cin>>arr[i];}
#define invec(arr,n) vector<ll>arr(n); for(ll i=0;i<n;i++){cin>>arr[i];}
#define invecvec(arr,n,m) vector<vector<ll>>arr(n,vector<ll>(m,0)); for(ll i=0;i<n;i++){for(ll j=0;j<m;j++){cin>>arr[i][j];}}
#define invecpair(arr,n) vector<pair<ll,ll>>arr(n) for(ll i=0;i<n;i++){cin>>arr[i].first; cin>>arr[i].second;}

//DEBUGGING OUTPUTS:
#define outarr(arr) for(ll i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){ cout << arr[i] << " ";}cout << endl;
#define outvec(v) for(ll i=0;i<v.size();i++){ cout << v[i] << " ";}cout << endl;
#define outmap(m) for(auto i: m){ cout << i.f << " " << i.sec << endl;}
#define outvecvec(v) for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout << v[i][j] << " ";}cout << endl;}
#define outvecpair(v) for(ll i=0;i<v.size();i++){cout << v[i].first << " " << v[i].second << endl;}
#define outset(s) for(auto i : s){cout << i << " ";}cout<<endl;

//DEBUGGING ON CONSOLE ERROR
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print(x); cerr<<endl;
#else
#define debug(x)
#endif

// disjoinset
class disjointset{
public:
   vector<ll>rank,parent,size;
    disjointset(ll n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(ll i=0;i<n;i++){
            parent[i]=i;
        }
    }
    ll finduparent(ll node){
        if(parent[node]==node) return node;
        return parent[node]=finduparent(parent[node]);
    }
    void unionbyrank(ll u,ll v){
        ll pu=finduparent(u);
        ll pv=finduparent(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pv;
        }
        else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
    void unionbysize(ll u,ll v){
        ll pu=finduparent(u);
        ll pv=finduparent(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

// segement tree
class segmentTree{
public:
    vector<ll>seg;
    segmentTree(ll n){
        seg.resize(4*n + 1LL);
    }
    void build(ll ind,ll low,ll high,vector<ll>&arr){
        if(low==high){
            seg[ind]=arr[low];
            return;
        }
        ll mid=(low+high)>>1;
        build(2*ind +1,low,mid,arr);
        build(2*ind +2,mid+1,high,arr);
        seg[ind]=min(seg[2*ind +1],seg[2*ind +2]);
    }
    ll query(ll ind,ll low,ll high,ll l,ll r){
        // nooverlap
        if(r<low || l>high) return INT_MAX;
        // complete overlap
        if(low>=l && high<=r) return seg[ind];
        // partial overlap
        ll mid=(low+high)>>1;
        ll left=query(2*ind +1,low,mid,l,r);
        ll right=query(2*ind+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(ll ind,ll low,ll high,ll i,ll val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        ll mid=(low+high)>>1;
        if(i<=mid) update(2*ind +1,low,mid,i,val);
        else update(2*ind +2,mid+1,high,i,val);
        seg[ind]=min(seg[2*ind +1],seg[2*ind +2]);
    }
};

// fenwick tree
class fenwickTree{
public:
    vector<ll>bit;
    ll n;
    fenwickTree(ll n){
        this->n=n;
        bit.assign(n,0);
    }
    fenwickTree(vector<ll>&arr) : fenwickTree(arr.size()){
        for(size_t i=0;i<arr.size();i++){
            // add(i,arr[i])  // this takes O(nlogn) time
            bit[i]+=arr[i];   // this takes O(logn) time
            ll r= i|(i+1);
            if(r<n) bit[r]+=bit[i];
        }
    }
    ll sum(ll r){ // computes sum from 0 to r
        ll ans=0;
        for( ;r>=0;r=(r&(r+1))-1){ // also... r-=(r&-r)
            ans+=bit[r];
        }
        return ans;
    }
    ll sum(ll l,ll r){ // computes sum from l to r
        return sum(r)-sum(l-1);
    }
    ll getmin(ll r){
        ll ans=-1e9;
        for( ;r>=0;r=(r&(r+1))-1){
            ans=min(ans,bit[r]);
        }
        return ans;
    }
    void add(ll ind,ll delta){
        for( ;ind<n;ind=ind|(ind+1)){   // also.. ind += (ind&-ind)
            bit[ind]+=delta;  // adding delta case
            // bit[ind]=min(bit[ind],delta)  // find min case
        }
    }
};

//Bits
string decToBinary(int n) {string s = ""; int i = 0; while (n > 0) {s = to_string(n % 2) + s; n = n / 2; i++;} return s;}
ll binaryToDecimal(string n) {string num = n; ll dec_value = 0; int base = 1; int len = num.length(); for (int i = len - 1; i >= 0; i--) {if (num[i] == '1')dec_value += base; base = base * 2;} return dec_value;}

//Check
bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(int n) {if (n == 0)return false; return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}

//algos
ll maxSubArraySum(vector<ll>&arr){int n=arr.size(); ll maxi=LONG_MIN; ll sum=0; for(int i=0;i<n;i++){sum+=arr[i]; if(sum>maxi){maxi=sum;} if(sum<0){sum=0;}} return maxi;}

//factorial
ll fact(int n){
	if(n==0) return 0;
	ll ans=1;
	for(ll i=2;i<=n;i++){
		ans*=i;
	}
	return ans;
}

/* 
    1. Think Greedy
    2. Think Brute Force
    3. Think solution in reverse order
    4. Think DP [ check constraints carefully ]
    5. Check base cases for DP and prove solution for Greedy
    6. Think Graph 
    7. ceil a/b=(a+b-1)/b do remember
    8. Take care while converting double/float to integers!!! Add some small double number before conversion!!
       throws precision errors!
    9. Remember to convert size() to int!! Causes crazy errors!
    10. XOR is invertible to itself.
    11.If x = a mod b then a mod 2b = x or x+a
    12. (a+b)modc = (a+b-c)modc
*/ 

// solution
void solve(){
    int1(n);
    invec(arr,n);
    for(ll i=1;i<n;i++){
        if(abs(arr[i]-arr[i-1])<=1){
            cout<<0<<endl;
            return;
        }
    }
    for(ll i=1;i<n-1;i++){
        if((arr[i-1]<arr[i] && arr[i]>arr[i+1]) || (arr[i-1]>arr[i] && arr[i]<arr[i+1])){
            cout<<1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}

int32_t main(){
    FastIO
#ifndef ONLINE_JUDGE
	IOtext
	freopen("Error.txt", "w", stderr);
#endif
    int1(t);
    while(t--){
       solve();
    }
   return 0;
}
