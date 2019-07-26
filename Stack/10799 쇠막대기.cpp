//10799
#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	string s;
	cin >> s;

	stack<int> S;
	int total = 0;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			S.push(i);
		else
		{
			if (S.top() == i - 1)	//laser
			{
				S.pop();
				total += S.size();
			}
			else
			{
				S.pop();
				total += 1;
			}

		}
	}
	cout << total;

	return 0;
}

