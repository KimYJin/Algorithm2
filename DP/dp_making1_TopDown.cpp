//백준 문제 1463 https://www.acmicpc.net/problem/1463

#include <iostream>
using namespace std;
const int MAX = 1000000;
int dp[MAX + 1] = { 0, };

int func(int );

int main(void) {
	int n;
	cin >> n;

	cout << func(n);
	return 0;
}

int func(int x)
{
	if (x <= 1)
		return 0;

	if (dp[x] > 0)
		return dp[x];

	if (x > 1)
		dp[x] = func(x - 1) + 1;

	if (x % 3 == 0 && dp[x] > func(x / 3) + 1)
		dp[x] = func(x / 3) + 1;

	if (x % 2 == 0 && dp[x] > func(x / 2) + 1)
		dp[x] = func(x / 2) + 1;

	cout << x << " : " << dp[x] << endl;

	return dp[x];
}