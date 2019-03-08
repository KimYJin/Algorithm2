/*
문제 5014
강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다.오늘은 강호의 면접날이다.
하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.
스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 
스타트링크가 있는 곳의 위치는 G층이다.
강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 
강호가 탄 엘리베이터는 버튼이 2개밖에 없다.U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. 
(만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오.
만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.

입력
첫째 줄에 F, S, G, U, D가 주어진다. (1 ≤ S, G ≤ F ≤ 1000000, 0 ≤ U, D ≤ 1000000) 
건물은 1층부터 시작하고, 가장 높은 층은 F층이다.

출력
첫째 줄에 강호가 S층에서 G층으로 가기 위해 눌러야 하는 버튼의 수의 최소값을 출력한다.
만약, 엘리베이터로 이동할 수 없을 때는 "use the stairs"를 출력한다.

예제 입력 복사
10 1 10 2 1

예제 출력 복사
6

예제 입력 2 복사
100 2 1 1 0

예제 출력 2 복사
use the stairs
*/

#include<iostream>
#include<queue>

using namespace std;

const int MAX = 1000000;

bool check[MAX + 1];
int dist[MAX + 1];

int main(void) 
{

	int total, start, goal, up, down;

	cin >> total >> start >> goal >> up >> down;

	queue<int> q;
	q.push(start);
	check[start] = true;
	dist[start] = 0;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == goal)
			break;

		if (now < goal)	//up
		{
			int next = now + up;

			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
			}
		}
		else //down
		{
			int next = now - down;

			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
			}
		}

	}//end while

	if (check[goal] == true)
		cout << dist[goal] << endl;
	else
		cout << "use the stairs" << endl;

	return 0;
}