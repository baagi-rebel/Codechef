#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = int (1e9) + int (1e5);
const ll INFL = ll(2e18) + ll(1e10);
const ui MOD = 1E9 + 7;
const double EPS = 1e-9;
#define FOR(i,n) for (int i=0;i<(n);i++)
#define FOR2(i,a,b) for (int i=(a);i<(b);i++)
#define ROF(i,x) for(int i = (x) ; i >= 0 ; --i)
#define ROF2(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define ODD(x) (((x)&1)==0?(0):(1))
#define sign(x) ((x > 0) - (x < 0))
#define FAST ios_base::sync_with_stdio(false); cin.tie(0)

inline ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
inline ll gcd(ll a, ll b) { return a ? gcd(b%a, a): b; }
inline ll lcm(ll a, ll b) { return a / gcd(a,b) * b; }

template<class T,class U>
ostream &operator<<(ostream &os,const pair<T,U> &x) {
    return os<<"("<<x.first<<","<<x.second<<")";
}

template<class T>
ostream &operator<<(ostream &os,const vector<T> &x) {
    os << '[';
    if ( !x.empty() ) {
        std::copy (x.begin(), x.end(), std::ostream_iterator<T>(os, ","));
        os << "\b";
    }
    os << "]";
    return os;
}
template<class T>
ostream &operator<<(ostream &os,const vector<vector<T> > &x) {
    os << '[';
    if ( !x.empty() ) {
        os << x[0];
        for (int i=1;i<x.size();i++) os << endl << " " << x[i];
    } else os << "[]";
    os << "]";
    return os;
}

int n;
vi a,b;
vector<ll> ab;
ll m;

bool proba(ll x){
    ll mm=m;
    FOR(i,n){
        if (ab[i]>x){
            ll dif=(ab[i]-x);
            mm -= dif/b[i] + (dif%b[i]==0?0:1);
            if (mm<0) return false;
        }
    }
    return true;
}

int main() {
    FAST;
 //   freopen ("in.txt", "r", stdin);
    cin>>n>>m;
    a.resize(n),b.resize(n),ab.resize(n);
    FOR(i,n) cin>>a[i];
    FOR(i,n) cin>>b[i];
    FOR(i,n) ab[i]=1LL*a[i]*b[i];
    ll lo,hi,mid;
    lo = 0, hi=1E18;
    while (lo<hi){
        mid = (lo+hi)/2;
        if (proba(mid))
            hi=mid;
        else
            lo = mid+1;
    }
    cout << lo;
    return 0;
}

