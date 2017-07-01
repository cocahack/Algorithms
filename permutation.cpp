#include <iostream>

#define swap(a,b,temp) temp=a; a=b; b=temp;

using namespace std;

int cnt = 0;

void permutations(int *a, const int k, const int m) // k 는 시작점
													// a[k],...,a[m]에 대한 모든 순열을 생성
{
	int i;
	int temp;


	if (k == m) //순열을 출력
	{
		for (i = 0; i <= m; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		cnt++; // 총 몇가지 경우의 수인지 확인 
	}

	else // a[k] a[m]에 있는 여러 순열을 순환적으로 생성
	{
		for (i = k; i <= m; i++)
		{
			swap(a[k], a[i], temp); // a[k]와 a[i]를 교환
			permutations(a, k + 1, m); // a[k+1],...a[m]에 대한 모든 순열
									   // 원래 상태로 되돌리기 위해 a[k]와 a[i]를 다시 교환
			swap(a[k], a[i], temp);
		}

	}
}

int main()
{
	int n;
	int arr[100];

	cout << "순열에 이용할 자리 수를 입력하시오 : ";
	cin >> n; // 몇 가지의 수를 이용할지 

	for (int i = 0; i < n; i++) arr[i] = i+1;

	cout << endl;
	permutations(arr, 0, n - 1); // 0~n-1 까지의 수는 총 n가지이다. 
	printf("총 가짓 수 : %d\n", cnt);
}

