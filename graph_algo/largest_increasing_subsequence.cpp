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
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<bool> VB;

typedef pair<ll, ll> PL;
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

ll mx = 1e6;




int main(){
      ios::sync_with_stdio(0);
      cin.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    //     #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
    // #endif
    ll i,j,n,m;
    cin>>n;
    VL l(n);
    FOR(i,n){
        cin>>l[i];
    }   
    VL ends(n,0); 
    ll len = 1;
    for(i=0;i<n;i++){
        // debug(ends);
        if(l[i]>ends[len-1]){
            ends[len] = l[i];
            len+=1; 
        }
        else{
            ll lf = 0, rt = len-1, ans=0;
            while(lf<=rt){
                ll m = lf+(rt-lf)/2;
                if(ends[m]>=l[i]){
                    ans = m;
                    rt = m-1;
                }
                else{
                    lf = m+1;
                }
            }
            ends[ans] = l[i];
        }
    }
    cout<<len-1;

}
    

