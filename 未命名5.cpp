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

int x, y, z;

int main()
{
	x = read();
	y = read();
	z = read();
	if ((x > 0) ^ (y > 0))
		write(abs(x));
	else if (abs(x) < abs(y))
		write(abs(x));
	else if ((x > 0) ^ (z > 0))
		write(abs(z) + abs(x - z));
	else if (abs(z) > abs(y))
		write(-1);
	else write(abs(x));
	putchar('\n');
 	return 0;
}

