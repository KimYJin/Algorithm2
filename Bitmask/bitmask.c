/*
문제


비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
//add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
//remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
//check x : S에 x가 있으면 1을, 없으면 0을 출력한다.
//toggle x : S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
//all : S를{ 1, 2, ..., 20 } 으로 바꾼다.
//empty : S를 공집합으로 바꾼다.


입력


첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.


출력

check 연산이 주어질때마다, 결과를 출력한다.


예제 입력
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1


예제 출력
1
1
0
1
0
1
0
1
0
1
1
0
0
0
1
0

------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
//remove x : S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
//check x : S에 x가 있으면 1을, 없으면 0을 출력한다.
//toggle x : S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
//all : S를{ 1, 2, ..., 20 } 으로 바꾼다.
//empty : S를 공집합으로 바꾼다.

int main(void)
{
	int m, n;
	int s = 0;	// 공집합 S
	char act[10] = "";


	scanf("%d", &m);	// 수행할 연산의 수

	while (m--)
	{
		scanf("%s", act);

		if (!strcmp(act, "add"))
		{
			scanf("%d", &n);
			n = n - 1;
			s = s | (1 << n);
		}
		else if (!strcmp(act, "remove"))
		{
			scanf("%d", &n);
			n = n - 1;
			s = s & ~(1 << n);
		}
		else if (!strcmp(act, "check"))
		{
			scanf("%d", &n);
			n = n - 1;

			int res = s& (1 << n);

			if (res)	///
				printf("1\n");
			else
				printf("0\n");
		}
		else if (!strcmp(act, "toggle"))
		{
			scanf("%d", &n);
			n = n - 1;

			s = s ^ (1 << n);
		}
		else if (!strcmp(act, "all"))
		{
			s = ((1 << 20) - 1); //코드 수정.1-19(x)1-20 (-1을 하면 맨 앞자리 없어짐) 
		}
		else if (!strcmp(act, "empty"))
		{
			s = 0;
		}
	}


	for (;;);
}