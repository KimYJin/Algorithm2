/*
���� 5014
��ȣ�� �ڵ� ������ �ϴ� ��ŸƮ�� ��ŸƮ��ũ�� �����ߴ�.������ ��ȣ�� �������̴�.
������, ������ �� ��ȣ�� ��ŸƮ��ũ�� �ִ� �ǹ��� �ʰ� �����ϰ� ���Ҵ�.
��ŸƮ��ũ�� �� F������ �̷���� ���� �ǹ��� �繫���� �ְ�, 
��ŸƮ��ũ�� �ִ� ���� ��ġ�� G���̴�.
��ȣ�� ���� �ִ� ���� S���̰�, ���� ���������͸� Ÿ�� G������ �̵��Ϸ��� �Ѵ�.

���� ���������Ϳ��� � ������ �̵��� �� �ִ� ��ư�� ������, 
��ȣ�� ź ���������ʹ� ��ư�� 2���ۿ� ����.U��ư�� ���� U���� ���� ��ư, D��ư�� �Ʒ��� D���� ���� ��ư�̴�. 
(����, U�� ��, �Ǵ� D�� �Ʒ��� �ش��ϴ� ���� ���� ����, ���������ʹ� �������� �ʴ´�)

��ȣ�� G���� �����Ϸ���, ��ư�� ��� �� �� ������ �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����, ���������͸� �̿��ؼ� G���� �� �� ���ٸ�, "use the stairs"�� ����Ѵ�.

�Է�
ù° �ٿ� F, S, G, U, D�� �־�����. (1 �� S, G �� F �� 1000000, 0 �� U, D �� 1000000) 
�ǹ��� 1������ �����ϰ�, ���� ���� ���� F���̴�.

���
ù° �ٿ� ��ȣ�� S������ G������ ���� ���� ������ �ϴ� ��ư�� ���� �ּҰ��� ����Ѵ�.
����, ���������ͷ� �̵��� �� ���� ���� "use the stairs"�� ����Ѵ�.

���� �Է� ����
10 1 10 2 1

���� ��� ����
6

���� �Է� 2 ����
100 2 1 1 0

���� ��� 2 ����
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