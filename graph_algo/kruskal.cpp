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
VL parent(mx);
VL sizep(mx,1);
ll max_size = 1;
ll num_comp = mx;



void createDSU(){
    for(ll i=0;i<mx;i++){
        parent[i]=i;
    }
}
ll findp(ll i){
    if(parent[i]==i){
        return i;
    }
    return parent[i] = findp(parent[i]);
}
void unionSet(ll i, ll j){
    ll a,b;
    a= findp(i);
    b = findp(j);
    if(a==b){
        return;
    }
    if(sizep[a]>sizep[b]){
        swap(a,b);
    }
    parent[a] = b;
    sizep[b]+=sizep[a];
    max_size = max(max_size, sizep[b]);
    num_comp--;
    return;
}

int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    #endif
    ll i,u,v,j,c; 
    ll n,m;
    cin>>n>>m;
    createDSU();
    vector<pl> edge;
    priority_queue<pl,vector<pl>, greater<pl>> weights;
    num_comp = n;
    FOR(i,m){
        cin>>u>>v>>c;
        edge.pb(mp(u,v));
        weights.push(mp(c,i));
    }
    ll ct=0;
    ll ans = 0;
    while(ct<n-1 && weights.size()>0){
        pl g=weights.top();weights.pop();
        u = edge[g.second].first, v = edge[g.second].second;
        // debug(g, ans, u, v);
        if(findp(u)!=findp(v)){
            ct++;
            ans+= g.first;
            unionSet(u,v);
        }
    }
    if(ct==n-1){
        cout<<ans;
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}