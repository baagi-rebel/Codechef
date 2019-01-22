#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define ff first
#define ss second
#define LIM 100005


using namespace std;

struct info {
    ll x,y,z;
    info() {}
    info(ll xx, ll yy, ll zz) {
        x = xx; y = yy; z = zz;
    }
    bool operator < (const info &b) const {
        return z < b.z;
    }
};

int n;
ll m;
ll v[LIM], w[LIM];

bool f(ll x) {
    ll M = m;
    ll ans = 0;
    for(int i=0; i<n; i++) {
        ll need = v[i]*w[i];

        if(need > x) {

            ll bal = (need-x +w[i]-1)/w[i];
            if(bal <= M) M -= bal;
            else return false;

        }
    }
    return true;
}

int main() {
    scanf("%d %lld", &n,&m);
    for(int i=0; i<n; i++) scanf("%lld", &v[i]);
    for(int i=0; i<n; i++) scanf("%lld", &w[i]);

    ll lo = 0, hi = 1e18;

    while(lo < hi) {
        ll md = (lo+hi)/2;

        if(f(md)) hi = md;
        else lo = md+1;
    }
    cout << hi << endl;
}
