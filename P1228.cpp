#include<iostream>

using namespace std;

int x,y,k;

char step(int x,int y,int xgo,int ygo,int length) {
	if(xgo <= x + length / 2 - 1 && ygo <= y + length / 2 - 1)
		return 'a';
	else if (xgo <= x + length / 2 - 1 && ygo >= y + length / 2)
		return 'b';
	else if (xgo >= x + length / 2 && ygo <= y + length / 2 - 1)
		return 'c';
	else return 'd';
}

void go(int x,int y,int xgo,int ygo,int length) {
	if(length == 1) return;
	if(step(x,y,xgo,ygo,length) == 'a'){
		cout << x + length / 2 << " " << y + length / 2 << " " << 1 << '\n';
		go(x,y,xgo,ygo,length >> 1);
		go(x,y + length / 2,x+ length / 2 - 1,y + length / 2,length >> 1);
		go(x + length / 2,y,x + length / 2,y + length /2 - 1,length >> 1);
		go(x + length / 2,y + length / 2,x + length / 2,y + length / 2,length >> 1);
	} else if (step(x,y,xgo,ygo,length) == 'b') {
		cout << x + length / 2 << " " << y + length / 2 - 1 << " " << 2 << '\n';
		go(x,y,x + length /2 - 1,y + length / 2 - 1,length >> 1);
		go(x,y + length / 2,xgo,ygo,length >> 1);
		go(x + length / 2,y,x + length / 2,y + length /2 - 1,length >> 1);
		go(x + length / 2,y + length / 2,x + length / 2,y + length / 2,length >> 1);
	} else if (step(x,y,xgo,ygo,length) == 'c') {
		cout << x + length / 2 - 1 << " " << y + length / 2 << " " << 3 << '\n';
		go(x,y,x + length / 2 - 1,y + length / 2 - 1,length >> 1);
		go(x,y + length / 2,x+ length / 2 - 1,y + length / 2,length >> 1);
		go(x + length / 2,y,xgo,ygo,length >> 1);
		go(x + length / 2,y + length / 2,x + length / 2,y + length / 2,length >> 1);
	} else if (step(x,y,xgo,ygo,length) == 'd') {
		cout << x + length / 2 - 1 << " " << y + length / 2 - 1 << " " << 4 << '\n';
		go(x,y,x + length / 2 - 1,y + length / 2 - 1,length >> 1);
		go(x,y + length / 2,x+ length / 2 - 1,y + length / 2,length >> 1);
		go(x + length / 2,y,x + length / 2,y + length /2 - 1,length >> 1);
		go(x + length / 2,y + length / 2,xgo,ygo,length >> 1);
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> k >> x >> y;
	go(1,1,x,y,1<<k);
	return 0;
}

	
