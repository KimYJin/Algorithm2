/*
���� 15953 - �������
*/
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
using namespace std;

void result(int, int );

//�������� ���ߴٸ� a = 0
//�ڿ� ä������ ���� ���� 0���� �ʱ�ȭ�ȴ�.
int prize1[101] = { 0,500,300,300,200,200,200,50,50,50,50,30,30,30,30,30,10,10,10,10,10,10 };
int prize2[65] = { 0,512,256,256,128,128,128,128,64,64,64,64,64,64,64,64,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32 };

int main(void)
{
	int T=0, a=0, b=0;

	cin >> T;
	
	while (T--)
	{
		cin >> a;
		cin >> b;

		result(a, b);
	}

	for (;;);	return 0;
}

void result(int a, int b) {

	int total = 0;

	//if (a <= 21 && a >= 0)
	total = total + prize1[a];
	
	//if (b <= 31 && b >= 0)
	total = total + prize2[b];

	total = total * 10000;

	cout << total << endl;
}