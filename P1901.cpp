#include<iostream>
#include<algorithm>
#define maxn 1000010
using namespace std;
namespace s {
	int n;
	struct node{
		int h,v;
	}a[maxn];
	int stc[maxn],ans[maxn],r,as;
	
	void solvep() {
		cin >> n;
		for(int i = 1;i <= n;i++) cin >> a[i].h >> a[i].v;
		r = 0;
		for(int i = 1;i <= n;i++) {
			int x = i;
			while(r && a[stc[r]].h <= a[x].h) --r;
			ans[stc[r]] += a[x].v;
			stc[++r] = x;
		}
		r = 0;
		for(int i = 1;i <= n;i++) {
			int x = n - i + 1;
			while(r && a[stc[r]].h <= a[x].h) --r;
			ans[stc[r]] += a[x].v;
			stc[++r] = x;
		}
		for(int i = 1;i <= n;i++) as = max(as,ans[i]);
		cout << as << '\n';
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	s::solvep();
	return 0;
}
