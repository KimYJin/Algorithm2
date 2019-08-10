/*
���� 1963

�Ҽ��� �������� �����ϴ� â���̴� ���� ���̵� ��й�ȣ�� 4�ڸ� ���Ҽ����� ���س��Ҵ�. 
��� �� â���̴� ģ�� ģ���� ��ȭ�� �������µ�:
-������ ���� ��� �ٲ� ���� ���ݾơ�
-���� ������ 1033���� �س��µ�... ���� �Ҽ��� �������� ���� ������̾�"
-���׷� 8179�� �ء�
-����... ���� �� �غ���. �� ������ �� �̻��ؼ� ��й�ȣ�� �� ���� �� �ڸ� �ۿ� �� �ٲ۴� ���̾�. 
  ���� ��� ���� ù �ڸ��� �ٲٸ� 8033�� �Ǵϱ� �Ҽ��� �ƴ��ݾ�. ���� �ܰ踦 ���ľ� ���� �� ���� �� ������... 
  ���� ���... 1033 1733 3733 3739 3779 8779 8179ó�� ���̾�.��
-����...���� �Ҽ��� ���Ʊ�. �׷� �ƿ� ���α׷��� ¥�� �׷�. 
  �� �ڸ� �Ҽ� �� ���� �Է¹޾Ƽ� �ٲٴµ� �� �ܰ質 �ʿ����� ����ϰ� ����.��
-�������ơ�

�׷���. �׷��� �������� �� ������ Ǯ�� �Ǿ���. �Է��� �׻� �� �ڸ� �Ҽ���(1000 �̻�) �־����ٰ� ��������. 
�־��� �� �Ҽ� A���� B�� �ٲٴ� ���������� �׻� �� �ڸ� �Ҽ����� �����ؾ� �ϰ�, 
���� �ڸ� ������ �Ͽ��� ������ 0039 �� ���� 1000 �̸��� ��й�ȣ�� ������ �ʴ´�.

�Է�
ù �ٿ� test case�� �� T�� �־�����. ���� T�ٿ� ���� �� �ٿ� 1�־� �� �ڸ� �Ҽ��� �־�����.

���
�� test case�� ���� �� �Ҽ� ������ ��ȯ�� �ʿ��� �ּ� ȸ���� ����Ѵ�. �Ұ����� ��� Impossible�� ����Ѵ�.

���� �Է� ����
3
1033 8179
1373 8017
1033 1033

���� ��� ����
6
7
0
*/


#include<iostream>
#include<queue>
#include <cstring> 
#include <string>  //c++11 to_string ����� ����.

using namespace std;

const int MAX = 10000;

bool prime[MAX+1]; //�ʱⰪ = false
bool check[MAX+1]; 
int dis[MAX + 1];


int change(int num, int index, int digit)
{
	if (index == 0 && digit == 0)
		return -1;

	string str = to_string(num); //c++11 ���� to_string�� ����� ���ڿ��� ��ȯ.

	str[index] = digit+'0';

	return stoi(str);
}

int main(void)
{
	int T,s,d;	// time, source, destination

	// prime number
	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i] == false)
		{
			for (int j = i*i; j <= MAX; j = j + i)
				prime[j] = true;
		}
	}

	for (int i = 0; i <= MAX; i++)
	{
		prime[i] = !prime[i];

	}

	cin >> T;

	while (T--)
	{
		cin >> s >> d;

		memset(check, false, sizeof(check));
		memset(dis, 0, sizeof(dis));

		check[s] = true;
		dis[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty()) {

			int now = q.front();
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int next = change(now, i, j);
					
					if (next != -1)
					{
						if (prime[next] == true && check[next]==false)
						{
							q.push(next);
							dis[next] = dis[now]+1;
							check[next] = true;
						}
					}

				}

			}
			if (check[d] == true)
				break;

		}//end while

		cout << dis[d]<<endl;
	}//end while

	for (;;);
	//return 0;
}