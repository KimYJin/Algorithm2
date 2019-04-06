#define _CRT_SECURE_NO_WARNINGS

//백준 문제 1463 https://www.acmicpc.net/problem/1463

#include <stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000000+1];

int main()
{
	int n,temp1,temp2,temp3;
	cin >> n;
	
	dp[1] = 0;

	//Bottom-up
	for (int i = 2; i <= n; i++)
	{		
		// 값이 정해져있지 않으면 가능한 방법 중 최솟값
		dp[i] = dp[i - 1]+1;

		if (i % 3 == 0 && dp[i] > dp[i/3]+1)
			dp[i] = dp[i / 3]+1;
		
		if (i % 2 == 0 && dp[i] > dp[i/2] + 1)
			dp[i] = dp[i / 2]+1;
	}

	cout << dp[n];

	for (;;);
	return 0;
}
