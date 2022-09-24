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
inline long long _read()
{
	long long x = 0;
	int f = 1;
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
inline void _write(long long x)
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

int n, cnt;
long long a[100005];
long long k;
struct node{
	long long num;
	int id;
	friend bool operator <(node a, node b)
	{
		return a.num < b.num;
	}
}
node arr[100005];

int main()
{
	n = read();
	k = _read();
	node t;
	for (int i = 1; i <= n; i++)
	{
		a[i] = _read();
		arr[i].num = a[i];
		arr[i].id = i;
	}
	sort(arr + 1, arr + n + 1);
	for (int i = n; i >= 2;)
		arr[i].num -= arr[--i].num;
	tot = 0;
	for (int i = 1; tot + (n - i + 1) * arr[i].num <= k; i++)
	{
		tot += (n - i + 1) * arr[i].num;
		arr[i].num = 0;
	}
	
 	return 0;
}

