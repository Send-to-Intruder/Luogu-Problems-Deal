#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int maxn = 20000005;
int n,m,head[250005],tot;
int d[250005],a[505][505];
int bx,by,ex,ey;
bool v[250005];
char aa[505];

struct node {
	int next,to,w;
} e[maxn];

void add(int x,int y,int z) {
	e[++tot].next = head[x];
	e[tot].to = y;
	e[tot].w = z;
	head[x] = tot;
}

void spfa(int s) {
	queue<int> q;
	for(int i = 1; i <= n * m + 1; i++) {
		d[i] = 2000040915;
		v[i] = false;
	}
	d[s] = 0;
	v[s] = true;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		v[x] = false;
		for(int i = head[x];i;i = e[i].next){
			int y = e[i].to;
			int z = e[i].w;
			if(d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if(v[y] == false) {
					q.push(y);
					v[y] = true;
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(;;) {
		cin >> n >> m;
		if (n == 0 && m == 0) return 0;
		memset(head,0,sizeof(head));
		tot = 0;
		for(int i = 1; i <= n; i++) {
			cin >> aa+1;
			for(int j = 1;j <= m; j++) {
				if(aa[j] == '@') a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		for(int i = 1;i <= n; i++) 
			for(int j = 1;j <= m; j++) {
				if(i > 1) add((i-1) * m + j,(i-2) * m + j,a[i][j] ^ a[i - 1][j]),add((i - 2) * m + j,(i - 1) * m + j,a[i][j] ^ a[i - 1][j]);
				if(i < n) add((i-1) * m + j,i * m + j,a[i][j] ^ a[i + 1][j]),add(i * m + j,(i - 1) * m + j,a[i][j] ^ a[i + 1][j]);
				if(j > 1) add((i-1) * m + j,(i-1) * m + j - 1,a[i][j] ^ a[i][j - 1]),add((i - 1) * m + j - 1,(i - 1) * m + j,a[i][j] ^ a[i][j - 1]);
				if(j < m) add((i-1) * m + j,(i-1) * m + j + 1,a[i][j] ^ a[i][j + 1]),add((i - 1) * m + j + 1,(i - 1) * m + j,a[i][j] ^ a[i][j + 1]);
				
			}
		cin >> bx >> by >> ex >> ey;
		bx++,by++,ex++,ey++;
		int be = (bx - 1) * m + by;
		int en = (ex - 1) * m + ey;
		spfa(be);
		cout << d[en] << '\n';
	}
	return 0;
}