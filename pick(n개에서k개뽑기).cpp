#include <iostream>
#include <vector>
using namespace std;
void pick(int n, vector<vector<int>>& list, vector<int>& picked, int toPick)
{
	if (toPick == 0) {
		list.push_back(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, list, picked, toPick - 1);
		picked.pop_back();
	}
}

int main()
{
	vector<vector<int>> list;
	vector<int> picked;
	pick(7, list, picked, 4);
	for (int i = 0; i < list.size(); ++i) {
		for (int j = 0; j < list[0].size(); ++j) {
			cout << list[i][j];
			if (j != list[0].size() - 1)
				cout << ", ";
		}
		cout << "\n";
	}
	return 0;
}