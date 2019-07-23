#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		string str;
		cin >> str;

		stack <char>S;
	
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
			{
				S.push('(');
			}
			else
			{
				if (!S.empty() && S.top() == '(')
				{
					S.pop();
				}
				else
				{
					S.push(')');
				}
			}
	
		}//end for

		if (S.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

