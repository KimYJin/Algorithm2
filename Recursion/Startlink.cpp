/*
���� 9095

���� 4�� 1, 2, 3�� �������� ��Ÿ���� ����� �� 7������ �ִ�.
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

���� n�� �־����� ��, n�� 1,2,3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 11���� �۴�.

���
�� �׽�Ʈ ���̽�����, n�� 1,2,3�� ������ ��Ÿ���� ����� ���� ����Ѵ�.


���� �Է� ����
3
4
7
10


���� ��� ����
7
44
274

*/

#include<iostream>

using namespace std;

int ans = 0;

void go(int count, int sum, int goal)
{
	if (count > 10)
		return;
	if (sum > goal)
		return;

	if (sum == goal)
	{
		ans++; return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (sum  < goal)
			go(count+1,sum + i, goal);

	}
}

int main(void)
{
	int t,n;

	cin >> t;

	while (t--)
	{
		ans = 0;

		cin >> n;

		go(0,0, n);

		cout << ans << endl;
	}
}