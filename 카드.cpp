#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main(){
	map<long long, int>ans;
	
	int fnum;
	cin >> fnum;
	int realans = 0;
	long long key = 0;
	while (fnum--)
	{
		long long a;
		cin >> a;
		if (ans.count(a)!=0)
		{
			ans[a]++;
		}
		else
		{
			ans.insert({ a,1 });
		}
		if (ans[a] > realans) {
			realans = ans[a];
			key = a;
		}
		else if (ans[a] == realans) {
			if (a < key)
				key = a;
		}

	}
	cout << key;
	

}