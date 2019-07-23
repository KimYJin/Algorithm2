/* 
�Ｚ 1861 ���簢�� ��

*/


#include<iostream>
#include<queue>
#include<utility>	
#include<cstdio>

using namespace std;
int start;
const int MAX = 1000;
int A[MAX][MAX] = { 0 };

int dir[4][2] = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };	//�����¿�
int T, N;	//�׽�Ʈ ���̽��� ��, �� = N��N. (1 �� N �� 10^3)

int main(void)
{	
	int max=0;	//�ִ� �� ���� ���� �̵��� �� �ִ���
	int temp;

	cin >> T;

	for(int t=1;t<=T;t++)
	{
		cin >> N;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> A[i][j];
	
		// �� �غ���
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				queue<pair<int, int>> q;
				q.push(make_pair(i,j));
				int count = 0;

				while (!q.empty())
				{
					int pre_f = q.front().first, pre_s = q.front().second;
					count++;
				
					for (int k = 0; k < 4; k++)
					{
						int cur_f = pre_f + dir[k][0], cur_s = pre_s + dir[k][1];
					
						if (cur_f >= 0 && cur_f < N && cur_s >= 0 && cur_s < N)
						{
							if (A[cur_f][cur_s] == A[pre_f][pre_s] + 1)
							{
								q.push(make_pair(cur_f, cur_s));
							}
						}
					}
					q.pop();
				}//end while

				if (max < count)
				{
					max = count;
					start = A[i][j];
				}
			}
		}//end for
		cout << '#' << t << " " << start<<" " <<max<< endl;
	}
	return 0;
}

