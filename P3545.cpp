#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#define MAXN 250001

int min(int a, int b) { return a < b ? a : b; }

typedef std::pair<int, int> pii;
std::priority_queue<pii, std::vector<pii>, std::greater<pii> > q;
int n, cnt, a[MAXN], b[MAXN], ans[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
	for (int i = n; i >= 1; --i) {
		q.push(std::make_pair(b[i], i));
		int now = a[i];
		while (!q.empty()) {
			pii t = q.top(); q.pop();
			int jian = min(t.first, now);
			t.first -= jian;
			now -= jian;
			if (t.first == 0) {
				ans[++cnt] = t.second;
			}
			else q.push(t);
			if (now == 0) break;
		}
	}
	std::sort(ans + 1, ans + cnt + 1);
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; ++i) {
		printf("%d ", ans[i]);
	}
	return 0;
}

