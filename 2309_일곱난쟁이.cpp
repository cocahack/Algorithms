#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool finish = false;
bool test(vector<int>& v)
{
	int acc = 0;
	for (int i = 0; i < 7; ++i)
		acc += v[i];
	if (acc == 100)
		return true;
	else return false;
}

void printdwarf(vector<int>& v)
{
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
}

int main()
{
	vector<int> H;
	int h, i, j, k, d = 9;
	while (d > 0) {
		cin >> h;
		H.push_back(h);
		--d;
	}
	sort(H.begin(), H.end());
	for (i = 0; i < 9; ++i) {
		for (j = 0; j < 9; ++j) {
			if (i == j) continue;
			vector<int> v;
			for (int k = 0; k < 9; ++k) {
				if (k == i || k == j) continue;
				v.push_back(H[k]);
			}
			if (test(v)) {
				printdwarf(v);
				goto stop;
			}
		}
	}
	stop:
	return 0;
}