#include <bits/stdc++.h>
#include <atcoder/convolution>
#define SIZE 1000005
#define MOD 998244353
using namespace std;
using namespace atcoder;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll C(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}
int main()
{
	make();
	int a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(a%2!=b%2)
	{
		puts("0");
		return 0;
	}
	if(a%2!=c%2)
	{
		puts("0");
		return 0;
	}
	if(a%2!=d%2)
	{
		puts("0");
		return 0;
	}
	vector <ll> vx(min(c,d)+1);
	vector <ll> vy(min(a,b)+1);
	for(int i=0;i<=min(c,d);i++)
	{
		if(i%2!=c%2) continue;
		vx[i]=finv[i]*finv[(d-i)/2]%MOD*finv[(c-i)/2]%MOD;
	}
	for(int i=0;i<=min(a,b);i++)
	{
		if(i%2!=a%2) continue;
		vy[i]=finv[i]*finv[(a-i)/2]%MOD*finv[(b-i)/2]%MOD;
	}
	vector <ll> vz=convolution<MOD>(vx,vy);
	ll ans=0;
	for(int i=0;i<vz.size();i++)
	{
		if(vz[i]==0) continue;
		if(i==0&&b+c>0) continue;
		ll w=vz[i]*fac[i]%MOD*fac[(a+d-i)/2]%MOD*fac[(b+c-i)/2]%MOD;
		if(i>0) w=w*C((b+c)/2-1,i/2-1)%MOD;
		w=w*C((a+d)/2,i/2)%MOD;
		ans=(ans+w)%MOD;
	}
	printf("%lld\n",ans);
}
