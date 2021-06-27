#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	stack<int>s;
	vector<int>v;
	
	int fnum;
	cin >> fnum;
	while (fnum--)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	vector<int>a(v.size(), -1);
	for (size_t i = 0; i < v.size(); i++)
	{
		while (!s.empty() && v[s.top()] < v[i])
		{
			a[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}
	for (auto e : a)
		cout << e << ' ';

	
	

}