#include <iostream>
using namespace std;

int arr[1000000];

int main() {
	for (size_t i = 1; i < 10001; i++)
	{
		int cnum = i;
		int a = 0;
		while (cnum!=0)
		{
			a += cnum % 10;
			cnum = cnum / 10;
		}
		arr[i + a]++;
	}

	for (size_t i = 1; i < 10001; i++)
	{
		if (arr[i] == 0) {
			cout << i << '\n';
		}
	}


}
