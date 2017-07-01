#include<iostream>
#include<vector>
using namespace std;
using arr = vector<vector<int>>;
void init(arr& a, int r, int c) {
	for(int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j)
			cin >> a[i][j];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int N, M, K, i, j, k, t, acc;
	cin >> N >> M;
	arr A(N, vector<int>(M));
	init(A, N, M);
	cin >> M >> K;
	arr B(M, vector<int>(K));
	init(B, M, K);
	arr result(N, vector<int>(K));
	acc = 0;
	for (i = 0; i < N; ++i) {
		for (k = 0; k < M; ++k) {
			t = A[i][k];
			for (j = 0; j < K; ++j) {
				result[i][j] += t * B[k][j];
			}
		}
	}
	for (i = 0; i < N; ++i){
		for (j = 0; j < K; ++j)
			cout << result[i][j] << " ";
		cout << "\n";
	}
}