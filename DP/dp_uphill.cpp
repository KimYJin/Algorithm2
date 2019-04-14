// ���� 11057 https://www.acmicpc.net/problem/11057
// ������ ���� ���� �ڸ��� ���������� �̷�� ��. 
//�̶�, ������ ���� ���Ƶ� ������������ ģ��.

#include<iostream>
using namespace std;
const int MAX = 1000;

long long dp[MAX+1][MAX + 1] = { 0, };

int main(void)
{
	int n;	//����
	long long result = 0; //���̰� n�� ������ ���� �� ����

	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int curr = 0; curr <= 9; curr++) //���� ��
		{
			for (int pre = curr; pre <= 9; pre++) //�� ���� ���� ���ۼ����� ���ų� Ŀ�� ��
			{
				dp[i][curr] += dp[i - 1][pre];
			}
			dp[i][curr] %= 10007;
		}
	}

	for (int i = 0; i <= 9; i++) //���� 0���� ������ �� �ִ�.
		result += dp[n][i];

	result = result % 10007;
	cout << result;

	return 0;
}

