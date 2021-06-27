#include <iostream>
#include <algorithm>
using namespace std;
int arr[1002];
int ans[1002];
int main() {
	
	for (size_t i = 0; i < 1002; i++)
	{
		ans[i] = 1;
	}
	int fnum;
	cin >> fnum;
	for (size_t i = 0; i < fnum; i++)
	{
		cin >> arr[i];
	}
	ans[0] = 1;
	for (size_t i = 1; i < fnum; i++)
	{
		
		for (size_t j = 0; j < i; j++)
		{
			if (arr[j] < arr[i]) ans[i] = max(ans[i], ans[j] + 1);
		}
	}
	cout << *max_element(ans,ans+fnum);
	
	


}