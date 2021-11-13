#include <bits/stdc++.h>
using namespace std;
#define X ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FIXED_FLOAT(x) std::fixed <<std::setprecision(2)<<(x)
 
 
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
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
 
// long long p = 1e9+7;
 
typedef long long ll;
typedef pair<ll,ll> pl;
typedef vector<int> VI;
typedef vector<pair<ll,ll>> VP;
typedef vector<ll> VL;
typedef vector<bool> VB;
 
// typedef pair<ll, ll> PL;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b) for(i=0;i<b;i++)
#define pb push_back
#define mp make_pair
 
// typedef  unordered_set<ll>;
 
 
void printa(VI &x,ll n){
    ll i;
    FOR(i, n){
        cout<<x[i]<<" ";
    }
    cout<<endl;
}
 
 
/////GLOABLS VARS
ll MOD = 1e9+7;
ll gmx = 1e5+7; 
VL fact(gmx, 1);
//////FUNCTIONS
// ll pow(ll val, ll deg)
// {
//     if (!deg)
//         return 1 % MOD;
//     if (deg & 1)
//         return pow(val, deg - 1) * val % MOD;
//     ll res = pow(val, deg >> 1);
//     return (res * res) % MOD;
// }
ll powm(ll a, ll p) {
    ll res = 1;
    while(p) {
        if(p & 1) {res = (res * a) % MOD;}
        p /= 2;
        a = (a * a) % MOD;
    }
    return res;
}
ll inv(ll r){
    return powm(r, MOD-2)%MOD;
}
ll nCr(ll n, ll r){
    ll tmp = fact[n-r]*fact[r];
    tmp = tmp%MOD;
    return (fact[n]*inv(tmp))%MOD;
}
ll mx = 2*1e5+7;
vector<VL> adj(mx+1);
VL arr(mx);
vector<unordered_set<ll>> seg(4*mx);
VL update(4*mx);

void createSegTree(ll lf, ll rt, ll pos){
    if(lf==rt){

        seg[pos].insert(arr[lf]);
        // debug(seg[pos], lf);
        return;
    }
    ll mid = lf+(rt-lf)/2;
    createSegTree(lf, mid, 2*pos+1);
    createSegTree(mid+1, rt, 2*pos+2);
    set_union(seg[2*pos+1].begin(), seg[2*pos+1].end(), seg[2*pos+2].begin(), seg[2*pos+2].end(), inserter(seg[pos], seg[pos].begin()));
    // debug(seg[pos], pos);
    return;
};

unordered_set<ll> querySegTree(ll lf, ll rt, ll cur_lf, ll cur_rt, ll pos){
    if(lf<=cur_lf && rt>=cur_rt){
        return seg[pos];
    }
    
    else if(cur_lf>rt || lf>cur_rt){
        unordered_set<ll>tmp;
        return tmp;
    }
    else{
        ll mid = cur_lf+(cur_rt-cur_lf)/2;
        unordered_set<ll>tmp1=querySegTree(lf,rt, cur_lf, mid, 2*pos+1);
        unordered_set<ll>tmp2=querySegTree(lf,rt, mid+1, cur_rt, 2*pos+2);

        set_union(tmp1.begin(), tmp1.end(),tmp2.begin(), tmp2.end(), inserter(tmp1, tmp1.begin())); 
        // debug(seg[pos]);
        return tmp1;
    }
} 

//It is not easy but it can be fun, if you think!!!
int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll i,u,v,j,c; 
    ll n,q;
    cin>>n>>q;
    VL l(n);
    // VL a(n);
    VL req(n);
    FOR(i,n){
        cin>>arr[i];
        // arr[i] = 1;
    }
    VL pre(n);
    unordered_set<ll> dp;
    ll tmp = 0;
    FOR(i,n){
        if(dp.find(arr[i])==dp.end()){
            tmp++;
            dp.insert(arr[i]);
        }
        pre[i] =tmp;

    }

    // createSegTree(0, n-1, 0);
    FOR(i,q){
        ll a,b;
        cin>>a>>b;
        ;
        cout<<tmp.size()<<"\n";
    }
    
    
    
    
    
}