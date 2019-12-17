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
왼쪽과 오른쪽으로 창문을 열었을 때, 양쪽 모두 거리 2 이상의 공간이 확보될 때 조망권이 확보된다고 말한다.
빌딩들에 대한 정보가 주어질 때, 조망권이 확보된 세대의 수를 반환하는 프로그램을 작성하시오.
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

