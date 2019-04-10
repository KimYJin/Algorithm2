//백준 문제 11727 https://www.acmicpc.net/problem/11727

#include <iostream>
using namespace std;
const int MAX = 1000;
int dp[MAX + 1] = { 0, };

int main(void) {
	int n;
	cin >> n;
	 
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		if (dp[i] == 0)
		{
			dp[i] = dp[i - 2] + dp[i - 1]+dp[i-2];
			dp[i] = dp[i] % 10007;
		}
	}

	cout<< dp[n];
	return 0;
}
