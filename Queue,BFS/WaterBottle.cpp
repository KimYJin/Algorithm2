/*
문제 2251
각각 부피가 A, B, C(1≤ A, B, C ≤200) 리터인 세 개의 물통이 있다.
처음에는 앞의 두 물통은 비어 있고, 세 번째 물통은 가득(C 리터) 차 있다.
이제 어떤 물통에 들어있는 물을 다른 물통으로 쏟아 부을 수 있는데, 이 때에는 한 물통이 비거나,
다른 한 물통이 가득 찰 때까지 물을 부을 수 있다. 이 과정에서 손실되는 물은 없다고 가정한다.
이와 같은 과정을 거치다보면 세 번째 물통(용량이 C인)에 담겨있는 물의 양이 변할 수도 있다.
첫 번째 물통(용량이 A인)이 비어 있을 때,
세 번째 물통(용량이 C인)에 담겨있을 수 있는 물의 양을 모두 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 세 정수 A, B, C가 주어진다.

출력
첫째 줄에 공백으로 구분하여 답을 출력한다. 각 용량은 오름차순으로 정렬한다.

예제 입력 복사
8 9 10

예제 출력 복사
1 2 8 9 10
*/

#include<iostream>
#include<queue>

using namespace std;

const int MAX = 200;

int from[] = { 0,0,1,1,2,2 };
int to[] = { 1,2,0,2,0,1 };

bool check[MAX+ 1][MAX+1];	// 물통 A와 물통 B에 담긴 물의 양
bool ans[MAX + 1];	// 물통 C에 담겨있을 수 있는 물의 양의 모든 케이스

int main(void)
{
	//물통 A,B,C 각각의 부피
	int v[3];
	cin >> v[0] >>v[1]>> v[2];

	//물통에 담긴 물의 양
	int now[3] = { 0,0,v[2] };
	
	//총 물의 양.
	int sum = now[2];

	//물통 A와 B에 담긴 물의 양을 큐에 넣어줌.(C의 물의양은 sum에서 A,B의 물의양을 뺀 양)
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));		//짝을 만들어주어 queue에 넣는 것 몰랐음. 

	check[0][0] = true;	// 빼먹은 부분
	ans[now[2]] = true;

	while (!q.empty())
	{
		now[0] = q.front().first;	/////
		now[1] = q.front().second;	/////
		now[2] = sum - now[0] - now[1];

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int next[3] = { now[0],now[1],now[2] };

			//from 물통의 물을 to물통에 옮긴 후 from물통의 물의 양이 0이 되는 경우.
			if (now[from[i]] + now[to[i]] <= v[to[i]])
			{
				next[to[i]] = now[from[i]]+ now[to[i]];
				next[from[i]] = 0;
			}
			//from 물통의 물을 to물통에 옮긴 후 from물통의 물의 양이 남는 경우.
			else
			{
				next[to[i]] = v[to[i]];
				next[from[i]] = now[from[i]] - (v[to[i]]- now[to[i]]);
			}

			if (check[next[0]][next[1]] == false)
			{
				check[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				//A 물통이 비어 있을 때,
				//C 물통에 담겨있을 수 있는 물의 양
				if (next[0] == 0 && ans[next[2]]==false)
				{
					ans[next[2]] = true;
				}
			}
		} // end for
	} // end while

	for (int i = 0; i <= v[2]; i++)
	{
		if (ans[i] == true)
			cout << i << ' ';
	}

	return 0;
}