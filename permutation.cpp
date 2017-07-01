#include <iostream>

#define swap(a,b,temp) temp=a; a=b; b=temp;

using namespace std;

int cnt = 0;

void permutations(int *a, const int k, const int m) // k �� ������
													// a[k],...,a[m]�� ���� ��� ������ ����
{
	int i;
	int temp;


	if (k == m) //������ ���
	{
		for (i = 0; i <= m; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		cnt++; // �� ��� ����� ������ Ȯ�� 
	}

	else // a[k] a[m]�� �ִ� ���� ������ ��ȯ������ ����
	{
		for (i = k; i <= m; i++)
		{
			swap(a[k], a[i], temp); // a[k]�� a[i]�� ��ȯ
			permutations(a, k + 1, m); // a[k+1],...a[m]�� ���� ��� ����
									   // ���� ���·� �ǵ����� ���� a[k]�� a[i]�� �ٽ� ��ȯ
			swap(a[k], a[i], temp);
		}

	}
}

int main()
{
	int n;
	int arr[100];

	cout << "������ �̿��� �ڸ� ���� �Է��Ͻÿ� : ";
	cin >> n; // �� ������ ���� �̿����� 

	for (int i = 0; i < n; i++) arr[i] = i+1;

	cout << endl;
	permutations(arr, 0, n - 1); // 0~n-1 ������ ���� �� n�����̴�. 
	printf("�� ���� �� : %d\n", cnt);
}

