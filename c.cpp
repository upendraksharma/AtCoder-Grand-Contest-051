#include <bits/stdc++.h>
#define SIZE 100005
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int X[SIZE],Y[SIZE];
int cx[SIZE][3],cy[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	vector <int> vx,vy;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		X[i]=x,Y[i]=y;
		vx.push_back(x);
		vy.push_back(y);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=0;i<n;i++)
	{
		X[i]=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
		Y[i]=lower_bound(vy.begin(),vy.end(),Y[i])-vy.begin();
		cx[X[i]][vy[Y[i]]%3]^=1;
		cy[Y[i]]^=1;
	}
	int a=0,b=0,c=0;
	for(int i=0;i<vy.size();i++)
	{
		if(cy[i])
		{
			if(vy[i]%3==0) a++;
			else if(vy[i]%3==1) b++;
			else c++;
		}
	}
	//printf("%d %d %d\n",a,b,c);
	int x=0,y=0,z=0;
	for(int i=0;i<vx.size();i++)
	{
		for(int j=0;j<3;j++)
		{
			bool up=true;
			for(int k=0;k<3;k++) if(k!=j&&cx[i][j]==cx[i][k]) up=false;
			if(up)
			{
				if(j==0) x++;
				else if(j==1) y++;
				else z++;
			}
		}
	}
	//printf("%d %d %d\n",x,y,z);
	x-=a,y-=b,z-=c;
	if(x<y) swap(x,y);
	if(y<z) swap(y,z);
	if(x<y) swap(x,y);
	
	if(x<0) x=y=z=0;
	if(x>0&&y<0&&z<0)
	{
		int t=min(x,min(-y,-z));
		x-=t,y+=t;z+=t;
		if(x==0) y=z=0;
	}
	if(y>=0&&z<0)
	{
		int t=(-z)/2;
		z+=2*t;
		if(z<0)
		{
			if(x>0) x--,y++,z++;
			else x++,y++,z++;
		}
	}
	if(z>=0)
	{
		if(z%2==1) x++,y++,z--;
	}
	printf("%d\n",a+b+c+x+y+z);
}
