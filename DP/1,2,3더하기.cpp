//���� ���� 9095 1,2,3���ϱ� https://www.acmicpc.net/problem/9095
#include <iostream>
using namespace std;
const int MAX = 10;
int dp[MAX + 1] = { 0, };

int main(void) {
	int n,T;
	cin >> T;
	
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = dp[0] + dp[1];

	for (int i = 3; i <= MAX; i++)
	{
		//dp[i-a] �� a������ ���� ����� ��
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	while (T--)
	{
		cin >> n;

		cout << dp[n] <<endl;
	}
	
	return 0;
}
