#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdlib.h>
#include<cstdlib>
#include<math.h>
using namespace std;
vector<int> btns{9,8,7,6,5,4,3,2,1,0};
long long ch;

long long nearest(long long x, long long y)
{
    return abs(x - ch) <= abs(y - ch) ? x : y;
}

int nearest(int x, int y, int c)
{
    return abs(x - c) <= abs(y - c) ? x : y;
}

long long power(int base, int exp)
{
    long long ret = 1;
    while (exp > 0) {
        ret *= base;
        --exp;
    }
    return ret;
}

long long cipher(int cur, int x)
{
    if (cur == 0) return x;
    return power(10, cur) * x;
}

long long normalize(int cpy, int cur, int base)
{
    if (cur == 0) return cpy - base;
    return cpy - power(10, cur) * base;
}

long long comb(const int len, const int base, int cur, long long tmp)
{
    if (len == cur)
        return tmp;
    long long cpy = tmp;
    for (unsigned i = 0; i < btns.size(); ++i)
        tmp = nearest(tmp, comb(len, base, cur + 1, normalize(cpy,cur,base) + cipher(cur, btns[i])));
    return tmp;
}

bool test(int chleft)
{
    for (int i = 0; i < btns.size(); ++i)
        if (btns[i] == chleft) return true;
    return false;
}
int main()
{
	string channel;
	unsigned broken_num, i,j;
	cin >> channel >> broken_num;
	vector<int> brokens(broken_num);
    for (i = 0; i < broken_num; ++i) {
        cin >> j;
        btns.erase(std::remove(btns.begin(), btns.end(), j), btns.end());
    }
    j = channel.length();
    ch = stoll(channel);
    if (ch == 100)
        cout << 0 << "\n";
    else if (btns.size() == 0)
        cout << abs(100 - ch) << endl;
    else {
        int leftmost= btns[0];
        int chleft = channel[0] - '0';
        bool is_exist = test(chleft);
        for (i = 1; i < btns.size(); ++i)
            leftmost = nearest(leftmost, btns[i], chleft);
        long long start = leftmost * power(10, j-1);
        for(i = 0; i < j - 1; ++i)
            start += cipher(i, btns[0]);
        long long result = comb(j-1, btns[0], 0, start);
        //cout << result << endl;

        if (!is_exist) {
            leftmost = btns[btns.size()-1];
            for (int z = btns.size() - 2 ; z >= 0; --z)
                leftmost = nearest(leftmost, btns[z], chleft);
            start = leftmost * power(10, j - 1);
            for (i = 0; i < j - 1; ++i)
                start += cipher(i, btns[0]);
            result = min(result, comb(j - 1, btns[0], 0, start));
        }
        //cout << result << endl;
        cout << abs(result-ch) + j << endl;
    }
	return 0;
}