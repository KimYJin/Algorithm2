#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

int Y, X, T;
int map[2][50][50];

int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int m_y1=0, m_y2;

void spread(int cur) {
	int next = (cur + 1) % 2;
	//1.미세먼지 확산

	//확산 전 map[next] 초기화
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (map[cur][y][x] == -1) {
				map[next][y][x] = -1;
			}
			else {
				map[next][y][x] = 0;
			}
		}
	}

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			
			//공기청정기나 빈 공간이면 무시
			if (map[cur][y][x] <= 0)
				continue;
				
			int dust = map[cur][y][x] / 5;
			int sum = 0;

			for (int dir = 0; dir < 4; dir++)
			{
				int next_y = y + dy[dir];
				int next_x = x + dx[dir];

				if (next_y < 0 || next_y >= Y || next_x < 0 || next_x >= X)
					continue;

				if (map[next][next_y][next_x] != -1)
				{
					map[next][next_y][next_x] += dust;
					sum += dust;
				}
			}//end 확산

			 //확산 후
			if (map[next][y][x] != -1)
				map[next][y][x] += (map[cur][y][x] - sum);
		}
	}
}

void move(int cur)
{
	//2. 공기청정기 작동
	//2-1.반시계방향
	for (int y = m_y1 - 1; y > 0; y--)
	{
		map[cur][y][0] = map[cur][y - 1][0];
	}
	for (int x = 0; x < X - 1; x++)
	{
		map[cur][0][x] = map[cur][0][x + 1];
	}
	for (int y = 0; y < m_y1; y++)
	{
		map[cur][y][X - 1] = map[cur][y + 1][X - 1];
	}
	for (int x = X - 1; x >1; x--)
	{
		map[cur][m_y1][x] = map[cur][m_y1][x - 1];
	}

	map[cur][m_y1][1] = 0;		//정화된 공기
	
	//2-2.
	for (int y = m_y2 + 1; y <Y - 1; y++)
	{
		map[cur][y][0] = map[cur][y + 1][0];
	}
	for (int x = 0; x < X - 1; x++)
	{
		map[cur][Y - 1][x] = map[cur][Y - 1][x + 1];
	}
	for (int y = Y - 1; y > m_y2; y--)
	{
		map[cur][y][X - 1] = map[cur][y - 1][X - 1];
	}
	for (int x = X - 1; x >1; x--)
	{
		map[cur][m_y2][x] = map[cur][m_y2][x - 1];
	}
	map[cur][m_y2][1] = 0;	//정화된 공기
}

int main(){

	cin >> Y >> X >> T;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			cin >> map[0][y][x];

			if (map[0][y][x] == -1) {
				if (m_y1 != 0)	{
					m_y2 = y; 
				}
				else {
					m_y1 = y; 
				}
			}
		}
	}

	int cur = 0;
	while (T--)
	{
		//0과 1 번갈아가며
		spread(cur);

		cur = (cur + 1) % 2;
		move(cur);
		

	}//end while(T--)

	int total=0;
	
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (map[cur][y][x] != -1)
			{
				total += map[cur][y][x];
			}

		}
	}
	cout << total;


	return 0;
}