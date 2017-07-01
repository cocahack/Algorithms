#include<iostream>
#include<vector>
using namespace std;
using board = vector<vector<char>>;
int main()
{
	ios_base::sync_with_stdio(false);
	int N, M, K, H, W, Q, T, x, y, i, j;

	cin >> N >> M;
	board paper(N, vector<char>(M));
	for (i = 0; i < N; ++i)
		for (j = 0; j < M; ++j)
			paper[i][j] = '.';

	cin >> K;
	vector<board> stamps;
	while (K > 0) {
		cin >> H >> W;
		board stamp(H, vector<char>(W));
		for (i = 0; i < H; ++i)
			for (j = 0; j < W; ++j)
				cin >> stamp[i][j];
		stamps.push_back(stamp);
		--K;
	}

	cin >> Q;
	while (Q > 0) {
		cin >> T >> y >> x;
		H = stamps[T - 1].size(), W = stamps[T - 1][0].size();
		for (i = 0; i < H; ++i)
			for (j = 0; j < W; ++j)
				paper[y + i][x + j] = stamps[T - 1][i][j];
		--Q;
	}

	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j)
			cout << paper[i][j];
		cout << "\n";
	}
	return 0;
}