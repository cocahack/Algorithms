#include <iostream>
using namespace std;
int triangle[500][500] = { 0, };
int dp[500][500] = { 0, };
int maximum = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, i, j;
	cin >> N ;
	for (i = 0; i < N; ++i)
		for (j = 0; j < i + 1; ++j)
			cin >> triangle[i][j];
	dp[0][0] = triangle[0][0];
	for(i=0; i< N-1;++i)
		for (j = 0; j < i + 1; ++j) {
			if (dp[i + 1][j] < dp[i][j] + triangle[i + 1][j])
				dp[i + 1][j] = dp[i][j] + triangle[i + 1][j];
			if (dp[i + 1][j + 1] < dp[i][j] + triangle[i + 1][j + 1])
				dp[i + 1][j + 1] = dp[i][j] + triangle[i + 1][j + 1];
		}

	int max = 0;
	for (i = 0; i < N; ++i)
		if (dp[N - 1][i] > max)
			max = dp[N - 1][i];
	cout << max;
	return 0;
}

//int main()
//{
//	int N, i, j;
//	long long num[501][501] = { 0, };
//	long long dp[501][501] = { 0, };
//	scanf("%d", &N);
//	for (i = 0; i < N; ++i)
//		for (j = 0; j < i + 1; ++j)
//			scanf("%lld", &num[i][j]);
//
//	dp[0][0] = num[0][0];
//	for (i = 0; i < N - 1; ++i)
//		for (j = 0; j < i + 1; ++j) {
//			if (dp[i + 1][j] < dp[i][j] + num[i + 1][j])
//				dp[i + 1][j] = dp[i][j] + num[i + 1][j];
//			if (dp[i + 1][j + 1] < dp[i][j] + num[i + 1][j + 1])
//				dp[i + 1][j + 1] = dp[i][j] + num[i + 1][j + 1];
//		}
//	long long max = 0;
//	for (int i = 0; i < N; i++) {
//		if (dp[N - 1][i] > max)
//			max = dp[N - 1][i];
//	}
//	printf("%lld\n", max);
//	return 0;
//}