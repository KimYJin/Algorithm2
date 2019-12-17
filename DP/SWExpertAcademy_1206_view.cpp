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
	int d[17][17][3] = { 0 };	//����,����,����

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
				//����or�밢��->����
				d[i][j][0] += d[i][j - 1][0] + d[i][j - 1][2];

				//����or�밢��->����
				d[i][j][1] += d[i - 1][j][1] + d[i - 1][j][2];

				//����or����or�밢��->�밢��
				if(home[i][j-1]==0 && home[i-1][j]==0)	//�밢���� ���� �� �ִ��� �˻�
					d[i][j][2] += d[i-1][j - 1][0] + d[i - 1][j-1][1] + d[i - 1][j - 1][2];
			}
		}
	}
	
	cout << d[n][n][0]+d[n][n][1]+d[n][n][2];
	
	return 0;
}

