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

struct node{
	int l, r, num;
}ST[2000005];
int a[500005];
int m, n;
int opt, x, y;

int _search(int id, int l, int r)
{
	if (ST[id].l >= l && ST[id].r <= r)
		return ST[id].num;
	if (ST[id].r < l || ST[id].l > r)
		return 0;
	int s = 0;
	if (ST[id << 1].r >= l)
		s += _search((id << 1), l, r);
	if (ST[(id << 1) + 1].l <= r)
		s += _search((id << 1) + 1, l, r);
	return s;
}

void _add(int id, int x, int k)
{
	ST[id].num += k;
	if (ST[id].l < ST[id].r)
	{
		int mid =  (ST[id].r + ST[id].l) >> 1;
		if (x > mid)
			_add((id << 1) + 1, x, k);
		else
			_add(id << 1, x, k);
	}
}

void _build(int id, int l, int r)
{
	if (l > r)
		return;
	ST[id].l = l;
	ST[id].r = r;
	if (l == r)
	{
		ST[id].num = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	_build(id << 1, l, mid);
	_build((id << 1) + 1, mid + 1, r);
	ST[id].num = ST[id << 1].num + ST[(id << 1) + 1].num;
}

int main()
{
	n = read();
	m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	_build(1, 1, n);
	while (m--)
	{
		opt = read();
		x = read();
		y = read();
		if (--opt)
		{
			write(_search(1, x, y));
			putchar('\n');
		}
		else
			_add(1, x, y);
	}
 	return 0;
}
