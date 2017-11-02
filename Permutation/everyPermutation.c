/* 문제 10974

N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.

입력

첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력

첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.

예제 입력 복사
3

예제 출력 복사
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX 8

int nextPermutation(int s[], int n)
{
	int i, j, temp;

	i = n - 1;

	while (s[i - 1] >= s[i] && i > 0)
		i = i - 1;

	if (i <= 0)
		return 0;

	j = n - 1;

	while (s[i - 1] >= s[j])
		j--;

	temp = s[i - 1];
	s[i - 1] = s[j];
	s[j] = temp;

	j = n - 1;

	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;

		i++;
		j--;
	}

	return 1;
}

int main(void)
{
	int n, i;
	int s[MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		s[i] = i + 1;
		printf("%d ", s[i]);
	}
	printf("\n");

	while (nextPermutation(s, n))
	{
		for (i = 0; i < n; i++)
			printf("%d ", s[i]);

		printf("\n");
	}

	return 0;
}