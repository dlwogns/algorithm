#include<iostream>
#include <stack>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int fnum;
	stack<pair<int, int>>s;
	int index = 0;
	cin >> fnum;
	while (fnum--)
	{
		int a;
		cin >> a;
		if (s.empty())
		{
			index++;
			s.push({ index, a });
			cout << "0 ";
			continue;
		}
		else
		{
			if (a < s.top().second)
			{
				cout << s.top().first << " ";
				index++;
				s.push({ index,a });
				continue;
			}
			else
			{
				while (true)
				{
					s.pop();
					if (s.empty()) {
						cout << "0 ";
						index++;
						s.push({ index,a });
						break;
					}
					if (a < s.top().second) {
						cout << s.top().first << " ";
						index++;
						s.push({ index,a });
						break;
					}
					else
						continue;
				}
			}
		}
	}
}