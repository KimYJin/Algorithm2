/*
���� 10819

N���� ������ �̷���� �迭 A�� �־�����. �� ��, �迭�� ����ִ� ������ ������ ������ �ٲ㼭 ���� ���� �ִ밪�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

�Է�
ù° �ٿ� N (3 �� N �� 8)�� �־�����. ��° �ٿ��� �迭 A�� ����ִ� ������ �־�����. �迭�� ����ִ� ������ -100���� ũ�ų� ����, 100���� �۰ų� ����.

���
ù° �ٿ� �迭�� ����ִ� ���� ������ ������ �ٲ㼭 ���� �� �ִ� ���� �ִ��� ����Ѵ�.

���� �Է� ����
6
20 1 15 8 4 10

���� ��� ����
62
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#define MAX 8

int nextPermutation(int a[], int n)
{
	int i, j,temp;

	i = n - 1;
	while (a[i - 1] >= a[i] && i > 0)
	{
		i--;
	}

	if (i <= 0)
		return 0;

	j = n - 1;
	while (a[i-1] >= a[j] )
	{
		j--;
	}

	temp = a[i-1];
	a[i-1] = a[j];
	a[j] = temp;

	j = n - 1;
	while (i < j)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;

		i++;
		j--;
	}
	return 1;
}

int cal(int a[], int n)
{
	int i, result=0;

	for (i = 1; i < n; i++)
	{
		result += abs(a[i] - a[i-1]);
	}

	return result;
}

int main(void)
{
	int n, a[MAX];
	int i, j, min=0,temp,result=0;

	scanf("%d", &n);
	
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	//selection sort in axcending order
	for (i = 0; i < n-1; i++)
	{
		min = i;

		for (j = i+1; j < n; j++)
		{
			if (a[min] > a[j])
			{
				min = j;
			}
		}
		
		//swap
		temp = a[min];
		a[min] = a[i];
		a[i] = temp;

	}

	result = cal(a, n);

	while (nextPermutation(a, n))
	{		
		if(result < cal(a,n))
			result = cal(a, n);
	}

	printf("%d", result);
	
	return 0;

}