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
	list<char> L;

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		L.push_back(s[i]);
	}

	int t = 0;
	cin >> t;
	
	char x;
	auto iter = L.end();
	cout << "Ŀ��>>" << *iter << endl;

	while (t--)
	{
		cin >> x;
		
		switch(x)
		{
			//Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		case 'L':
			if(iter!=L.begin())
				iter--;
			cout << "Ŀ��>>" << *iter << endl;
			for (char c : L)//////////////
				cout << c;

			cout << endl;
			break;
			//Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
		case 'D':
			if (iter!=L.end())
				iter++;
			cout << "Ŀ��>>" << *iter << endl;
			for (char c : L)//////////////
				cout << c;
			cout << endl;
			break;
			//Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
		case 'B':
			if (iter != L.begin())
			{
				iter--; //����
				cout << "�����?>>" << *iter << endl;
				iter = L.erase(iter);
				cout << "iter>>" << *iter << endl;
			
				
			}	for (char c : L)//////////////
				cout << c;
			cout << endl;
			break;
		case 'P':
			cout << "������ Ŀ��>>" << *iter << endl;
			char plus;
			cin >> plus;
			iter = L.insert(iter, plus);
			iter++;
			cout << "������ Ŀ��>>" << *iter << endl;
			for (char c : L)//////////////
				cout << c;
			cout << endl;
			break;

		}
	}
	for (char c : L)//////////////
		cout << c;
	cout << endl;
	return 0;
}

