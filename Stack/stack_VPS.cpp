/*���� 9012 - ��ȣ
��ȣ ���ڿ�(Parenthesis String, PS)�� �� ���� ��ȣ ��ȣ�� ��(�� �� ��)�� ������ �����Ǿ� �ִ� ���ڿ��̴�. 
�� �߿��� ��ȣ�� ����� �ٸ��� ������ ���ڿ��� �ùٸ� ��ȣ ���ڿ�(Valid PS, VPS)�̶�� �θ���. 
�� ���� ��ȣ ��ȣ�� �� ��( )�� ���ڿ��� �⺻ VPS �̶�� �θ���. ���� x �� VPS ��� 
�̰��� �ϳ��� ��ȣ�� ���� ���ο� ���ڿ� ��(x)���� VPS �� �ȴ�. 
�׸��� �� VPS x �� y�� ����(concatenation)��Ų ���ο� ���ڿ� xy�� VPS �� �ȴ�. 
���� ��� ��(())()���� ��((()))�� �� VPS ������ ��(()(��, ��(())()))�� , �׸��� ��(()�� �� ��� VPS �� �ƴ� ���ڿ��̴�.

�������� �Է����� �־��� ��ȣ ���ڿ��� VPS ���� �ƴ����� �Ǵ��ؼ� �� ����� YES �� NO �� ��Ÿ����� �Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(void)
{
	int n;
	stack<char> vps;
	bool result;
	string s;

	cin >> n;

	while (n--)
	{
		cin >> s;
		result = true;

		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] == '(')
				vps.push(s[i]);
			else
			{
				if (!vps.empty())
					vps.pop();
				else
				{
					result = false;
					break;
				}
			}
		}
		if (!vps.empty() || result == false)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;

		while (!vps.empty())
			vps.pop();
	}

	for (;;);
	return 0;
}