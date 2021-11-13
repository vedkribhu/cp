#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>
// typedef vector<int> vi; 
typedef long long ll;

using namespace std;


ll MOD = 998244353;
ll fast(ll a, ll n){
	if(n==0){
		return 1;
	}
	else{
		ll r = fast(a, n/2);
		if(n%2==0){
			return (r*r)%MOD;
		}
		else{
			return (r*r*a)%MOD;
		}
	}
}

int main(){
	int w,h;
	cin >> w>>h;
	ll ans = fast(2, w+h);
	cout<<ans<<endl;

}