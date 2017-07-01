#include <iostream>
#include <vector>
using namespace std;
void calc(vector<long long> &ans, long long n, long long ten) {
	while (n > 0) {
		ans[n % 10] += ten;
		n = n / 10;
	}
}
void go(vector<long long> &ans, long long start, long long end, long long ten) {
	while (start % 10 != 0 && start <= end) {
		calc(ans, start, ten);
		start += 1;
	}
	if (start > end) return;
	while (end % 10 != 9 && start <= end) {
		calc(ans, end, ten);
		end -= 1;
	}
	long long cnt = (end / 10 - start / 10 + 1);
	for (int i = 0; i <= 9; i++) {
		ans[i] += cnt*ten;
	}
	go(ans, start / 10, end / 10, ten * 10LL);
}
int main() {
	long long n;
	cin >> n;
	vector<long long> ans(10);
	go(ans, 1, n, 1);
	for (int i = 0; i <= 9; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
	return 0;
}
