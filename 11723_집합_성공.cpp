#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
	int M, val;
	scanf("%d", &M);
	bool sets[21];
	memset(sets, 0, sizeof(sets[0]) * 21);
	while (M > 0) {
		char str[7];
		scanf("%s", str);
		if (str[0] == 'a') {
			if (str[1] == 'd') {
				scanf("%d", &val);
				sets[val] = 1;
			}
			else memset(sets, 1, sizeof(sets[0]) * 21);
		}
		else if (str[0] == 'r') {
			scanf("%d", &val);
			sets[val] = 0;
		}
		else if (str[0] == 'c') {
			scanf("%d", &val);
			printf("%d\n", sets[val]);
		}
		else if (str[0] == 't') {
			scanf("%d", &val);
			sets[val] ^= 0x1;
		}
		else if (str[0] == 'e') 
			memset(sets, 0, sizeof(sets[0]) * 21);
		--M;
	}
	return 0;
}