/*
����


����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
//remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
//check x : S�� x�� ������ 1��, ������ 0�� ����Ѵ�.
//toggle x : S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
//all : S��{ 1, 2, ..., 20 } ���� �ٲ۴�.
//empty : S�� ���������� �ٲ۴�.


�Է�


ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.


���

check ������ �־���������, ����� ����Ѵ�.


���� �Է�
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


���� ���
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

//add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
//remove x : S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
//check x : S�� x�� ������ 1��, ������ 0�� ����Ѵ�.
//toggle x : S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
//all : S��{ 1, 2, ..., 20 } ���� �ٲ۴�.
//empty : S�� ���������� �ٲ۴�.

int main(void)
{
	int m, n;
	int s = 0;	// ������ S
	char act[10] = "";


	scanf("%d", &m);	// ������ ������ ��

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
			s = ((1 << 20) - 1); //�ڵ� ����.1-19(x)1-20 (-1�� �ϸ� �� ���ڸ� ������) 
		}
		else if (!strcmp(act, "empty"))
		{
			s = 0;
		}
	}


	for (;;);
}