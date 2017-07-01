#include<iostream>
#include<vector>
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
const char linked[SWITCHES][CLOCKS + 1] =
{
	"xxx............."
	,"...x...x.x.x...."
	,"....x.....x...xx"
	,"x...xxxx........"
	,"......xxx.x.x..."
	,"x.x...........xx"
	,"...x..........xx"
	,"....xx.x......xx"
	,".xxxxx.........."
	,"...xxx...x...x.."
};

bool check_end(const vector<int>& clocks)
{
	for (int i = 0; i < CLOCKS; ++i)
		if (clocks[i] != 12) return false;
	return true;
}

namespace custom {
	template<typename T>
	inline T min(const T& left, const T& right)
	{
		return left <= right ? left : right;
	}
}

void push(vector<int>& clocks, int swt)
{
	for(int i=0; i < CLOCKS; ++i)
		if (linked[swt][i] == 'x') {
			clocks[i] += 3;
			if (clocks[i] == 15) clocks[i] %= 12;
		}
}

int solve(vector<int>& clocks, int swt)
{
	if (swt == SWITCHES) return check_end(clocks) ? 0 : INF;
	int ret = INF;
	for (int i = 0; i < 4; ++i) {
		ret = custom::min(ret, i + solve(clocks, swt + 1));
		push(clocks, swt);
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;
	int answer = 0;
	while (T > 0)
	{
		vector<int> clocks(16);
		for (int i = 0; i < CLOCKS; ++i)
			cin >> clocks[i];
		answer = solve(clocks, 0);
		cout << (answer == INF ? -1 : answer) << "\n";
		--T;
	}
	return 0;
}