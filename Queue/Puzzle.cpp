/*
문제 1525 퍼즐 풀이

3 * 3 표에 다음과 같이 수가 채워져 있다.오른쪽 아래 가장 끝 칸은 비어 있는 칸이다.

1 2 3
4 5 6
7 8

어떤 수와 인접해 있는 네 개의 칸 중에 하나가 비어 있으면, 수를 그 칸으로 이동시킬 수가 있다.
물론 표 바깥으로 나가는 경우는 불가능하다.
우리의 목표는 초기 상태가 주어졌을 때, 최소의 이동으로 위와 같은 정리된 상태를 만드는 것이다.다음의 예를 보자.

1   3
4 2 5
7 8 6

1 2 3
4   5
7 8 6

1 2 3
4 5
7 8 6

1 2 3
4 5 6
7 8

가장 윗 상태에서 세 번의 이동을 통해 정리된 상태를 만들 수 있다.이와 같이 최소 이동 횟수를 구하는 프로그램을 작성하시오.

입력
세 줄에 걸쳐서 표에 채워져 있는 아홉 개의 수가 주어진다.한 줄에 세 개의 수가 주어지며, 빈 칸은 0으로 나타낸다.

출력
첫째 줄에 최소의 이동 횟수를 출력한다.이동이 불가능한 경우 - 1을 출력한다.

예제 입력 복사
1 0 3
4 2 5
7 8 6

예제 출력 복사
3
*/

#include<iostream>
#include<queue>
#include<map>
#include<string>

using namespace std;


//상(0,1), 하(0,-1), 우(1,0), 좌(-1,0) 
int dx[] = {0,0,1,-1 };
int dy[] = {1,-1,0,0, };

int main(void)
{
	int start = 0;
	int n = 3;

	for (int i = 0; i < n*n; i++)
	{
		int temp;
		cin >> temp;

		//빈칸을 0 이 아닌 9로 바꿔주기
		if (temp == 0)
			temp = 9;

		start = start * 10 + temp;
	}

	queue<int> q;
	q.push(start);

	map<int, int> dist;
	dist[start] = 0;

	while (!q.empty())
	{
		//빈 칸 위치 찾기
		int now_n = q.front();
		q.pop();
		string now_s = to_string(now_n);
		int z = now_s.find('9');
			
		int x = z / n;		//n*n 배열에서의 (x,y)의 x. 여기서 n=3
		int y = z % n;		//n*n 배열에서의 (x,y)의 y. 여기서 n=3

		//퍼즐 위 빈칸의 상,하,좌,우에 위치한 숫자를 빈칸으로 이동
		//상(0,1), 하(0,-1), 우(1,0), 좌(-1,0) 
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			//퍼즐 판을 넘어가지 않는지 검사
			if (nx >= 0 && nx < n  && ny >= 0 && ny < n)
			{
				//// 2차원 배열 상의(x,y)를 1차원 배열의 위치로 바꾸기(x*n+y). (여기서 n=3)
				string next_s = now_s;
				swap(next_s[x*n+y], next_s[nx * n + ny]);	//n=3;
				
				int next_n = stoi(next_s);
				
				if (dist.count(next_n) == 0) {
					q.push(next_n);
					dist[next_n] = dist[now_n] + 1;
				}
			}
		}

	}//end while

	if (dist.count(123456789) == 0)
		cout << '-1' << endl;
	else
		cout << dist[123456789]<<endl;

	return 0;
}

