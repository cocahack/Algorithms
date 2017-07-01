#include<iostream>
using namespace std;
int sumCipher(int n)
{
	int acc = 0;
	while (n > 0) {
		acc += n % 10;
		n /= 10;
	}
	return acc;
}
int main()
{
	int n;
	cin >> n;
	int count = 0, c = n, i = 1, sum;
	while (i <= 1000000) {
		sum = i + sumCipher(i);
		if (sum == n) {
			cout << i << "\n";
			goto stop;
		}
		++i;
	}
	cout << 0 << "\n";
	stop:
	return 0;
}