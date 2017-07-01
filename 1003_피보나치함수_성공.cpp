#include<iostream>
#include<string.h>
using namespace std;
using ll = long long;
ll dp[41][2];

int fib(int n, int i)
{
	if (n == 0) { 
		if(i == 0)
			return 1;
		else return 0;
	}
	if (n == 1) {
		if (i == 1)
			return 1;
		else return 0;
	}
	if (i == 0) {
		if(dp[n][0] != 0)
			return dp[n][0];
		else
			return dp[n][0] = fib(n - 1, 0) + fib(n - 2, 0);
	}
	if (i == 1) {
		if(dp[n][1] != 0)
			return dp[n][1];
		else
			return dp[n][1] = fib(n - 1, 1) + fib(n - 2, 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	memset(dp, 0, sizeof(ll) * 40);
	dp[0][0] = 1; dp[0][1] = 0;
	dp[1][0] = 0; dp[1][1] = 1;
	int T, N;
	cin >> T;
	while (T > 0) {
		cin >> N;
		cout << fib(N, 0) << " " << fib(N, 1) << "\n";
		--T;
	}
	return 0;
}