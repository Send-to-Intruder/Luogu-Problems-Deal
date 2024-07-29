#include<iostream>
#include<cstdio>
#include<utility>
#include<algorithm>
#define pii pair<int,int>

using namespace std;

int n,f[10005];
pii a[10005];

bool cmp(pii a,pii b) {
	return a.first > b.first;
}

int find(int x) {
	if(x != f[x]) f[x] = find(f[x]);
	return f[x];
}

int mg()
{
	int sum = 0;
	for(int i = 0;i < n; i++) {
		int t1 = a[i].first;
		int t2 = a[i].second;
		int x = find(t2);
		if(x > 0) {
			sum += t1;
			f[x] = x - 1;
		}
	}
	return sum;
}

signed main()
{	
	while(scanf ("%d", &n) != EOF) {
		int maxd = 0;
		for(int i = 0;i < n; i++) {
			scanf("%d%d",&a[i].first,&a[i].second);
			maxd = max(maxd,a[i].second);
		}
		sort(a,a + n,cmp);
		for(int i = 0;i <= maxd; i++)
			f[i] = i;
		printf("%d\n",mg());
	}
	return 0;
}
