#include<iostream>
#include<vector>
#include<iomanip>
#include<string.h>
#define INIT 2000
using namespace std;
double winRT[3];
int scoreAdd[3] = { 50, -50,0 };
double dp[21][21][21];
typedef struct probaObj{
	double proba;
	int count;
	probaObj() :proba{ 0.0 }, count{ 0 } {}
} probObj;
int myTier(int score)
{
	if (score >= 3000) return 4;
	else if (score >= 2500) return 3;
	else if (score >= 2000) return 2;
	else if (score >= 1500) return 1;
	else return 0;
}
double calc(double acc, int count, int win, int lose, int type)
{
	if (count == 20) {
		dp[count][win][lose] = acc * ;
	}
	if(dp[count][win][lose] == 0.0)
		dp[count][win][lose] = 
}
int main()
{
	memset(dp, 0, sizeof(double) * 21 * 21 * 21);
	cin >> winRT[0] >> winRT[1] >> winRT[2];
	for(int i=0; i)
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(8);
	return 0;
}