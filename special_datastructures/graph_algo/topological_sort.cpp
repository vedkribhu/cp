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
ll mx = 2e5+7;
ll n,m;
vector<VL> adj(mx);
VL col(mx);
deque<ll> fwd;
VL tmp;
// VL depths(mx);

bool dfs(ll i, ll parent){
    // debug(i, parent);
    if(col[i]==1){
        // debug(i);
        return false;
    }

    else if(col[i]==0){
        col[i]=1;
        bool flag = true;
        
        // pre[i]=parent;
        for(auto nb: adj[i]){
            if(nb==parent || col[nb]==2){continue;}
            // pre[nb]=i;
            // debug()
            if (dfs(nb, i)==false){
                flag = false;
                break;
            }

        }
        tmp.pb(i);
        col[i]=2;
        
        return flag;
    }
    else{
        return true;
    }
}




int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll tc;
    cin >> tc;
    ll ct= 0;
    while(tc--){
        ct++;
        ll i,u,v,j,c;
        cin>>n>>m;
        adj.clear();
        col.clear();
        fwd.clear();
        for(i=0;i<=n;i++){
            VL tmp;
            adj.pb(tmp);
            col.pb(0);
        }

        // debug(col);

        // vector<VL> adj(mx);
        // VL col(mx);
        vector<pl> und;
        vector<pl> edges;
        for(i=0;i<m;i++){
            cin>>c>>u>>v;
            if(c==0){
                und.pb(mp(u,v));
                continue;
            }
            adj[u].pb(v);
            edges.pb(mp(u,v));
            // adj[v].pb(u); 
        }
        // if(ct==41){
        //     debug(n,m, edges, und);
        //     break;
        // }
        // else{
        //     continue;
        // }

        bool flag = true;
        // dfs(1,-1);
        // debug(col);
        for(i=1;i<=n;i++){
            // debug(col[i],i);
            if(col[i]==0){
                // debug(i);
                tmp.clear();
                flag = dfs(i, -1);
                if(!flag){
                    break;
                }
                else{
                    for(auto k: tmp){
                        fwd.push_front(k);
                    }
                }
            }
        }
    }
}