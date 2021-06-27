#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
	int fnum;
	cin >> fnum;
	while (fnum--)
	{
		string fun;
		cin >> fun;
		deque<int>num;
		bool check = true;
		int f;
		cin >> f;
		while (f--)
		{
			int inum;
			cin >> inum;
			if (!cin) {
				cin.clear();
				cin.ignore();
				f++;
			}
			else
				num.push_back(inum);
		}
		for (auto e : fun) {
			if (e == 'D') {
				if (num.empty()) {
					check = false;
					break;
				}
				else
					num.pop_front();
			}
			else if (e == 'R') {
				int temp;
				for (size_t i = 0; i < num.size() / 2; i++)
				{
					temp = num[i];
					num[i] = num[num.size() - 1 - i];
					num[num.size() - 1 - i] = temp;

				}
			}
		
		}
		if (check)
		{
			cout << "[";
			for (size_t i = 0; i < num.size(); i++)
			{
				if (i == num.size() - 1)
					cout << num[i] << "]\n";
				else
					cout << num[i] << ",";
			}
		}
		else
		{
			cout << "error\n";
		}
	}
	
	
}
