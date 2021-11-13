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

//It is not easy but it can be fun, if you think!!!

//
ll mx = 1e5+7;
ll n,m;
vector<VL> adj(mx);
vector<VL>rev_adj(mx);
VL fwd_stack;
VL ans(mx, -1);
VL visited(mx,0);

void fwd_dfs(ll i, ll parent){
    // debug(i, parent);
    if(visited[i]==1){
        return;
    }
    visited[i]=1;
    for(auto nb: adj[i]){
        if(nb==parent){continue;}
        if(visited[nb]==1){continue;}
        fwd_dfs(nb, i);
    }
    
    fwd_stack.pb(i);
    return;
}

void rev_dfs(ll ct, ll i, ll parent){
    // debug(i, parent);
    if(ans[i]!=-1){
        return;
    }
    ans[i] = ct;
    for(auto nb: rev_adj[i]){
        if(nb==parent || ans[nb]!=-1){continue;}
        rev_dfs(ct, nb, i);
    }
    return;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll i,u,v,j,c;
    cin>>n>>m;
    FOR(i,m){
        ll u,v;
        cin>>u>>v;
        adj[u].pb(v);
        rev_adj[v].pb(u);
    }
    for(i=1;i<n+1;i++){
        if(visited[i]==0){
            fwd_dfs(i, -1);
        }
    }
    // debug(fwd_stack);
    ll tot=0;
    for(i=0;i<n;i++){
        if(ans[fwd_stack[n-i-1]]==-1){
            // debug(fwd_stack[i], tot);
            tot+=1;
            rev_dfs(tot, fwd_stack[n-i-1], -1);
        }
    }
    cout<<tot<<'\n';
    FOR(i,n){
        cout<<ans[i+1]<<" ";
    }

    // fwd_dfs(1, 0);


    
}