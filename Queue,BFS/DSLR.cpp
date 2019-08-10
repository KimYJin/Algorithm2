/*
���� 9019

�� ���� ��ɾ� D, S, L, R �� �̿��ϴ� ������ ���Ⱑ �ִ�. �� ���⿡�� �������Ͱ� �ϳ� �ִµ�,
�� �������Ϳ��� 0 �̻� 10,000 �̸��� �������� ������ �� �ִ�.�� ��ɾ�� �� �������Ϳ� ����� n�� ������ ���� ��ȯ�Ѵ�.
n�� �� �ڸ����� d1, d2, d3, d4��� ����(�� n = ((d1 �� 10 + d2) �� 10 + d3) �� 10 + d4��� ����)

1.D: D �� n�� �� ��� �ٲ۴�.��� ���� 9999 ���� ū ��쿡�� 10000 ���� ���� �������� ���Ѵ�.
�� ��� ��(2n mod 10000)�� �������Ϳ� �����Ѵ�.
2.S : S �� n���� 1 �� �� ��� n - 1�� �������Ϳ� �����Ѵ�. n�� 0 �̶�� 9999 �� ��� �������Ϳ� ����ȴ�.
3.L : L �� n�� �� �ڸ����� �������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.
�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d2, d3, d4, d1�� �ȴ�.
4.R : R �� n�� �� �ڸ����� ���������� ȸ������ �� ����� �������Ϳ� �����Ѵ�.
�� ������ ������ �������Ϳ� ����� �� �ڸ����� ������� d4, d1, d2, d3�� �ȴ�.

������ ����� ��ó��, L �� R ��ɾ�� ���� �ڸ����� �����ϰ� ������ �����Ѵ�.
���� �� n = 1234 ��� ���⿡ L �� �����ϸ� 2341 �� �ǰ� R �� �����ϸ� 4123 �� �ȴ�.

�������� �ۼ��� ���α׷��� �־��� ���� �ٸ� �� ���� A�� B(A �� B)�� ���Ͽ� A�� B�� �ٲٴ� �ּ����� ��ɾ �����ϴ� ���α׷��̴�.
���� �� A = 1234, B = 3412 ��� ������ ���� �� ���� ��ɾ �����ϸ� A�� B�� ��ȯ�� �� �ִ�.

1234 ��L 2341 ��L 3412
1234 ��R 4123 ��R 3412

���� �������� ���α׷��� �� ��쿡 LL �̳� RR �� ����ؾ� �Ѵ�.
n�� �ڸ����� 0 �� ���Ե� ��쿡 �����ؾ� �Ѵ�.���� �� 1000 �� L �� �����ϸ� 0001 �� �ǹǷ� ����� 1 �� �ȴ�.
�׷��� R �� �����ϸ� 0100 �� �ǹǷ� ����� 100 �� �ȴ�.

�Է�
���α׷� �Է��� T ���� �׽�Ʈ ���̽��� �����ȴ�.�׽�Ʈ ���̽� ���� T �� �Է��� ù �ٿ� �־�����.
�� �׽�Ʈ ���̽��δ� �� ���� ���� A�� B(A �� B)�� �������� �и��Ǿ� ���ʷ� �־����µ�
A�� ���������� �ʱ� ���� ��Ÿ���� B�� ���� ���� ��Ÿ����.A �� B�� ��� 0 �̻� 10, 000 �̸��̴�.

���
A���� B�� ��ȯ�ϱ� ���� �ʿ��� �ּ����� ��ɾ� ������ ����Ѵ�.

���� �Է� ����
3
1234 3412
1000 1
1 16

���� ��� ����
LL
L
DDDD
*/


#include<iostream>
#include<queue>
#include<string>

using namespace std;

const int MAX = 10000;

int from[MAX + 1];
char how[MAX + 1];
bool check[MAX + 1];

int main(void)
{
	int t,a,b;
	int now, next;

	cin >> t;

	while (t--)
	{
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		memset(check, false, sizeof(check));

		cin >> a >> b;

		queue<int> q;
		q.push(a);
		check[a] = true;
		from[a] = -1;
		
		while (!q.empty())
		{
			now = q.front();
			q.pop();

			// D
			next = (now * 2) % 10000;
			
			if (check[next] != true)
			{
				q.push(next);
				check[next] = true;
				how[next] = 'D';
				from[next] = now;
			}

			// S
			if (now == 0)
				next = 9999;
			else
				next = now - 1;

			if (check[next] != true)
			{
				q.push(next);
				check[next] = true;
				how[next] = 'S';
				from[next] = now;
			}

			// L
			next = (now%1000) * 10 + (now/1000);

			if (check[next] != true)
			{
				q.push(next);
				check[next] = true;
				how[next] = 'L';
				from[next] = now;
			}

			// R
			next = (now%10) * 1000 + (now/10);

			if (check[next] != true)
			{
				q.push(next);
				check[next] = true;
				how[next] = 'R';
				from[next] = now;
			}

		}//end while


		string result = "";
		
		int n = b;

		while (from[n] != -1)
		{
			result += how[n];
			n = from[n];
		}
		reverse(result.begin(), result.end());
		cout << result << endl;

	}//end while

	return 0;
}

