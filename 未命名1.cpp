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
void write(int x)
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

int T;
int n, x;
int a[1005];
bool vis[10005];
bool fg[10005];
bool ans = 0;

bool dfs(int step)
{
	if (step > x)
		return false;
	if (step == x)
		return true;
	bool f = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!a[i] && !fg[step + a[i]])
			vis[step + a[i]] = dfs(step + a[i]), fg[step + a[i]] = 1;
	}
}

priority_queue < int > q;

int main()
{
	T = read();
	while (T--)
	{
		n = read();
		x = read();
		bool f = (x > 0), flag = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i] = read();
			if (!(f ^ (a[i] > 0)))
				flag = 1;
		}
		if (flag)
		{
			puts("Yes");
			continue;
		}
		if (!f)
		{
			x = -x;
		}
		else
		{
			for (int i = 1; i <= n; i++)
				a[i] = -a[i];
		}
		for (int i = 1; i <= n; i++)
			q.push(a[i]);
		while (q.size())
		{
			int num = q.top();
			if (num > x)
				break;
			q.pop();
			if (num == x)
			{
				ans = 1;
				continue;
			}
			for (int i = 1; i <= n; i++)
				q.push(num + a[i]);
		}
		if (q.size() || ans)
			puts("Yes");
		else
			puts("No");
	}
 	return 0;
}

