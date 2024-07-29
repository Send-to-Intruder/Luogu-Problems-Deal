#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int q1[maxn],q2[maxn],h1=1,h2=1,t1,t2;
int n,d;
struct node
{
	int x,y;
}a[maxn];
bool cmp(node qw,node we)
{
	return qw.x<we.x;
}
int ans=2147483647;
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
	}
	sort(a+1,a+n+1,cmp);
	for(int l=1,r=0;l<=n;l++)
	{
		while(h1<=t1&&q1[h1]<l) h1++;
		while(h2<=t2&&q2[h2]<l) h2++;
		while(a[q1[h1]].y-a[q2[h2]].y<d&&r<n)
		{
			++r;
			while(a[q1[t1]].y<a[r].y&&h1<=t1) t1--;
			q1[++t1]=r;
			while(a[q2[t2]].y>a[r].y&&h2<=t2) t2--;
			q2[++t2]=r;
		}
		if(a[q1[h1]].y-a[q2[h2]].y>=d) ans=min(ans,a[r].x-a[l].x); 
	}
	if(ans==2147483647) printf("-1");
	else printf("%d",ans);
	return 0;
}	
