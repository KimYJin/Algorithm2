#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

int N;	//공간 크기 NxN
int map[20][20];

struct SHARK {
	int x; int y; int time;
};

SHARK shark; //상어의 위치
int shark_size, shark_eat;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { -1,1,0,0 };

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 9)	//상어 초기 위치
			{
				shark.y = i; shark.x = j; shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[i][j] = 0;
			}
		}
	}

	bool is_eat = true;

	while (is_eat)	//먹은 물고기가 있을 때까지 반복
	{
		is_eat = false;

		bool visited[20][20] = { false, };
		visited[shark.y][shark.x] = true;

		SHARK candi;	//가장 거리가 가까운 물고기
		candi.y = 20; candi.x = 20; candi.time = -1;

		queue<SHARK> q;	//상어가 이동할 칸의 위치 및 소요시간
		q.push(shark);	//초기 상어 위치 

		while (!q.empty())
		{
			//현재 검사할 칸의 물고기
			SHARK cur = q.front();	q.pop();

			//이미 가장 가까운 물고기를 먹었다면 더이상 큐 돌 필요x
			if (candi.time != -1 && candi.time < cur.time)
				break;

			//먹을 수 있는 물고기라면
			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < shark_size)
			{
				is_eat = true;

				//candi 보다 더 가까운 위치의 물고기라면
				if (cur.y < candi.y || (cur.y == candi.y && cur.x < candi.x))
				{
					candi = cur;
				}
			}

			//4방향으로 이동
			for (int dir = 0; dir < 4; dir++)
			{
				SHARK next;
				next.y = cur.y + dy[dir]; 
				next.x = cur.x + dx[dir];
				next.time = cur.time+1;

				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)
					continue;

				//이전에 방문한 적없고 상어크기보다 같거나 작으면 방문가능
				if (visited[next.y][next.x] == false && map[next.y][next.x] <=shark_size)
				{
					q.push(next);
					visited[next.y][next.x] = true;
				}
				
			}
	
		}//end while(!q.empty())

		if (is_eat)
		{
			shark = candi;
			++shark_eat;

			if (shark_size == shark_eat) 
			{
				++shark_size;
				shark_eat = 0;
			}

			map[shark.y][shark.x] = 0;
		}

	}//end while(is_eat)

	cout << shark.time;

	return 0;
}