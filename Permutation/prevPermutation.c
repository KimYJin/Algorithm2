/*
문제 10973


1부터 N까지의 수로 이루어진 순열이 있다. 이 때, 사전순으로 이전에 오는 순열을 구하는 프로그램을 작성하시오.

사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.


입력

첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.


출력

둘째 줄에 입력으로 주어진 순열의 이전에 오는 순열을 출력한다. 만약, 사전순으로 처음에 오는 순열인 경우에는 -1을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX 10000

int prevPermutation(int s[], int n)
{
	int i, j, temp;

	i = n - 1;

	while (s[i - 1] <= s[i] && i > 0)
		i = i - 1;

	//if there is no prev premutation.
	if (i <= 0)
		return 0;

	j = n - 1;

	while (s[i - 1] <= s[j])
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
		scanf("%d", &s[i]);


	if (prevPermutation(s, n))
	{
		for (i = 0; i < n; i++)
			printf("%d ", s[i]);
	}
	else
		printf("-1");

	return 0;
}