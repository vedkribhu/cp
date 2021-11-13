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
 
typedef int ll;
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
ll mx = 2*1e5+7;
ll n,m;
vector<VL> adj(mx);
VL col(mx);
ll ans=-1, cur_depth = 0;

// deque<ll> fwd;
// VL tmp;
VL depths(mx,-1);






int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("test_input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #endif
    ll i,j,q,u,v,n,k;
    cin>>n>>q;
    // n++;
    // VL adj
    ll tmp = log2(n);
    ll ori = tmp;
    // debug(ori);
    vector<VL> pre(n+1,vector<ll>(tmp,-1));
    vector<VL> adj(n+1);
    VL levels(n+1);
    levels[1] = 0;
    FOR(i,n-1){
        cin>>u;
        adj[u].pb(i+2);
        // levels[i+2] = 1+levels[u];
        pre[i+2][0]=u;
    }
    queue<ll>bfq;
    bfq.push(1);
    while(bfq.size()>0){
        ll e = bfq.front(); bfq.pop();
        // debug(e);
        for(auto nb: adj[e]){
            levels[nb] = 1+levels[e];
            bfq.push(nb);
        }
    }


    // debug(levels);
    // debug(pre);
    // debug
    // FOR()

    for(i=1;i<=n;i++){
        for(j=1; j<=tmp;j++){
            if(pre[i][j-1]!=-1){
                pre[i][j] = pre[pre[i][j-1]][j-1];
            }
        }
    }
    // debug(pre);
    ll op;
    FOR(op,q){
        cin>>u>>v;
        // debug(u,v);
        if(levels[u]>levels[v]){
            swap(u,v);
        }
        k = levels[v]- levels[u];
        tmp = log2(k);
        // debug(k,v);
        while(k>0){
            v = pre[v][tmp];
            k -= (1<<tmp);
            if(k==0 || v==-1){
                break;
            }
            tmp = log2(k);
        }
        // debug(u,v);
        for(i = ori; i>=0;i--){
            if(u==v){
                break;
            }
            if((pre[u][i]!=pre[v][i]) && (pre[u][i]!=-1)){
                // debug(pre[u][i],pre[v][i],u,i);
                u = pre[u][i];
                v = pre[v][i];
                break;
            }
        }
        // debug(u,v);
        while(u!=v){
            u = pre[u][0];
            v = pre[v][0];
        }
        printf("%d\n",u);
        
    }



}