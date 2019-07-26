//10799
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>
#include<list>

using namespace std;

int main()
{
	string s;
	cin >> s;
	char time[26] = { 0 };

	for (char c:s)
	{
		int index = c - 'a';
		
		time[index]++;
	}
	for (int i : time)
	{
		cout << i << ' ';
	}

	return 0;
}

