#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int direction[4][2] =
{
    0, -1
    ,1, 0
    ,0, 1
    ,-1, 0
};
int vis[55][55];
int dp[55][55];
int N, M;
bool cycle = false;
bool out_of_board(const int y, const int x)
{
    return y < 0 || y >= N || x < 0 || x >= M;
}
void dfs(const vector<vector<int>>& board, int y, int x)
{
    vis[y][x] = -1;
    if (board[y][x] == -1) {
        vis[y][x] = 1;
        return;
    }
    
    for (int i = 0; i < 4; ++i) {
        int k = board[y][x];
        int ny = y + direction[i][0] * k;
        int nx = x + direction[i][1] * k;
        if (0 <= ny && ny<N && 0 <= nx && nx<M) {
            if (vis[ny][nx] == -1) {
                cycle = true;
                return;
            }
            else if (!vis[ny][nx]) {
                dfs(board, ny, nx);
            }
        }
    }
    vis[y][x] = 1;
}
int move(const vector<vector<int>>& board, int y, int x)
{
    if (out_of_board(y, x))
        return 0;
    if (board[y][x] == -1)
        return 0;
    int& ret = dp[y][x];
    if (ret) return ret;
    ret = 1;
    int i, distance = board[y][x];
    for (int i = 0; i < 4; ++i)
        ret = max(ret, 1 + move(board, y + direction[i][0] * distance, x + direction[i][1] * distance));
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    memset(dp, 0, sizeof(int)*55*55);
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));
    int i, j;
    char ch = 0;
    for(i = 0; i < N; ++i)
        for (j = 0; j < M; ++j) {
            cin >> ch;
            if(ch == 'H') board[i][j] = -1;
            else board[i][j] = ch - '0';
        }
    dfs(board, 0, 0);
    if (cycle) cout << -1 << "\n";
    else cout << move(board, 0, 0) << "\n";
    return 0;
}