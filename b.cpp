#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int k;
	//scanf("%d",&k);
	k=20;
	vector <int> vx,vy;
	mt19937 mrnd(11111);
	uniform_int_distribution <int> drnd(100,10000);
	int sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=drnd(mrnd);
		for(int j=1;j<=k;j++)
		{
			vx.push_back(sum);
			sum+=j;
		}
	}
	sum=0;
	for(int i=0;i<k;i++)
	{
		sum+=drnd(mrnd);
		for(int j=1;j<=k;j++)
		{
			vy.push_back(sum);
			sum+=j;
		}
	}
	set <int> sx,dx;
	int c=0;
	printf("%d\n",k*k*k);
	for(int i=0;i<k*k;i++)
	{
		for(int j=0;j<k*k;j++)
		{
			if(i%k!=j%k) continue;
			c++;
			printf("%d %d\n",vx[i],vx[j]);
			sx.insert(vx[i]+vx[j]);
			dx.insert(vx[i]-vx[j]);
		}
	}
	//printf("%d %d : %d %d\n",c,vx.size(),sx.size(),dx.size());
}
