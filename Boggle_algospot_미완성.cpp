#include<iostream>
#include<vector>
#include<string>
using namespace std;
char board[5][5];
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1,  0,  1,-1, 0, 1,-1, 1 };
bool hasWord(int y, int x, const string& word, int index, int n)
{
	if (board[y][x] != word[index]) return false;
	if (index == n) 
		return true;
	for (int dir = 0; dir < 8; ++dir)
		if (hasWord(y+dy[dir], x+dx[dir], word, index + 1, n))
			return true;
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);

	int C, N, i, j;
	cin >> C;
	char c;
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 5; ++j)
			cin >> board[i][j];
	cin >> N;
	vector<string> strs;
	string str;
	vector<bool> success;
	char head;
	for (int k = 0; k < N; ++k) {
		cin >> str;
		strs.push_back(str);
		success.push_back(false);
		head = str[0];
		for (i = 0; i < 5; ++i) {
			for (j = 0; j < 5; ++j)
				if (head == board[i][j])
					success[k] = hasWord(i, j, str, 0, str.length());
			if (success[k]) break;
		}
	}
	for (i = 0; i < N; ++i) {
		cout << strs[i] << " ";
		if (success[i]) cout << "YES\n";
		else cout<<"NO\n";
	}
	return 0;
}