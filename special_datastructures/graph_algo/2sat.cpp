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
typedef vector<VL> VVL;
typedef vector<bool> VB;
 
// typedef pair<ll, ll> PL;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b,init) for(i=init;i<b;i++)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
 
// typedef  unordered_set<ll>;
 
 
// void printa(VI &x,ll n){
//     ll i;
//     FOR(i, n){
//         cout<<x[i]<<" ";
//     }
//     cout<<endl;
// }
 
 

/////GLOABLS VARS
ll MOD = 1e9+7;
ll MOD1 = 998244353;
ll gmx = 1e6+7; 

VL fact(gmx, 1);
//////FUNCTIONS
ll powp(ll val, ll deg)
{
    // debug(val, deg);
    if (!deg)
        return 1;
    if (deg & 1)
        return (powp(val, deg - 1) * val) % MOD;
    ll res = powp(val, deg >> 1);
    // debug(res);
    return (res * res) % MOD;
}
ll mx=2*1e5+7;
vector<VL> adj(mx);
vector<VL> rev_adj(mx);
VL sub;
VL vis(mx,0);
VL comp(mx,-1);
// VL igno;
ll n;

void dfs(ll r, ll parent){
    // if(igno[r]==1){return;}
    // debug(r,parent);
    vis[r]=1;
    for(auto k: adj[r]){
        if(k==parent){continue;}
        if(vis[k]==1){continue;}
        dfs(k, r);
    }
    sub.pb(r);
    return;
}

void rev_dfs(ll r, ll parent, ll ct){
    // if(igno[r]==1){return;}
    // debug(r,parent);
    comp[r] = ct;
    // vis[r]=1;
    for(auto k: rev_adj[r]){
        if(k==parent){continue;}
        if(comp[k]!=-1){continue;}
        rev_dfs(k, r,ct);
    }
    // sub.pb(r);
    return;
}


//It is not easy but it can be fun, if you think!!!

ll gcd(ll a, ll b){
    // debug(a,b);
    if(a>b){swap(a,b);}
    if(a==0){return b;}
    return gcd(a, b%a);
}
int centroid(ll u, ll p) {
    // debug(u,p);
    for (auto v : adj[u])
        if (v != p and sub[v] > n/2) return centroid(v, u);

    return u;
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll n,m;
    cin>>n>>m;
    ll i,j,k,ind;
    
    FOR(ind,n,0){
        char c1,c2;
        ll i1,i2;
        cin>>c1>>i1>>c2>>i2;
        if(c1=='+'){
            // i1 = 2*i1;
            if(c2=='+'){
                adj[2*i1].pb(2*i2-1);
                adj[2*i2].pb(2*i1-1);
            }
            else{
                adj[2*i1].pb(2*i2);
                adj[2*i2-1].pb(2*i1-1);
            }
        }
        else{
            if(c2=='+'){
                adj[2*i1-1].pb(2*i2-1);
                adj[2*i2].pb(2*i1);
            }
            else{
                adj[2*i1-1].pb(2*i2);
                adj[2*i2-1].pb(2*i1);
            }      
        }
    }
    for(ll x=1;x<=2*m;x++){
        for(auto y: adj[x]){
            rev_adj[y].pb(x);
        }
    }
    for(ll x=1;x<=2*m;x++){
        if(vis[x]==0){
            dfs(x,-1);
        }
    }
    // debug(sub,adj);
    ll s=sub.size();
    j=0;
    FOR(i,s,0){
        if(comp[sub[s-i-1]]==-1){
            rev_dfs(sub[s-i-1],-1,j);
            j++;
        }
    }
    string ans[m];
    // debug(comp);
    for(i=1;i<=2*m;i+=2){
        // debug(comp[i], comp[i+1]);
        if(comp[i]==comp[i+1]){
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        if(comp[i]>comp[i+1]){
            ans[(i-1)/2] ='+';
        }
        else{
            ans[(i-1)/2] ='-';
        }

    }
    FOR(i,m,0){
        cout<<ans[i]<<" ";
    }


}