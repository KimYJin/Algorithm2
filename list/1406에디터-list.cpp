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
	cout << "커서>>" << *iter << endl;

	while (t--)
	{
		cin >> x;
		
		switch(x)
		{
			//커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
		case 'L':
			if(iter!=L.begin())
				iter--;
			cout << "커서>>" << *iter << endl;
			for (char c : L)//////////////
				cout << c;

			cout << endl;
			break;
			//커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
		case 'D':
			if (iter!=L.end())
				iter++;
			cout << "커서>>" << *iter << endl;
			for (char c : L)//////////////
				cout << c;
			cout << endl;
			break;
			//커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
		case 'B':
			if (iter != L.begin())
			{
				iter--; //순서
				cout << "지운것?>>" << *iter << endl;
				iter = L.erase(iter);
				cout << "iter>>" << *iter << endl;
			
				
			}	for (char c : L)//////////////
				cout << c;
			cout << endl;
			break;
		case 'P':
			cout << "삽입전 커서>>" << *iter << endl;
			char plus;
			cin >> plus;
			iter = L.insert(iter, plus);
			iter++;
			cout << "삽입후 커서>>" << *iter << endl;
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

