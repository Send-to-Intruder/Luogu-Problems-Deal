#include<iostream>

using namespace std;
const int N = 5001;
int t[N * N], f[N * N], up[N], down[N];
long long a,b,c,d;
int n,m,q;

int read() {
	int x = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0',ch = getchar();
	return x * w;
}

signed main()
{
	f[0] = read(), a = read(), b = read(), c = read(), d = read();
	n = read(), m = read(), q = read();
	for(int i = 1;i <= n * m;i++) f[i] = (a * f[i - 1] * f[i - 1] + b * f[i - 1] + c) % d;
	for(int i = 1;i <= n * m;i++) t[i] = i;
	for(int i = 1;i <= n * m;i++) swap(t[i],t[f[i] % i + 1]);
	for(int i = 1;i <= q;i++) {int x = read(), y =read();swap(t[x],t[y]);}
	for(int i = 1;i <= n * m;i++) f[t[i]] = i;
	for(int i = 1;i <= m;i++) up[i] = 1,down[i] = n;
	for(int i = 1;i <= n * m;i++) {
		int x = f[i] % m == 0 ? m : f[i] % m, y = (f[i] - 1) / m + 1;
		if(up[x] <= y && down[x] >= y) {
			printf("%lld ",i);
			for(int j = x + 1;j <= m;j++) up[j] = max(up[j],y);
			for(int j = 1;j < x;j++) down[j] = min(down[j],y);
		}
	}
 	return 0;
}
