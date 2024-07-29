#include<iostream>

using namespace std;
const int maxn = 255 ,maxm = 1010;
int n,w,a[maxn],b[maxn];
double f[maxm];

bool check(double mid) {
	f[0] = 0;
	for(int i = 1;i <= w;i++) f[i] = -1e9;
	for(int i = 1;i <= n;i++) {
		for(int j = w;j >= 0;j--) {
			int k = min(j + b[i],w);
			f[k] = max(f[k],f[j] + a[i] - mid * b[i]);
		} 
	}
	return f[w] >= 0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> w;
	for(int i = 1;i <= n;i++) cin >> b[i] >> a[i];
	double l = 0,r = 1000;
	while(r - l > 1e-5) { 
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << (int)(l * 1000) << '\n';
	return 0;
}

