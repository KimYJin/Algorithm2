/*
문제 10971

외판원 순회 문제는 영어로 Traveling Salesman problem (TSP) 라고 불리는 문제로 computer science 분야에서 가장 중요하게 취급되는 문제 중 하나이다. 
여러 가지 변종 문제가 있으나, 여기서는 가장 일반적인 형태의 문제를 살펴보자.
1번부터 N번까지 번호가 매겨져 있는 도시들이 있고, 도시들 사이에는 길이 있다. (길이 없을 수도 있다) 
이제 한 외판원이 어느 한 도시에서 출발해 N개의 도시를 모두 거쳐 다시 원래의 도시로 돌아오는 순회 여행 경로를 계획하려고 한다. 
단, 한번 갔던 도시로는 다시 갈 수 없다. (맨 마지막에 여행을 출발했던 도시로 돌아오는 것은 예외) 
이런 여행 경로는 여러 가지가 있을 수 있는데, 가장 적은 비용을 들이는 여행 계획을 세우고자 한다.
각 도시간에 이동하는데 드는 비용은 행렬 W[i][j]형태로 주어진다. W[i][j]는 도시 i에서 도시 j로 가기 위한 비용을 나타낸다. 
비용은 대칭적이지 않다. 즉, W[i][j] 는 W[j][i]와 다를 수 있다. 모든 도시간의 비용은 양의 정수이다. W[i][i]는 항상 0이다.
경우에 따라서 도시 i에서 도시 j로 갈 수 없는 경우도 있으며 이럴 경우 W[i][j]=0이라고 하자.
N과 비용 행렬이 주어졌을 때, 가장 적은 비용을 들이는 외판원의 순회 여행 경로를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 도시의 수 N이 주어진다. (2<=N<=10) 다음 N개의 줄에는 비용 행렬이 주어진다. 
각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다. W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.
항상 순회할 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 외판원의 순회에 필요한 최소 비용을 출력한다.

예제 입력 복사
4
0 10 15 20
5  0  9 10
6 13  0 12
8  8  9  0

예제 출력 복사
35

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX 10
#define false 0
#define true 1

int c[MAX] = { 0 };

int nextPermutation(int begin, int n)
{
	int i, j, temp;

	i = n - 1;
	while (c[i - 1] >= c[i] && i > begin)  //// reduce time complexity. O(N*N!)-> O(N!)
	{
		i--;
	}

	if (i <= begin)  //// reduce time complexity. O(N*N!)-> O(N!)
		return 0;

	j = n - 1;
	while (c[i - 1] >= c[j])
	{
		j--;
	}

	temp = c[i - 1];
	c[i - 1] = c[j];
	c[j] = temp;

	j = n - 1;
	while (i < j)
	{
		temp = c[i];
		c[i] = c[j];
		c[j] = temp;

		i++;
		j--;
	}
	return 1;
}

int main(void)
{
	int n, i,j,min, sum,ok;
	int w[MAX][MAX];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &w[i][j]);
		}
	}

	for (i = 0; i < n; i++)
	{
		c[i] = i;
	}

	min = 9999990;
	
	do {
		sum = 0;
		ok = true;

		for (i = 0; i < n - 1; i++)
		{
			if (w[c[i]][c[i + 1]] == 0)
			{
				ok = false;
				break;
			}
			else
				sum += w[c[i]][c[i + 1]];
		}

		//go back to the source.
		if (ok && w[c[n - 1]][c[0]] != 0)
		{
			sum += w[c[n - 1]][c[0]];

			if (min > sum)
				min = sum;
		}

	} while (nextPermutation(1, n));   //// reduce time complexity. O(N*N!)-> O(N!)

	printf("%d", min);

	return 0;

}