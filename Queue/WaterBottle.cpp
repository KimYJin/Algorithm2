/*
���� 2251
���� ���ǰ� A, B, C(1�� A, B, C ��200) ������ �� ���� ������ �ִ�.
ó������ ���� �� ������ ��� �ְ�, �� ��° ������ ����(C ����) �� �ִ�.
���� � ���뿡 ����ִ� ���� �ٸ� �������� ��� ���� �� �ִµ�, �� ������ �� ������ ��ų�,
�ٸ� �� ������ ���� �� ������ ���� ���� �� �ִ�. �� �������� �սǵǴ� ���� ���ٰ� �����Ѵ�.
�̿� ���� ������ ��ġ�ٺ��� �� ��° ����(�뷮�� C��)�� ����ִ� ���� ���� ���� ���� �ִ�.
ù ��° ����(�뷮�� A��)�� ��� ���� ��,
�� ��° ����(�뷮�� C��)�� ������� �� �ִ� ���� ���� ��� ���س��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� A, B, C�� �־�����.

���
ù° �ٿ� �������� �����Ͽ� ���� ����Ѵ�. �� �뷮�� ������������ �����Ѵ�.

���� �Է� ����
8 9 10

���� ��� ����
1 2 8 9 10
*/

#include<iostream>
#include<queue>

using namespace std;

const int MAX = 200;

int from[] = { 0,0,1,1,2,2 };
int to[] = { 1,2,0,2,0,1 };

bool check[MAX+ 1][MAX+1];	// ���� A�� ���� B�� ��� ���� ��
bool ans[MAX + 1];	// ���� C�� ������� �� �ִ� ���� ���� ��� ���̽�

int main(void)
{
	//���� A,B,C ������ ����
	int v[3];
	cin >> v[0] >>v[1]>> v[2];

	//���뿡 ��� ���� ��
	int now[3] = { 0,0,v[2] };
	
	//�� ���� ��.
	int sum = now[2];

	//���� A�� B�� ��� ���� ���� ť�� �־���.(C�� ���Ǿ��� sum���� A,B�� ���Ǿ��� �� ��)
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));		//¦�� ������־� queue�� �ִ� �� ������. 

	check[0][0] = true;	// ������ �κ�
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

			//from ������ ���� to���뿡 �ű� �� from������ ���� ���� 0�� �Ǵ� ���.
			if (now[from[i]] + now[to[i]] <= v[to[i]])
			{
				next[to[i]] = now[from[i]]+ now[to[i]];
				next[from[i]] = 0;
			}
			//from ������ ���� to���뿡 �ű� �� from������ ���� ���� ���� ���.
			else
			{
				next[to[i]] = v[to[i]];
				next[from[i]] = now[from[i]] - (v[to[i]]- now[to[i]]);
			}

			if (check[next[0]][next[1]] == false)
			{
				check[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				//A ������ ��� ���� ��,
				//C ���뿡 ������� �� �ִ� ���� ��
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