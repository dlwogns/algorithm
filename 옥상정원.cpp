#include <iostream>
#include <stack>
using namespace std;
int main() {

	int fnum;
	cin >> fnum;
	stack<int>top;
	long long int ans=0;
	while (fnum--)
	{
		int a;
		cin >> a;
		if (top.empty()) {
			top.push(a);
		}
		if (a > top.top()) {
			while (!top.empty()&&a >= top.top() )
			{
				top.pop();
			}
			ans += top.size();
			top.push(a);
		}
		else if(a<top.top()) {
			ans += top.size();
			top.push(a);
		}
		else if (a == top.top()) {
			ans += top.size() - 1;
		}
	}
	cout << ans;

}