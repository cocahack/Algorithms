#include<iostream>
using namespace std;
#define EARTH 16
#define SUN 29
#define MOON 20
int E, S, M, cnt, e, s, m;
bool is_end()
{
	return E == e && S == s && M == m;
}
int main()
{
	cin >> E >> S >> M;
	e = s = m = cnt = 1;
	while (!is_end()) {
		++e; ++s; ++m;
		if (e == EARTH) e = 1;
		if (s == SUN) s = 1;
		if (m == MOON) m = 1;
		++cnt;
	}
	cout << cnt << "\n";
	return 0;
}