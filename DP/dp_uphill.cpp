// 백준 11057 https://www.acmicpc.net/problem/11057
// 오르막 수는 수의 자리가 오름차순을 이루는 수. 
//이때, 인접한 수가 같아도 오름차순으로 친다.

#include<iostream>
using namespace std;
const int MAX = 1000;

long long dp[MAX+1][MAX + 1] = { 0, };

int main(void)
{
	int n;	//길이
	long long result = 0; //길이가 n인 오르막 수의 총 개수

	cin >> n;

	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int curr = 0; curr <= 9; curr++) //시작 수
		{
			for (int pre = curr; pre <= 9; pre++) //그 다음 수는 시작수보다 같거나 커야 함
			{
				dp[i][curr] += dp[i - 1][pre];
			}
			dp[i][curr] %= 10007;
		}
	}

	for (int i = 0; i <= 9; i++) //수는 0으로 시작할 수 있다.
		result += dp[n][i];

	result = result % 10007;
	cout << result;

	return 0;
}

