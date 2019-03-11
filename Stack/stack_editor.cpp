#define _CRT_SECURE_NO_WARNINGS

/*
���� 1406 - ������

�� �ٷ� �� ������ �����͸� �����Ϸ��� �Ѵ�. �� ������� ���� �ҹ��ڸ���  �ִ� 600,000���ڱ��� �Է��� �� �ִ�.
�� �����⿡�� 'Ŀ��'��� ���� �ִµ�, Ŀ���� ������ �� ��(ù ��° ������ ����), 
������ �� ��(������ ������ ������), �Ǵ� ���� �߰� ������ ��(��� ���ӵ� �� ���� ����)�� ��ġ�� �� �ִ�. 
�� ���̰� L�� ���ڿ��� ���� �����⿡ �ԷµǾ� ������, Ŀ���� ��ġ�� �� �ִ� ���� L+1���� ��찡 �ִ�.

�� �����Ⱑ �����ϴ� ��ɾ�� ������ ����.

L
Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
D
Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
B
Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
������ ���� Ŀ���� �� ĭ �������� �̵��� ��ó�� ��Ÿ������, ������ Ŀ���� �����ʿ� �ִ� ���ڴ� �״����
P $
$��� ���ڸ� Ŀ�� ���ʿ� �߰���

�ʱ⿡ �����⿡ �ԷµǾ� �ִ� ���ڿ��� �־�����, �� ���� �Է��� ��ɾ ���ʷ� �־����� ��, 
��� ��ɾ �����ϰ� �� �� �����⿡ �ԷµǾ� �ִ� ���ڿ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
��, ��ɾ ����Ǳ� ���� Ŀ���� ������ �� �ڿ� ��ġ�ϰ� �ִٰ� �Ѵ�.

*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string result(string s, int n);

int main(void)
{
	string s;
	int n;

	cin >> s;
	cin >> n;
	cout << result(s, n);

	for (;;);
	return 0;
}

string result(string s, int n) {
	stack<char> left, right;
	char command, temp;
	string output;
	int len = s.size();

	for (int i = 0; i < len; i++)
	{
		left.push(s[i]);
	}

	while (n--)
	{
		cin >> command;

		switch (command)
		{
		case 'L':
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;

		case 'D':
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;

		case 'B':
			if (!left.empty())
			{
				left.pop();
			}
			break;

		case 'P':
			cin >> temp;
			left.push(temp);
			break;

		}
	}

	//left stack -> right stack���� ���� �ű��
	while (!left.empty())
	{
		temp = left.top();
		right.push(temp);
		left.pop();
	}

	//stack -> string
	while (!right.empty())
	{
		cout << right.top();
		right.pop();
	}

	return output;
}