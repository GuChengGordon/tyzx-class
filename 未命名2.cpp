#include <bits/stdc++.h>
using namespace std;

int n, m;
int ar[85];

struct node{
	int p[505], len;
	node()
	{
		memset(p, 0, sizeof p);
		len = 0;
	}
	void print()
	{
		printf("%d", p[len]);  
        for (int i = len - 1; i > 0; i--)
		{  
            if (p[i] == 0)
			{
				printf("0000"); 
				continue;
			}
            for (int k = 10; k * p[i] < 10000; k *= 10) 
				printf("0");
            printf("%d", p[i]);
        }
	}
}f[85][85], base[85], ans;

node operator + (const node &a, const node &b) {
	node c;
	c.len = max(a.len, b.len);
	int x = 0;
	for (int i = 1; i <= c.len; i++)
	{
		c.p[i] = a.p[i] + b.p[i] + x;
		x = c.p[i] / 10000;
		c.p[i] %= 10000;
	}
	if (x > 0)
		c.p[++c.len] = x;
	return c;
}

node operator * (const node &a, const int &b) {
	node c;
	c.len = a.len;
	int x = 0;
	for (int i = 1; i <= c.len; i++)
	{
		c.p[i] = a.p[i] * b + x;
		x = c.p[i] / 10000;
		c.p[i] %= 10000;
	}
	while (x > 0)
		c.p[++c.len] = x % 10000, x /= 10000;
	return c;
} 

node max(const node &a, const node &b) {
	if (a.len > b.len)
		return a;
	else if (a.len < b.len)
		return b;
	for (int i = a.len; i > 0; i--)
		if (a.p[i] > b.p[i])
			return a;
		else if (a.p[i] < b.p[i])
			return b;
	return a;
} 

void BaseTwo() {
	base[0].p[1] = 1, base[0].len = 1;
	for (int i = 1; i <= m + 2; i++)
	{ 
		base[i] = base[i - 1] * 2;
	}
}

int main(void) {
	scanf("%d%d", &n, &m);
	BaseTwo();
	while (n--)
	{
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= m; i++)
			scanf("%d", &ar[i]);
		for (int i = 1; i <= m; i++)
			for (int j = m; j >= i; j--)
			{
				f[i][j] = max(f[i][j], f[i - 1][j] + base[m - j + i - 1] * ar[i - 1]); 
				f[i][j] = max(f[i][j], f[i][j + 1] + base[m - j + i - 1] * ar[j + 1]);
			}
		node maxn;
		for (int i = 1; i <= m; i++)
			maxn = max(maxn, f[i][i] + base[m] * ar[i]);
		ans = ans + maxn;
	}
	ans.print();
	return 0;
}

