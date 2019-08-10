#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int home[17][17] = { 0 };
	int d[17][17][3] = { 0 };	//가로,세로,방향

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> home[i][j];
	
		}
	}

	d[1][2][0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (home[i][j] == 0)
			{
				//가로or대각선->가로
				d[i][j][0] += d[i][j - 1][0] + d[i][j - 1][2];

				//세로or대각선->세로
				d[i][j][1] += d[i - 1][j][1] + d[i - 1][j][2];

				//가로or세로or대각선->대각선
				if(home[i][j-1]==0 && home[i-1][j]==0)	//대각선이 놓일 수 있는지 검사
					d[i][j][2] += d[i-1][j - 1][0] + d[i - 1][j-1][1] + d[i - 1][j - 1][2];
			}
		}
	}
	
	cout << d[n][n][0]+d[n][n][1]+d[n][n][2];
	
	return 0;
}

