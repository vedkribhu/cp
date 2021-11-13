#include <bits/stdc++.h>
using namespace std;

 
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
 
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<bool> VB;
typedef vector<string> VS;
typedef pair<ll, ll> pl;
typedef unordered_map<ll, ll> UMP;
#define FOR(i,b) for(i=0;i<b;i++)
#define pb push_back
#define mp make_pair
 
vector<pair<ll,ll>> dirx{mp(1,0),mp(0,1),mp(-1,0),mp(0,-1)};
vector<char> dir{'D', 'R','U','L'};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,m,j;
    cin>>n>>m;
    string tmp;
    VS l(n);
    FOR(i,n){
        cin>>tmp;
        l[i]=tmp;
    }
    pl cord;
    FOR(i,n){
        FOR(j,m){
            if(l[i][j]=='A'){
                cord = mp(i,j);
                break;
            }
        }
    }
    // debug(cord);
    vector<VB> vis(n, vector<bool>(m, false));
    ll ans = 0;
    // cout<<l[0][0];
    list <pair<ll,ll>> queue;
    queue.pb(cord);
    string fans="";
    list<string> dirqueue;
    dirqueue.pb("");
    // debug(cord)
    while(!queue.empty()){
        pair<ll,ll> s = queue.front();
        queue.pop_front();
        string sof = dirqueue.front();
        // debug(queue);
        dirqueue.pop_front();
        debug(s);
        vis[s.first][s.second] = true;
        if(l[s.first][s.second]=='B'){
            fans = sof;
            break;
            
        }
        for(ll ind=0;ind<4;ind++){
                pl nbx=dirx[ind];
                ll nby = nbx.second;
                ll nx = nbx.first;
                nx = nx+s.first;
                nby = nby+s.second;
                if(nx>=n || nby>=m || nx<0 || nby<0){continue;}
                if(vis[nx][nby]==false && l[nx][nby]!='#'){
                    vis[nx][nby]=true; 
                    queue.push_back(mp(nx, nby));
                    dirqueue.pb(sof+dir[ind]);
                }
        }
    }
    if(fans.length()){
        cout<<"YES\n";
        cout<<fans.length()<<'\n';
        cout<<fans<<'\n';
    }
    else{
        cout<<"NO\n";
    }
    // cout<<fans<<endl;
}