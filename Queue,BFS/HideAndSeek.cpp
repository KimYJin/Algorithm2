#include <iostream> 
/*
���� 1697 ���ٲ���

�����̴� ������ ���ٲ����� �ϰ� �ִ�.
�����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�,
������ �� K(0 �� K �� 100,000)�� �ִ�.
�����̴� �Ȱų� �����̵��� �� �� �ִ�.
����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�.
�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��,
�����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.

���� �Է� ����
5 17

���� ��� ����
4
*/

#include <iostream>
#include <queue> 
using namespace std;
const int MAX = 200000;
bool check[MAX + 1];
int dist[MAX + 1];
int main() {
	int n, m;
	cin >> n >> m;
	check[n] = true;
	dist[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if (now + 1 < MAX) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if (now * 2 < MAX) {
			if (check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
	}
	cout << dist[m] << '\n';
	//return 0;
	for (;;);
}

