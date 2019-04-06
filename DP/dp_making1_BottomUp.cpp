#define _CRT_SECURE_NO_WARNINGS

//���� ���� 1463 https://www.acmicpc.net/problem/1463

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
		// ���� ���������� ������ ������ ��� �� �ּڰ�
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
