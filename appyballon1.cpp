#include "bits/stdc++.h"
using namespace std;

#define pb  push_back
#define mp  make_pair
#define ll  long long
#define itr iterator

typedef pair<ll,ll> pii;

const ll MAX=2e5;
const ll INF=1e12;

ll N,M,C,f[MAX],s[MAX];

ll cal(ll X)
{
	ll res=0;
	for(int A=1;A<=N;A++){
		if(X<f[A]*C){
			res+=f[A]-X/C;
        }
    }
	return res;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin>>N>>M>>C;
	for(int A=1;A<=N;A++)
		cin>>f[A];    
	ll low=1,high=1e18,mid,res=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
        ll m1=cal(mid);
        if(m1==M){
            res=mid;
            break;
        }
		else if(m1<=M)
			res=mid,high=mid-1;
		else
			low=mid+1;
	}
	cout<<res;
	return 0;
}