//10799
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>
#include<algorithm>

using namespace std;

/*
���ʰ� ���������� â���� ������ ��, ���� ��� �Ÿ� 2 �̻��� ������ Ȯ���� �� �������� Ȯ���ȴٰ� ���Ѵ�.
�����鿡 ���� ������ �־��� ��, �������� Ȯ���� ������ ���� ��ȯ�ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/
int main()
{
	int b[1000] = { 0 };
	int l1, l2, r1, r2, m,total=0;

	for(int t=1; t<=10; t++)
	{
		int total = 0;
		int num = 0;
		cin >> num;

		for (int i = 0; i < num; i++)
		{
			cin >> b[i];
		}
		
		for (int i = 2; i < num - 2; i++)
		{
			l1 = b[i] - b[i - 1];
			l2 = b[i] - b[i - 2];
			r1 = b[i] - b[i + 1];
			r2 = b[i] - b[i + 2];

			m = min({ l1,l2,r1,r2 });

			if (m > 0)
			{
				total += m;
			}
		}//end for
		cout << "#"<<t<<" "<< total << endl;
	}
	
	return 0;
}

