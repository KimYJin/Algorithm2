#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>
#include<algorithm>
#include<queue>

using namespace std;

int N;	//���� ũ�� NxN
int map[20][20];

struct SHARK {
	int x; int y; int time;
};

SHARK shark; //����� ��ġ
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

			if (map[i][j] == 9)	//��� �ʱ� ��ġ
			{
				shark.y = i; shark.x = j; shark.time = 0;
				shark_size = 2, shark_eat = 0;
				map[i][j] = 0;
			}
		}
	}

	bool is_eat = true;

	while (is_eat)	//���� ����Ⱑ ���� ������ �ݺ�
	{
		is_eat = false;

		bool visited[20][20] = { false, };
		visited[shark.y][shark.x] = true;

		SHARK candi;	//���� �Ÿ��� ����� �����
		candi.y = 20; candi.x = 20; candi.time = -1;

		queue<SHARK> q;	//�� �̵��� ĭ�� ��ġ �� �ҿ�ð�
		q.push(shark);	//�ʱ� ��� ��ġ 

		while (!q.empty())
		{
			//���� �˻��� ĭ�� �����
			SHARK cur = q.front();	q.pop();

			//�̹� ���� ����� ����⸦ �Ծ��ٸ� ���̻� ť �� �ʿ�x
			if (candi.time != -1 && candi.time < cur.time)
				break;

			//���� �� �ִ� �������
			if (map[cur.y][cur.x] != 0 && map[cur.y][cur.x] < shark_size)
			{
				is_eat = true;

				//candi ���� �� ����� ��ġ�� �������
				if (cur.y < candi.y || (cur.y == candi.y && cur.x < candi.x))
				{
					candi = cur;
				}
			}

			//4�������� �̵�
			for (int dir = 0; dir < 4; dir++)
			{
				SHARK next;
				next.y = cur.y + dy[dir]; 
				next.x = cur.x + dx[dir];
				next.time = cur.time+1;

				if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N)
					continue;

				//������ �湮�� ������ ���ũ�⺸�� ���ų� ������ �湮����
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