#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch;
	ch = getchar();
	while (!isdigit(ch) && ch != '-')
	{
		ch = getchar();
	}
	if (ch == '-')
		f = -1, ch = getchar();
	while (isdigit(ch))
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-');
		write(-x);
		return;
	}
	if (x < 10)
	{
		putchar(x + '0');
		return;
	}
	write(x / 10);
	putchar(x % 10 + '0');
}

int n, x, y, a, b;
vector < int > v[200005];
bool vis[200005];
int arr[200005];

void print(int step)
{
	for (int i = 1; i <= step; i++)
		putchar(' '), write(arr[i]);
	putchar('\n');
}

void dfs(int step, int ver)
{
	if (ver == y)
	{
		print(--step);
		exit(0);
	}
	for (int i = 0; i < v[ver].size(); i++)
		if (!vis[v[ver][i]])
		{
			vis[v[ver][i]] = 1;
			arr[step] = v[ver][i];
			dfs(step + 1, v[ver][i]);
			vis[v[ver][i]] = 0;
		}
}

int main()
{
	n = read();
	x = read();
	y = read();
	vis[x] = 1;
	for (int i = 1; i < n; i++)
	{
		a = read();
		b = read();
		v[a].push_back(b);
		v[b].push_back(a);
	}
	write(x);
	dfs(1, x);
 	return 0;
}

