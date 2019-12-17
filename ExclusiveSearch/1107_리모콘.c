/*
다해보기
문제: 1107 <리모콘>

수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼을 망가뜨렸다.

리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.

수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 망가져있는지 주어졌을 때, N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오.

수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 망가진 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 셋째 줄에는 망가진 버튼이 주어지며, 같은 버튼이 중복되서 주어지는 경우는 없다.

출력
첫째 줄에 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다.

예제 입력 복사
5457
3
6 7 8

예제 출력 복사
6

예제 입력 2 복사

100
5
0 1 2 3 4

예제 출력 2 복사
0

예제 입력 3 복사
500000
8
0 2 3 4 6 7 8 9

예제 출력 3 복사
11117

*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define false 0
#define true 1

//타겟채널로 숫자버튼을 눌러 이동가능하면 그 길이를 return,
//타겟채널의 숫자 중 고장난 버튼이 있어 이동할 수 없다면 0을 return
int possible(int broken[], int ch)
{
	int len = 0;

	if (ch == 0)
		return broken[ch] ? 0 : 1;

	while (ch > 0)
	{
		if (broken[ch % 10] == 1)
			return 0;

		len++;
		ch /= 10;
	}
	return len;
}


int main(void)
{
	int broken[10] = { false }; //button 0~9
	int ch; // target channel
	int num_broken; //the number of broken buttons
	int up_down, numeric_keypad;
	int temp, button;	


	scanf("%d", &ch);
	scanf("%d", &num_broken);
	
	while (num_broken--)
	{
		scanf("%d", &temp);
		broken[temp] = true;
	}

	// 1. 초기값을 100에서 +또는 -로만 이동하는 횟수로 지정.
	button = (ch > 100) ? (ch - 100) : (100 - ch);

	// 2. 숫자버튼과 +또는 -를 이용한 버튼 이동 수.
	// 채널이 0번~50만 이므로 50만번 채널까지 이동하려면
	// 0에서 50만번 +를 하는 것과 100만에서 50만번 - 한 것과 같으므로
	// for문의 i를 0부터 50만이 아닌 100만까지 돌려준다.

	for (int i = 0; i < 1000000; i++)
	{
		//숫자버튼만으로 이동가능하면 그 길이를 구하고,없다면 0
		numeric_keypad = possible(broken, i);	

		if (numeric_keypad > 0)
		{
			//숫자 버튼 누른 후, 타켓채널로 가기 위해 +또는 - 를 눌러야 하는 횟수
			up_down = (ch > i) ? (ch - i) : (i - ch);

			if (up_down + numeric_keypad < button)
				button = up_down + numeric_keypad;
		}
	}

	printf("%d", button);

	return 0;
}