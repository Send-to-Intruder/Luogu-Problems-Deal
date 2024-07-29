#include<iostream>
#include<queue>

using namespace std;
priority_queue<int> que;
long long ans;
int n, u;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) {
		cin >> u;
		que.push(-u),que.push(-u);
		ans += u + que.top();
		que.pop();
	}
	printf("%lld",ans);
	return 0;
}
