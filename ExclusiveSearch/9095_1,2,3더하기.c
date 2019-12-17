/*
문제 9095

정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.
1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력


첫쨰 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.


출력


각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.


예제 입력 복사
3
4
7
10


예제 출력 복사
7
44
274

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//재귀 9095번

int s[10] = { 1 };
int result = 0;

void sol(int n, int pre, int i)
{

	for (s[i] = 1; s[i] <= 3; s[i]++)
	{

		if (pre + s[i] == n)
			result++;


		if (i > 9)
			return;
		else
			sol(n, s[i] + pre, i + 1);
	}

}

int main(void)
{

	int time, n;

	// 10보다 작은 양의 정수 n이 주어졌을 때...
	// n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램
	scanf("%d", &time);

	while (time--)
	{
		scanf("%d", &n);

		result = 0;

		sol(n, 0, 0);

		printf("%d\n", result);

	}//end while

	return 0;
}