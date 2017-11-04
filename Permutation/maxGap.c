/*
문제 10819

N개의 정수로 이루어진 배열 A가 주어진다. 이 때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최대값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

예제 입력 복사
6
20 1 15 8 4 10

예제 출력 복사
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