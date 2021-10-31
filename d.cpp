#include <bits/stdc++.h>
#define INF 1500000000LL
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;

ll sqr(ll a)
{
	ll l=1,r=INF;
	while(r-l>1)
	{
		ll d=(l+r)/2;
		if(d*d<=a) l=d;
		else r=d;
	}
	return l;
}
vector <P> vx1;
void solve1(ll x,ll y)
{
	for(int i=0;i<vx1.size();i++)
	{
		P p=vx1[i];
		ll nx=x,ny=y;
		nx-=p.first;
		if(nx<0) break;
		nx/=2;
		ny=(ny+1)/2;
		for(int j=i;j>=0;j--)
		{
			P q=vx1[j];
			ll c=ny/q.second;
			nx-=c*q.first,ny-=c*q.second;
		}
		if(nx>=0)
		{
			puts("Yes");
			return;
		}
	}
	for(int i=0;i<vx1.size();i++)
	{
		P p=vx1[i];
		ll nx=x,ny=y;
		ny+=p.second;
		nx/=2;
		ny=(ny+1)/2;
		for(int j=i;j>=0;j--)
		{
			P q=vx1[j];
			ll c=ny/q.second;
			nx-=c*q.first,ny-=c*q.second;
		}
		if(nx>=0)
		{
			puts("Yes");
			return;
		}
	}
	puts("No");
}
vector <P> vx2;
void solve2(int x,int y)
{
	for(int i=0;i<vx2.size();i++)
	{
		P p=vx2[i];
		ll nx=x,ny=y;
		nx+=p.first;
		nx=(nx+1)/2;
		ny/=2;
		for(int j=i;j>=0;j--)
		{
			P q=vx2[j];
			ll c=nx/q.first;
			nx-=c*q.first,ny-=c*q.second;
		}
		if(ny>=0)
		{
			puts("Yes");
			return;
		}
	}
	for(int i=0;i<vx2.size();i++)
	{
		P p=vx2[i];
		ll nx=x,ny=y;
		ny-=p.second;
		if(ny<0) break;
		nx=(nx+1)/2;
		ny/=2;
		for(int j=i;j>=0;j--)
		{
			P q=vx2[j];
			ll c=nx/q.first;
			nx-=c*q.first,ny-=c*q.second;
		}
		if(ny>=0)
		{
			puts("Yes");
			return;
		}
	}
	puts("No");
}
int main()
{
	vector <ll> va1{2,12};
	while(6LL*va1[va1.size()-1]-va1[va1.size()-2]<=INF) va1.push_back(6LL*va1[va1.size()-1]-va1[va1.size()-2]);
	vector <ll> vb1{1,7};
	while(6LL*vb1[vb1.size()-1]-vb1[vb1.size()-2]<=INF) vb1.push_back(6LL*vb1[vb1.size()-1]-vb1[vb1.size()-2]);
	for(int i=0;i<va1.size();i++)
	{
		ll n=va1[i];
		ll a=2LL*n*n+1;
		vx1.push_back(P(sqr(a),n));
	}
	for(int i=0;i<vb1.size();i++)
	{
		ll n=vb1[i];
		ll b=2LL*n*n+2;
		vx1.push_back(P(sqr(b),n));
	}
	sort(vx1.begin(),vx1.end());
	
	vector <ll> va2{1,5};
	while(6LL*va2[va2.size()-1]-va2[va2.size()-2]<=INF) va2.push_back(6LL*va2[va2.size()-1]-va2[va2.size()-2]);
	vector <ll> vb2{3,17};
	while(6LL*vb2[vb2.size()-1]-vb2[vb2.size()-2]<=INF) vb2.push_back(6LL*vb2[vb2.size()-1]-vb2[vb2.size()-2]);
	for(int i=0;i<va2.size();i++)
	{
		ll n=va2[i];
		ll a=2LL*n*n-1;
		vx2.push_back(P(sqr(a),n));
	}
	for(int i=0;i<vb2.size();i++)
	{
		ll n=vb2[i];
		ll b=2LL*n*n-2;
		vx2.push_back(P(sqr(b),n));
	}
	sort(vx2.begin(),vx2.end());
	//for(int i=0;i<vx2.size();i++) printf("%lld %lld\n",vx2[i].first,vx2[i].second);
	int Q;
	scanf("%d",&Q);
	for(int i=0;i<Q;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x>=0&&y>=0) puts("Yes");
		else if(y<0) solve1(x,-y);
		else solve2(-x,y);
	}
}
