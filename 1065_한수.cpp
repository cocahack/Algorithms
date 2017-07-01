#include<iostream>
using namespace std;
inline int calCd(int n)
{
	return (n % 10) - ((n / 10) % 10);
}
int test(int n)
{
	int cd = calCd(n), diff;
	n /= 10;
	while (n > 9) {
		diff = calCd(n);
		if (cd != diff) return 0;
		n /= 10;
	}
	return 1;
}
int main()
{
	int n;
	cin >> n;
	if (n < 100)
		cout << n << "\n";
	else {
		int base = 99, i = 100;
		while (i <= n) {
			base += test(i);
			++i;
		}
		cout << base << "\n";
	}
	return 0;
}