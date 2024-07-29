#include<iostream>
#define int long long 
using namespace std;
int n,maxn,m;
int na[2000010];

int check(int x) {
	int ans = 0;
	for(int i = 1;i <= n;i++) if(na[i] > x) ans += (na[i] - x);
	return ans;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m; 
	for(int i = 1;i <= n;i++) {
		cin >> na[i];
		maxn = max(maxn,na[i]);
	}
	int l = 1,r = maxn;
	for(int i = 0;i <= 100;i++) {
		int mid = (l + r) >> 1;
		if(check(mid) < m) r = mid -1;
		else l = mid + 1;
	}
	cout << r << '\n';
	return 0;
}







//
