#include "bits/stdc++.h"
using namespace std;

#define pb  push_back
#define mp  make_pair
#define ll  long long
#define itr iterator

typedef pair<ll,ll> pii;

const ll MAX=2e5;
const ll INF=1e12;

ll N,M,A[MAX],B[MAX];

ll cal(ll X)
{
	ll res=0;
	cout<<X<<"\n";
	for(int i=1;i<=N;i++){
		if(X<A[i]*B[i])
      		cout<<X<<" "<<A[i]<<" "<<B[i]<<"\n";
			res+=A[i]-X/B[i];
	}
	return res;
}

signed main()
{
	ios_base::sync_with_stdio(false);

	cin>>N>>M;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	for(int i=1;i<=N;i++)
		cin>>B[i];
	ll low=1,high=1e18,mid,res=-1;

	while(low<=high)
	{
		mid=(low+high)/2;
		if(cal(mid)<=M)
			res=mid,high=mid-1;
		else
			low=mid+1;
	}
	cout<<res;
	
	return 0;
}