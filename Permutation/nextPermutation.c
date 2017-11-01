/*
���� 10972
1���� N������ ���� �̷���� ������ �ִ�. �� ��, ���������� ������ ���� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX 10000

int nextPermutation(int s[], int n)
{
	int i, j,temp;
	
	i= n - 1;

	while (s[i - 1] >= s[i] && i > 0)
		i = i - 1;

	if (i <= 0)
		return 0;

	j = n - 1;

	while (s[i - 1] >= s[j])
		j--;

	temp = s[i - 1];
	s[i - 1] = s[j]; 
	s[j]=temp;

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


	if (nextPermutation(s, n))
	{
		for (i = 0; i < n; i++)
			printf("%d ", s[i]);
	}
	else
		printf("-1");

	return 0;
}