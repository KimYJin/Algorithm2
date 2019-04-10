//백준 문제 11726 https://www.acmicpc.net/problem/11726

#include <iostream>
using namespace std;
const int MAX = 1000;
int dp[MAX + 1] = { 0, };

int func(int );

int main(void) {
	int n;
	cin >> n;
	cout << func(n)%10007;
	return 0;
}

int func(int x)
{
	if (x < 0)
		return 0;
	else if (x == 0 || x == 1)
		dp[x] = 1;
	else if (dp[x] == 0)	//dp[x]!=0인 경우 바로 return dp[x]
		//dp[x] = (func(x - 2) + func(x - 1)) % 10007;
		dp[x] = func(x - 2) + func(x - 1);
	return dp[x];
}